import os
import re
import logging
from Utils.main_class import *
from Utils.utils import extract_function
from convertor import SpecificationConvertor
from specification_verify import SpecVerifier
from config import *
from llm import *
from pre_cond_manager import PreconditionsManager

class SpecGenerator:

    config: MainConfig

    function_info: FunctionInfo
    function_info_list: list[FunctionInfo]
    annotated_c_file_path: str
    annotated_loop_c_file_path: str
    generated_loop_c_file_path: str
    output_path: str
    global_type_info_dict: dict
    debug: bool
    logger: logging.Logger

    llm: Chatbot


    def __init__(self,function_info: FunctionInfo, function_info_list: list[FunctionInfo], global_type_info_dict: dict,config: MainConfig,logger: logging.Logger,llm_config:LLMConfig,precond_manager: PreconditionsManager):
        self.function_info = function_info
        self.function_info_list = function_info_list
        self.annotated_c_file_path = config.annotated_c_file_path
        self.annotated_loop_c_file_path = config.annotated_loop_c_file_path
        self.generated_loop_c_file_path = config.generated_loop_c_file_path
        self.output_path = config.output_path
        self.global_type_info_dict = global_type_info_dict
        self.debug = config.debug
        self.config = config
        self.logger = logger
        self.precond_manager = precond_manager
        self.ignore_list = ['main','test','bar','foo']

        self.llm = Chatbot(llm_config)

    def if_assigns(self) -> bool:

        for parameter in self.function_info.parameter_list:
            if parameter.is_ptr and parameter.is_struct:
                return True
        return False


    def create_precondition(self) -> str:
        """
        Generate precondition to be inserted into temporary .c file
        """
        with_list = []
        require_list = []
        syntax_str = ''
        value_str = ''
        def parse_parameters_assertion(parameter_list:[List[Parameter]], with_list:list[str], require_list:list[str], syntax_str:str, value_str:str):
            if not parameter_list:
                return '', f'Require emp\n'
            
            for parameter in parameter_list:
                
                # Pointer, non-struct, non-array parameter

                if parameter.is_recursive:
                    self.logger.info(f'parameter.name:{parameter.name} is recursive')
                    continue
                
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    
                    with_list.append(f'{value_str}{parameter.name}_v')
                    if syntax_str != '' and value_str != '':
                        with_list.append(f'{value_str}{parameter.name}')
                    access = '*' * parameter.ptr_depth
                    require_list.append(
                                        f'{access}({syntax_str}{parameter.name}) == {value_str}{parameter.name}_v')
                    
                    if syntax_str != '' and value_str != '':
                        require_list.append(
                                            f'({syntax_str}{parameter.name}) == {value_str}{parameter.name}')
                    continue
        

                # Pointer, struct, non-array parameter

                if parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                
                    
                    old_syntax_str = syntax_str
                    old_value_str = value_str
                    
                    
                    if parameter.ptr_depth == 1:
                        access_name = parameter.name
                    else:
                        access = '*' * (parameter.ptr_depth - 1)
                        access_name =f'({access}{parameter.name})'

                    syntax_str = syntax_str + access_name + '->'
                    value_str = value_str + access_name + '_'

                    # Recursively process parameter list of struct
                    parse_parameters_assertion(parameter.type.parameter_list, with_list, require_list, syntax_str, value_str)

                    syntax_str =  old_syntax_str
                    value_str = old_value_str
                    
                    continue

                # Pointer, non-struct, array parameter

                if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    
                    # Add array symbol, address, and length separately
                    if parameter.array_length == 'INT_MAX':

                        next_parameter = parameter_list[parameter_list.index(parameter) + 1]

                        with_list.append(f'{value_str}{parameter.name}_l')
                        require_list.append (f'store_int_array({syntax_str}{parameter.name}, {next_parameter.name}, {value_str}{parameter.name}_l)'
                                            )
                    
                        require_list.append(f'{next_parameter.name} > 0 && {next_parameter.name} < 100')
                        
                    else:
                        with_list.append(f'{value_str}{parameter.name}_l')
                        require_list.append(f'store_int_array({syntax_str}{parameter.name},{value_str}{parameter.array_length}, {value_str}{parameter.name}_l)')
                    
                    
                    # for i in range(parameter.array_length):
                    #         with_list.append(f'{value_str}{parameter.name}_i')
                    #         require_list.append(f'a_l[{i}] == {value_str}{parameter.name}_i')
                        

                    continue

                # Pointer, struct, array parameter
                if parameter.is_ptr and  parameter.is_struct and parameter.array_length != -1:
                    raise ValueError(f'Currently cannot handle pointer struct array parameter: {syntax_str}{parameter.name}')
                

               

                # Non-pointer, struct, non-array parameter

                if not parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:

                    old_syntax_str = syntax_str
                    old_value_str = value_str
                    
                    syntax_str = syntax_str + parameter.name + '.'
                    value_str = value_str + parameter.name + '_'
                    # Recursively process parameter list of struct
                    parse_parameters_assertion(parameter.type.parameter_list, with_list, require_list, syntax_str, value_str)
                    syntax_str =  old_syntax_str
                    value_str = old_value_str
                    continue

                # Currently only supports intType arrays by default
                # Non-pointer, non-struct, array parameter
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    
                    if parameter.array_length == 'INT_MAX':

                        next_parameter = parameter_list[parameter_list.index(parameter) + 1]

                        with_list.append(f'{value_str}{parameter.name}_l')
                        require_list.append (f'store_int_array({syntax_str}{parameter.name}, {next_parameter.name}, {value_str}{parameter.name}_l)'
                                            )
                        require_list.append(f'{next_parameter.name} > 0 && {next_parameter.name} < 100')
                        
                    else:
                        with_list.append(f'{value_str}{parameter.name}_l')
                        require_list.append(f'store_int_array({syntax_str}{parameter.name},{parameter.array_length}, {value_str}{parameter.name}_l)')

                        # for i in range(parameter.array_length):
                        #     with_list.append(f'{value_str}{parameter.name}_{i}')
                        #     require_list.append(f'{value_str}{parameter.name}_l[{i}] == {value_str}{parameter.name}_{i}')

                    continue

                # Non-pointer, struct, array parameter
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    raise ValueError(f'Currently cannot handle non-pointer struct array parameter: {syntax_str}{parameter.name}')

                # Non-pointer, non-struct, non-array parameter
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    if syntax_str != '' and value_str != '':
                        with_list.append(f'{value_str}{parameter.name}')
                        require_list.append(f'{syntax_str}{parameter.name} == {value_str}{parameter.name}')
                    continue

                else:
                    raise ValueError(f'Encountered unexpected data type: {syntax_str}{parameter.name}')

            if with_list != []:
                with_str = 'With ' + ' '.join(with_list)
            else: 
                with_str = ''
            
            if require_list != []:
                require_str = 'Require ' + ' && '.join(require_list)
            else:
                require_str = 'Require emp'

            
            return with_str, require_str
        
        with_str, require_str = parse_parameters_assertion(self.function_info.parameter_list, with_list, require_list, syntax_str, value_str) 
        
        if self.function_info.func_type == 'void':
            ensure_str = 'Ensure emp'
        else:
            ensure_str = 'Ensure Results(__return)'

        return f'/*@\n{with_str}\n{require_str}\n{ensure_str}\n*/'

    def create_required_type(self):
        """
        Generate typedef and non-typedef structs to be inserted into temporary .c file
        """
        required_type_list = []
        for type_info in self.global_type_info_dict.values():
            required_type_list.append(type_info)
        required_type = '\n'.join(required_type_list)
        return required_type
    
    
    def create_generated_c_file(self):

        # Create required type definitions
        required_type = self.create_required_type()
        
        require_str = self.function_info.require
        
        # Create specifications for called functions
        annotated_callee_str = self.create_callee_specifications_by_llm(
            self.function_info.callee_set
        )    

        if required_type in annotated_callee_str:
            required_type = str()


        # Build input file path
        input_path = f"{self.function_info.file_path}"
        
        # Extract function code
        code = extract_function(input_path, self.function_info)[0][2]

        if require_str:
            template = f'''/*@
    {require_str}
    */
    '''
        else:

            
            template = ''
        content = (
                f'{required_type}\n' + annotated_callee_str +
                f'{template}\n{code}'
            )
        

        if self.debug:
            self.logger.info(f'Content of ACSL {self.function_info.name}.c file to be inserted into template: \n{content}')

        self.create_c_file(self.generated_loop_c_file_path, f'{self.function_info.name}.c',content)
    

    def create_annotated_callee(self,callee_set: set) -> str:
        if len(callee_set) == 0:
            return ''
        annotated_callee_list = []
        sub_callee_str = ''
        for callee_name in callee_set:
            for function_info in self.function_info_list:
                if function_info.name == callee_name:


                    
                    sub_callee_set = function_info.callee_set
                    if sub_callee_set != []:
                        sub_callee_str += self.create_annotated_callee(sub_callee_set)

                    function_header = function_info.code.split('{')[0]
                    # Extract new function
            
                    file_path = f"{self.annotated_loop_c_file_path}/{callee_name}.c"
                    #function_info.code = extract_function(file_path,callee_name)[0][2]
                    #code = function_info.code 
                    # print(function_info)
                    # print(extract_function(file_path,function_info))
                    code = extract_function(file_path,function_info)[0][2]

                

                    group = code.split('{')
                    function_code = '{'.join(group[1:])
                    annotated_callee = f'\n{function_header}{function_info.annotation}\n{{{function_code}'
                    # function_info.code = annotated_callee 
                    annotated_callee_list.append(annotated_callee)
                    break
        
        return sub_callee_str + '\n' + '\n'.join(annotated_callee_list)

    def create_custom_annotated_c_file(self,custom_annotation:str):

        self.function_info.annotation = custom_annotation
        
        
        def remove_comments_regex(code_str):
            # Remove single-line comments (//@ or #@ format)
            code_str = re.sub(r'//@.*', '', code_str)
            # Remove multi-line comments (/*@ ... */)
            code_str = re.sub(r'/\*@[\s\S]*?\*/', '', code_str, flags=re.DOTALL)
            # Remove standard multi-line comments (/* ... */)
            code_str = re.sub(r'/\*[\s\S]*?\*/', '', code_str, flags=re.DOTALL)
            return code_str
        

        
        required_type = self.create_required_type()
        
        annotated_callee_str = self.create_annotated_callee(self.function_info.callee_set)

        headers = '''
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        '''
        code = remove_comments_regex(self.function_info.code)
        groups = code.split('{')

        content = (headers +
                f'{required_type}\n' + annotated_callee_str +
                f'\n{groups[0]}\n{self.function_info.annotation}' + '{' + "{".join(groups[1:]))
        if self.debug:
            self.logger.info(f'Content of pre-annotated {self.function_info.name}.c file: \n{content}')
        self.create_c_file(self.annotated_c_file_path, f'{self.function_info.name}.c', content)
        self.create_c_file(self.annotated_loop_c_file_path, f'{self.function_info.name}.c', content)
        

    def create_annotated_c_file(self):
    
        def remove_comments_regex(code_str):
            # Remove single-line comments (//@ or #@ format)
            code_str = re.sub(r'//@.*', '', code_str)
            # Remove multi-line comments (/*@ ... */)
            code_str = re.sub(r'/\*@[\s\S]*?\*/', '', code_str, flags=re.DOTALL)
            # Remove standard multi-line comments (/* ... */)
            code_str = re.sub(r'/\*[\s\S]*?\*/', '', code_str, flags=re.DOTALL)
            return code_str
        

        
        required_type = self.create_required_type()
        

        annotated_callee_str = self.create_annotated_callee(self.function_info.callee_set)
        
        self.function_info.annotation = self.create_precondition()

        headers = '''
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        '''
        code = remove_comments_regex(self.function_info.code)
        groups = code.split('{')

        content = (headers +
                f'{required_type}\n' + annotated_callee_str +
                f'\n{groups[0]}\n{self.function_info.annotation}' + '{' + "{".join(groups[1:]))
        if self.debug:
            print(f'Content of pre-annotated {self.function_info.name}.c file: \n{content}')
        self.create_c_file(self.annotated_c_file_path, f'{self.function_info.name}.c', content)
        self.create_c_file(self.annotated_loop_c_file_path, f'{self.function_info.name}.c', content)



    def create_c_file(self,directory: str, filename: str, content: str) -> None:
        """
        Create a new .c file in the specified directory and write the given content.
        :param directory: Path to target directory
        :param filename: Filename (excluding path)
        :param content: Content to write to file
        """
        # Ensure directory exists, create if it doesn't exist
        if not os.path.exists(directory):
            os.makedirs(directory)
            print(f"Directory {directory} created.")

        # Build complete file path
        file_path = os.path.join(directory, filename)

        # Open file and write content
        try:
            with open(file_path, 'w') as f:
                f.write(content)
            print(f"File {file_path} created and written successfully.")
        except Exception as e:
            print(f"Error creating file: {e}")
    
    

    def create_callee_specifications_by_llm(self,callee_set: set) -> str:

        if len(callee_set) == 0:
            return ''
        annotated_callee_list = []
        sub_callee_str = ''
        processed_callees = set()  # Track processed callees to avoid duplicates
    
        for callee_name in callee_set:
            if callee_name in processed_callees:
                continue  # Skip already processed callees
                
            for function_info in self.function_info_list:
                if function_info.name == callee_name:

                    sub_callee_set = function_info.callee_set
                    
                    if sub_callee_set != []:
                        sub_callee_str += self.create_callee_specifications_by_llm(sub_callee_set)
                    
                    file_path = f"{self.output_path}/{callee_name}.c"
                    
                    # 如果文件不存在，直接跳过
                    if not os.path.exists(file_path):
                        self.logger.warning(f"Callee function {callee_name} file not found at {file_path}, skipping...")
                        processed_callees.add(callee_name)  # Mark as processed to avoid retry
                        break

                    code = ''
                    try:
                        with open(file_path, "r", encoding="utf-8") as file:
                            code = file.read()
                    except Exception as e:
                        self.logger.warning(f"Failed to read {file_path}: {e}, skipping...")
                        processed_callees.add(callee_name)  # Mark as processed to avoid retry
                        break
                    
                    if code:
                        annotated_callee_list.append(code)
                        processed_callees.add(callee_name)  # Mark as processed

                    break
        
        return sub_callee_str +'\n' + '\n'.join(annotated_callee_list)
    
    
    
    
    
    def create_callee_specifications(self,callee_set) -> str:

        if len(callee_set) == 0:
            return ''
        annotated_callee_list = []
        sub_callee_str = ''
        for callee_name in callee_set:
            for function_info in self.function_info_list:
                if function_info.name == callee_name:
                    
                
                    sub_callee_set = function_info.callee_set
                    if sub_callee_set != []:
                        sub_callee_str += self.create_callee_specifications(sub_callee_set)


                    function_header = function_info.code.split('{')[0]

                    annotation = function_info.specification

            
                    file_path = f"{self.generated_loop_c_file_path}/{callee_name}.c"

                    code = extract_function(file_path,function_info)[0][2]

                

                    group = code.split('{')
                    function_code = '{'.join(group[1:])
                    annotated_callee = f'\n{annotation}\n{function_header}\n{{{function_code}'
                  
                    
                    annotated_callee_list.append(annotated_callee)
                    break
        
        return sub_callee_str + '\n' + '\n'.join(annotated_callee_list)




        
    # def create_specification_by_llm(self) -> None:
    
    #     # Create required type definitions
    #     required_type = self.create_required_type()


    #     definitions_str = '\n'.join(self.definitions)

        
    #     require_str = self.function_info.require
        

    #     # Create specifications for called functions
    #     annotated_callee_str = self.create_callee_specifications_by_llm(
    #         self.function_info.callee_set
    #     )    

    #     if required_type in annotated_callee_str:
    #         required_type = ''

    #     # Build input file path
    #     input_path = f"{self.generated_loop_c_file_path}/{self.function_info.name}.c"
        
    #     # Extract function code
    #     code = extract_function(input_path, self.function_info)[0][2]

    #     # Create specification converter
    #     convertor = SpecificationConvertor(self.function_info)

    #     # Handle test functions
    #     if any(keyword in self.function_info.name for keyword in ['test','main','goo']):
    #         content = (
    #             f'{required_type}\n' + f'{definitions_str}\n' + annotated_callee_str +
    #             f'{code}'
    #         )
    #     # Handle functions with no parameters and void return
    #     elif self.function_info.parameter_list == [] and self.function_info.func_type == 'void':
    #         content = (
    #             f'{required_type}\n' + f'{definitions_str}\n' + annotated_callee_str +
    #             f'\n{code}'
    #         )
    #     # Handle void return functions
    #     elif self.function_info.func_type == 'void':
    #         template = f'''/*@
    # {require_str}
    # ensures PLACE_HOLDER;
    # */
    # '''
    #         content = (
    #             f'{required_type}\n' + f'{definitions_str}\n' + annotated_callee_str +
    #             f'{template}\n{code}'
    #         )
            
    #         if self.debug:
    #             print('content')
    #             print(content)
            
    #         # Generate specification annotations
    #         content = convertor.specgen_annotations(content)
    #     # Handle functions with return values
    #     else:
    #         template = f'''/*@
    # {require_str}
    # ensures PLACE_HOLDER;
    # ensures \\result == PLACE_HOLDER;
    # */
    # '''
    #         content = (
    #             f'{required_type}\n' + f'{definitions_str}\n' + annotated_callee_str +
    #             f'{template}\n{code}'
    #         )
            
    #         # Generate specification annotations
    #         content = convertor.specgen_annotations(content)

    #     # Create C file
    #     self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)


    #     for _ in range(self.config.refine_count):

    #             verifier = SpecVerifier(self.config,self.logger)
    #             verifier.run(self.function_info.name) 
                    
    #             # Get verification results (assuming list is returned)
    #             post_result = verifier.post_result
    #             assert_result = verifier.assert_result
    #             syntax_error = verifier.syntax_error

    #                 # Determine verification results
    #             valid = bool(post_result) and all(post_result)
    #             syntax = syntax_error ==''
    #             satisfy =  all(assert_result)

    #             if not syntax:

    #                 content = self.repair_spec(syntax_error, content)
    #                 self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)

    #             elif not valid or not satisfy:
    #                 error_list = verifier.post_error_list + verifier.assert_error_list
    #                 print('error_list')
    #                 print(error_list)
    #                 content = self.refine_spec(error_list,content)
    #                 self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)
                    
    #             else:
    #                 break

       
    #     # Debug output
    #     if self.debug:
            
    #          self.logger.info(f'Model generated specification content for {self.function_info.name}.c: {content}')

    def mark_failed_postcondition(self, code, post_results):
        # Match all postcondition statements, including complete ensures statements
        postcondition_pattern = re.compile(r'ensures\s+(.*?);', re.DOTALL)
        
        # Find all postconditions and their positions
        matches = list(postcondition_pattern.finditer(code))
        
        # Process from back to front to avoid offset issues
        for idx in reversed(range(len(post_results))):
            if idx < len(matches) and not post_results[idx]:
                match = matches[idx]
                
                # Get complete ensures statement position
                start = match.start()
                end = match.end()
                
                # Construct marked ensures statement
                original_condition = match.group(1)
                marked_statement = f"ensures {original_condition} [POSTCONDITION FAILED];"
                
                # Replace entire ensures statement
                code = code[:start] + marked_statement + code[end:]
        
        return code

    def _remove_duplicate_definitions(self, content: str) -> str:
        """
        Remove duplicate type definitions (struct definitions) from the content to avoid compilation errors.
        """
        lines = content.split('\n')
        seen_definitions = set()
        filtered_lines = []
        skip_lines = False
        brace_count = 0
        
        for line in lines:
            # Check if this line starts a struct definition
            struct_match = re.search(r'(?:typedef\s+)?struct\s+(\w+)', line)
            if struct_match:
                struct_name = struct_match.group(1)
                if struct_name in seen_definitions:
                    # Skip this duplicate definition
                    skip_lines = True
                    brace_count = line.count('{') - line.count('}')
                    continue
                else:
                    seen_definitions.add(struct_name)
                    skip_lines = False
                    brace_count = 0
            
            # If we're skipping a duplicate struct definition, count braces
            if skip_lines:
                brace_count += line.count('{') - line.count('}')
                if brace_count <= 0:
                    # End of struct definition
                    skip_lines = False
                    brace_count = 0
                continue
            
            filtered_lines.append(line)
        
        return '\n'.join(filtered_lines)

    def create_specification_by_llm(self) -> None:

        input_path = f"{self.generated_loop_c_file_path}/{self.function_info.name}.c"

        content = self.precond_manager.read_file_content(input_path)

        jump_flag = False

        ignore_list = self.ignore_list


        if any(keyword in self.function_info.name for keyword in ignore_list):
            print('ignore main')
            jump_flag = True
        # Handle functions with no parameters and void return
        elif self.function_info.parameter_list == [] and self.function_info.func_type == 'void':
            print('ignore void')
            jump_flag = True
        elif self.function_info.func_type == 'void':
            ensure_statement = 'ensures PLACE_HOLDER; \n    assigns PLACE_HOLDER;'
        else:
            ensure_statement = 'ensures PLACE_HOLDER; \n    ensures \\result == PLACE_HOLDER_RESULT;  \n    assigns PLACE_HOLDER;'


        if not jump_flag:
            content = self.precond_manager.add_ensures_to_function(content, self.function_info.name,ensure_statement)

        if self.debug:
            self.logger.info(f'content before specgen: \n{content}')

        convertor = SpecificationConvertor(self.function_info)


        # Generate specification annotations
        if not jump_flag:
            content = convertor.specgen_annotations(content)

        if self.debug:
            self.logger.info(f'content after specgen: \n{content}')

        # Remove duplicate type definitions to avoid compilation errors
        content = self._remove_duplicate_definitions(content)

        # Create C file
        self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)


        for _ in range(self.config.refine_count):

                verifier = SpecVerifier(self.config,self.logger)
                verifier.run(self.function_info.name) 
                    
                # Get verification results (assuming list is returned)
                post_result = verifier.post_result
                assert_result = verifier.assert_result
                loop_result = verifier.loop_result
                syntax_error = verifier.syntax_error
                

                    # Determine verification results
                valid = bool(post_result) and all(post_result) and all(loop_result)
                syntax = syntax_error ==''
                satisfy =  all(assert_result)

                if not syntax:

                    content = self.repair_spec(syntax_error, content)
                    self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)

                elif not valid or not satisfy:

                    error_list = verifier.post_error_list + verifier.assert_error_list + verifier.loop_error_list

                    content = self.mark_failed_postcondition(content, post_result)

                    self.logger.info(f'postconditon before refine: \n{content}')

                    content = self.refine_spec(error_list,content)

                    self.logger.info(f'postconditon after refine: \n{content}')

                    self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)
                    
                else:
                    break

       
        # Debug output
        if self.debug:
            
             self.logger.info(f'model generated specification of {self.function_info.name}.c is: \n{content}')

    def modify_specification_by_llm(self) -> None:

        self.logger.info(f'add assignments to specification')

        required_type = self.create_required_type()

        annotated_callee_str = self.create_callee_specifications(self.function_info.callee_set)

        if required_type in annotated_callee_str:
            required_type = ''
    
        function_header = self.function_info.code.split('{')[0]
            
        file_path = f"{self.generated_loop_c_file_path}/{self.function_info.name}.c"

        convertor = SpecificationConvertor(self.function_info)
        
        if self.function_info.require:
            only_pre = f'''/*@
            {self.function_info.require}
            */'''
        else:
            only_pre = str()

        self.function_info.specification = convertor.inconvert_annotations(self.function_info.annotation)

        specification = self.function_info.specification.split('*/')[0] + '\n' + 'assigns PLACE_HOLDER;' + '\n' + '*/'

        if self.debug:       
            self.logger.info(f'ACSL specification: \n{specification}')

        code = extract_function(file_path,self.function_info)[0][2]

        groups = code.split('{')

        ignore_list = self.ignore_list  

        jump_flag = False

        if any(keyword in self.function_info.name for keyword in ignore_list):
            jump_flag = True
            content = (
                f'{required_type}\n'  + annotated_callee_str + only_pre +
                f'\n{function_header}\n' + '{' + "{".join(groups[1:]))
        else:
            content = (
                f'{required_type}\n' + annotated_callee_str +
                f'\n{specification}\n{function_header}\n' + '{' + "{".join(groups[1:]))

      
        if not jump_flag:
            content = convertor.assign_annotations(content)
      

        if self.debug:
            self.logger.info(f'model generated specification of {self.function_info.name}.c is: \n{content}')
        self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)

       

        for _ in range(self.config.refine_count):

                verifier = SpecVerifier(self.config,self.logger)
                verifier.run(self.function_info.name) 
                    
                # Get verification results (assuming list is returned)
                post_result = verifier.post_result
                assert_result = verifier.assert_result
                loop_result = verifier.loop_result
                syntax_error = verifier.syntax_error

                    # Determine verification results
                valid = bool(post_result) and all(post_result) and all(loop_result)
                syntax = syntax_error ==''
                satisfy =  all(assert_result)

                if not syntax:

                    content = self.repair_spec(syntax_error, content)
                    self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)

                elif not valid or not satisfy:

                    error_list = verifier.post_error_list + verifier.assert_error_list + verifier.loop_error_list

                    content = self.mark_failed_postcondition(content, post_result)

                    self.logger.info(f'postconditon before refine: \n{content}')

                    content = self.refine_spec(error_list,content)

                    self.logger.info(f'postconditon after refine: \n{content}')

                    self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)
                    
                else:
                    break

       
        # Debug output
        if self.debug:
             self.logger.info(f'model modified specification of {self.function_info.name}.c is {content}')



    def refine_spec(self, error_list, c_code):
            """Call model to generate ACSL specification"""

            def format_errors(error_list):
                if not error_list:
                    return "No errors found."

                error_str = []

                for index, (desc, location, content) in enumerate(error_list, start=1):
                    desc = desc.splitlines()[0]

                    error_str.append(f"Error {index}: {desc}")
                    error_str.append(f"Code: {content}")
                    error_str.append("-" * 50)

                return "\n".join(error_str)
            
            

            error_str = format_errors(error_list)

            prompt = self.get_refine_prompt(error_str, c_code)

            try:
                """Call OpenAI API to get ACSL annotations"""
                

                def extract_last_c_code(text):
                    # Match C code blocks (Markdown code blocks or code starting with #include)
                    code_blocks = re.findall(r'```c(.*?)```', text, re.DOTALL)  # Markdown code blocks

                    return code_blocks[-1] if code_blocks else text  # Return the last C code block

                # Process response
                assistant_response = self.llm.chat(prompt)
                assistant_response = re.sub(r'>\s*Reasoning\s*[\s\S]*?(?=\n\n|$)', '', assistant_response, flags=re.IGNORECASE)
                assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
                assistant_response = extract_last_c_code(assistant_response)

                return assistant_response

            except Exception as e:
                self.logger.error(f"API call failed: {e}")
                return None
    
    def get_refine_prompt(self,error_message, c_code):
         # Read prompt template from file
        with open("prompt/func/refine.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # Replace {code} placeholder in template
        error_prompt = prompt_template.format(error_str = error_message , c_code= c_code)
        return error_prompt
    
    
    def create_final_c_file(self):


        required_type = self.create_required_type()
        

        annotated_callee_str = self.create_annotated_callee(self.function_info.callee_set)

        if required_type in annotated_callee_str:
            required_type = ''


        headers = '''
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        '''
        
        function_header = self.function_info.code.split('{')[0]
            
        file_path = f"{self.annotated_loop_c_file_path}/{self.function_info.name}.c"
                    
        code = extract_function(file_path,self.function_info)[0][2]

        groups = code.split('{')

        content = (headers +
                f'{required_type}\n'  + annotated_callee_str +
                f'\n{function_header}\n{self.function_info.annotation}\n' + '{' + "{".join(groups[1:]))
        
        if self.debug:
            self.logger.info(f'automated generated VST specification of {self.function_info.name}.c : \n{content}')
        self.create_c_file(self.annotated_loop_c_file_path, f'{self.function_info.name}.c', content)

    def create_specification(self):

        if self.if_assigns():

            self.modify_specification_by_llm()
            
        else:
            required_type = self.create_required_type()

            annotated_callee_str = self.create_callee_specifications(self.function_info.callee_set)

            if required_type in annotated_callee_str:
                required_type = ''
        
            function_header = self.function_info.code.split('{')[0]
                
            file_path = f"{self.generated_loop_c_file_path}/{self.function_info.name}.c"

            convertor = SpecificationConvertor(self.function_info)
            
            if self.function_info.require:
                only_pre = f'''/*@
                {self.function_info.require}
                */'''
            else:
                only_pre = str()

            self.function_info.specification = convertor.inconvert_annotations(self.function_info.annotation)
                        
            code = extract_function(file_path,self.function_info)[0][2]

            groups = code.split('{')

            ignore_list = self.ignore_list  

            if any(keyword in self.function_info.name for keyword in ignore_list):
                content = (
                    f'{required_type}\n'  + annotated_callee_str + only_pre +
                    f'\n{function_header}\n' + '{' + "{".join(groups[1:]))
            else:
                content = (
                    f'{required_type}\n' + annotated_callee_str +
                    f'\n{self.function_info.specification}\n{function_header}\n' + '{' + "{".join(groups[1:]))
        

            if self.debug:
                print(f'automated generated ACSL specification of {self.function_info.name}.c : \n{content}')
            self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)

    def create_looped_c_file(self):

            content = self.precond_manager.read_file_content(f"{self.generated_loop_c_file_path}/{self.function_info.name}.c")

            if self.debug:
                self.logger.info(f'{self.function_info.name}.c after loop invariant generation: \n{content}')

            self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)
    
    

    
    def repair_spec(self,error_message, c_code):
        """Call model to generate ACSL specification"""
        with open("prompt/error.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # Replace {code} placeholder in template
        error_prompt = prompt_template.format(error_str = error_message , c_code= c_code)

        try:
            """Call OpenAI API to get ACSL annotations"""
            
            def extract_last_c_code(text):
                # Match C code blocks (Markdown code blocks or code starting with #include)
                code_blocks = re.findall(r'```c(.*?)```', text, re.DOTALL)  # Markdown code blocks

                return code_blocks[-1] if code_blocks else text  # Return the last C code block

            # Process response
            assistant_response = self.llm.chat(error_prompt)
            assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
            assistant_response = extract_last_c_code(assistant_response)

            return assistant_response

        except Exception as e:
            self.logger.error(f"API call failed: {e}")
            return None
    
        
    

    def create_general_template_file(self):

        # Create required type definitions
        required_type = self.create_required_type()

        if self.config.use_db:
            definitions_str = '''
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        '''
        else:
            definitions_str = ''

        
        require_str = self.function_info.require


        if self.config.recursive_loop:
            require_str = 'requires PLACE_HOLDER;\n ensures PLACE_HOLDER;'
       


        # Create specifications for called functions
        annotated_callee_str = self.create_callee_specifications_by_llm(
            self.function_info.callee_set
        )    
        if annotated_callee_str and self.debug:
            self.logger.info(f'annotated_callee_str: \n{annotated_callee_str}')

        if required_type in annotated_callee_str:
            required_type = ''

        # Build input file path
        input_path = f"{self.generated_loop_c_file_path}/{self.function_info.name}.c"
        
        # Extract function code
        code = extract_function(input_path, self.function_info)[0][2]

        
        # Handle test functions
        if not require_str:
            definitions_str = ''
            content = (
                f'{required_type}\n' + f'{definitions_str}\n' + annotated_callee_str + 
                f'{code}'
            )
           
        # Handle functions with no parameters and void return
        else :
            template = f'''/*@
    {require_str}
    */
    '''
            content = (
                f'{required_type}\n' + f'{definitions_str}\n' + annotated_callee_str +
                f'{template}\n{code}'
            )
        
       
        # Debug output
        if self.debug:
            
             self.logger.info('Content of loop template: ' + content)

        return content