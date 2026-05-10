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
        # Skip pre/post-condition generation only for the program entry
        # point (`main`); other side-effect-free void functions are detected
        # dynamically via _is_side_effect_free() below.
        self.ignore_list = ['main']

        self.llm_config = llm_config
        self.llm = Chatbot(llm_config)

    def if_assigns(self) -> bool:

        for parameter in self.function_info.parameter_list:
            if parameter.is_ptr and parameter.is_struct:
                return True
        return False


    def create_precondition(self) -> str:
        """
        Generate precondition to be inserted into temporary .c file.

        Self-detect: if the source operates on a recursive data structure
        (linked list, tree, ...), structural precondition synthesis cannot
        express the well-formedness predicates required (lseg / listrep / ...).
        Skip the structural pass entirely and emit an empty contract; the
        downstream LLM stages (inv_gen + specgen) fill it in via the
        recursive_ds examples.
        """
        try:
            from example_retriever import classify
            file_path = getattr(self.function_info, 'file_path', None)
            if file_path:
                with open(file_path, 'r', encoding='utf-8') as fh:
                    if classify(fh.read()) == 'recursive_ds':
                        self.logger.info(
                            f'recursive_ds detected — skipping structural precondition for {self.function_info.name}'
                        )
                        return '/*@\nRequire emp\nEnsure Results(__return)\n*/'
        except Exception as e:
            self.logger.info(f'recursive_ds classification skipped: {e}')

        with_list = []
        require_list = []
        syntax_str = ''
        value_str = ''
        def parse_parameters_assertion(parameter_list:[List[Parameter]], with_list:list[str], require_list:list[str], syntax_str:str, value_str:str):
            if not parameter_list:
                return '', f'Require emp\n'

            for parameter in parameter_list:

                # Pointer, non-struct, non-array parameter

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
                    

                    code = ''

                    with open(file_path, "r", encoding="utf-8") as file:
                        code = file.read()
                    
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
    #     convertor = SpecificationConvertor(self.function_info, self.llm_config)

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

    def _dedup_acsl_global_decls(self, content: str) -> str:
        """Drop duplicate top-level `/*@ predicate <name> ... */`, `/*@ logic
        <type> <name> ... */`, and `/*@ inductive <name> ... */` blocks.
        Frama-C rejects redeclaring the same predicate/logic with the same
        profile (`predicate X is already declared with the same profile`).

        A block is dropped only when EVERY named declaration it contains has
        already been seen in an earlier block; otherwise it is kept whole so
        we don't accidentally lose a fresh declaration that happens to share
        the comment with a duplicate.
        """
        if not content:
            return content
        seen = set()  # set of (kind, name)
        out = []
        i = 0
        n = len(content)
        block_re = re.compile(r'/\*@.*?\*/', re.DOTALL)
        last_end = 0
        for m in block_re.finditer(content):
            block = m.group(0)
            decls = []
            for pm in re.finditer(r'\bpredicate\s+(\w+)\s*[\(\{]', block):
                decls.append(('predicate', pm.group(1)))
            for lm in re.finditer(r'\blogic\s+\w+(?:\s*\**)?\s+(\w+)\s*\(', block):
                decls.append(('logic', lm.group(1)))
            for am in re.finditer(r'\binductive\s+(\w+)\s*[\(\{]', block):
                decls.append(('inductive', am.group(1)))
            out.append(content[last_end:m.start()])
            if decls and all(d in seen for d in decls):
                # Drop the entire duplicate block (and trailing whitespace).
                trail_end = m.end()
                while trail_end < n and content[trail_end] in ' \t':
                    trail_end += 1
                if trail_end < n and content[trail_end] == '\n':
                    trail_end += 1
                last_end = trail_end
                continue
            for d in decls:
                seen.add(d)
            out.append(block)
            last_end = m.end()
        out.append(content[last_end:])
        return ''.join(out)

    def _remove_duplicate_definitions(self, content: str) -> str:
        """Remove duplicate `struct X { ... };` / `typedef struct ... {} X;`
        definitions to avoid compilation errors. Also drops duplicate
        top-level ACSL `predicate` / `logic` / `inductive` blocks.

        Handles both K&R style (`{` on next line) and same-line `{` styles.
        Field declarations like `struct SLL *tail;` and function headers like
        `struct SLL * main1(...)` are NOT treated as definitions.
        """
        # A definition starts with `struct <name>` or `typedef struct <name>`
        # with NO `*`, `(`, or identifier-other-than-whitespace between the
        # name and the opening `{`. The `{` may live on the same line or on a
        # later line (with only whitespace / blank lines in between).
        lines = content.split('\n')
        head_re = re.compile(r'^\s*(?:typedef\s+)?struct\s+(\w+)\s*(\{)?\s*$')
        seen = set()
        filtered = []
        skip_until_brace_close = False
        brace_depth = 0
        # Indices of lines that may be the start of a multi-line definition
        # but whose `{` we have not seen yet. Held so that we can DROP the
        # name line if it turns out to be a duplicate.
        pending_name_line = None  # (line_index_in_filtered, name)

        for line in lines:
            if skip_until_brace_close:
                brace_depth += line.count('{') - line.count('}')
                if brace_depth <= 0:
                    skip_until_brace_close = False
                    brace_depth = 0
                    if re.match(r'\s*\}[^;]*;', line):
                        continue
                continue

            if pending_name_line is not None:
                stripped = line.strip()
                if stripped == '':
                    filtered.append(line)
                    continue
                if stripped.startswith('{'):
                    # Confirmed multi-line struct definition. Decide dedup.
                    idx, name = pending_name_line
                    pending_name_line = None
                    if name in seen:
                        # Drop the name line we previously tentatively kept.
                        del filtered[idx]
                        skip_until_brace_close = True
                        brace_depth = line.count('{') - line.count('}')
                        if brace_depth <= 0:
                            skip_until_brace_close = False
                            brace_depth = 0
                        continue
                    seen.add(name)
                    filtered.append(line)
                    continue
                # Not a real definition (e.g. `struct SLL *p;`) — clear
                # pending and fall through to normal handling.
                pending_name_line = None

            m = head_re.match(line)
            if m:
                name = m.group(1)
                opens_now = m.group(2) is not None
                if opens_now:
                    if name in seen:
                        skip_until_brace_close = True
                        brace_depth = line.count('{') - line.count('}')
                        if brace_depth <= 0:
                            skip_until_brace_close = False
                            brace_depth = 0
                        continue
                    seen.add(name)
                    filtered.append(line)
                    continue
                # Name on this line, `{` expected on a later line — defer.
                filtered.append(line)
                pending_name_line = (len(filtered) - 1, name)
                continue

            filtered.append(line)

        deduped = '\n'.join(filtered)
        return self._dedup_acsl_global_decls(deduped)

    def _find_function_block(self, content: str, name: str):
        """Locate ``name``'s span and return four pieces:
        ``(preamble, contract, func_def, trailer)``.

        ``contract`` is the immediately-preceding `/*@ ... */` (or `/* ... */`)
        block plus the whitespace between it and the signature, or empty
        string if no contract precedes the signature. ``func_def`` is the
        signature plus the matching brace body. Returns
        ``(content, "", "", "")`` when the function is not found.
        """
        if not content or not name:
            return content, "", "", ""
        # Return-type fragment: an identifier followed by any mix of
        # whitespace / `*` / `[N]`. Repeated 1+ times so multi-word types
        # like `struct SLL *` or `unsigned long` are captured. (The earlier
        # form `[A-Za-z_][\w\*\[\]]*` failed on a standalone `*` between
        # `SLL` and the name.)
        sig_re = re.compile(
            r'(?:^|[\s;}])((?:[A-Za-z_]\w*[\s\*\[\]]+)+'
            + re.escape(name)
            + r'\s*\([^;{}]*\)\s*\{)'
        )
        m = sig_re.search(content)
        if not m:
            return content, "", "", ""
        sig_start = m.start(1)

        # Find the matching closing brace.
        body_open = m.end(1) - 1
        depth = 1
        i = body_open + 1
        body_end = -1
        while i < len(content):
            c = content[i]
            if c == '{':
                depth += 1
            elif c == '}':
                depth -= 1
                if depth == 0:
                    body_end = i + 1
                    break
            i += 1
        if body_end == -1:
            return content, "", "", ""

        # Look back for an attached /*@ ... */ (or /* ... */) contract.
        upstream = content[:sig_start]
        upstream_stripped = upstream.rstrip()
        contract_start = sig_start
        if upstream_stripped.endswith('*/'):
            opener = upstream_stripped.rfind('/*', 0, len(upstream_stripped) - 2)
            if opener != -1:
                contract_start = opener

        preamble = content[:contract_start]
        contract = content[contract_start:sig_start]
        func_def = content[sig_start:body_end]
        trailer = content[body_end:]
        return preamble, contract, func_def, trailer

    def _extract_global_decls(self, content: str):
        """Find every top-level `/*@ predicate <name>(...) ... */`,
        `/*@ logic <type> <name>(...) ... */`, and `/*@ inductive <name> ... */`
        block. Returns a list of ``(kind, name, full_block, span_start)`` so
        callers can reason about source order and uniqueness.
        """
        if not content:
            return []
        results = []
        for m in re.finditer(r'/\*@.*?\*/', content, re.DOTALL):
            block = m.group(0)
            decls = []
            for pm in re.finditer(r'\bpredicate\s+(\w+)\s*[\(\{]', block):
                decls.append(('predicate', pm.group(1)))
            for lm in re.finditer(r'\blogic\s+\w+(?:\s*\**)?\s+(\w+)\s*\(', block):
                decls.append(('logic', lm.group(1)))
            for am in re.finditer(r'\binductive\s+(\w+)\s*[\(\{]', block):
                decls.append(('inductive', am.group(1)))
            if not decls:
                continue
            end = m.end()
            full = content[m.start():end]
            if end < len(content) and content[end] == '\n':
                full += '\n'
            for kind, name in decls:
                results.append((kind, name, full, m.start()))
        return results

    def compute_function_assigns(self) -> str:
        """Static analysis: scan the target function body for every l-value
        written that is **caller-visible** (goes through a pointer, struct
        field, or array index — bare local-variable assignments are
        excluded), then union with each callee's already-emitted `assigns`
        clause. Returns the comma-separated location list (no leading
        `assigns ` keyword and no trailing `;`). Empty string if the function
        has no observable writes.

        Mirrors `inv_gen.compute_loop_assigns` (line 261) but at function
        scope: function-level `assigns` only lists state visible to the
        caller, so we filter out plain identifier writes (e.g.
        `int absfx1 = ...; absfx1 = -...`) which would otherwise leak
        local-variable names into the contract and trigger
        `unbound logic variable <local>` errors in Frama-C.
        """
        body = self.function_info.code or ''
        body = re.sub(r'/\*[\s\S]*?\*/', '', body)
        body = re.sub(r'//.*', '', body)

        # Allow optional leading `*` or `(*` for explicit-deref l-values like
        # `*(pIp->ret) = ...` and `*p = ...`.
        lvalue = (
            r'\*?\(?\s*\*?\s*[A-Za-z_]\w*'
            r'(?:\s*->\s*[A-Za-z_]\w*'
            r'|\s*\.\s*[A-Za-z_]\w*'
            r'|\s*\[[^\]]*\])*\)?'
        )
        targets = []

        def is_caller_visible(t):
            """Reject bare-identifier writes (locals/params-by-value).
            Accept anything that goes through `->`, `.`, `[`, `*` (i.e.
            reaches caller-visible memory)."""
            return bool(re.search(r'->|\.|\[|\*', t))

        def add(t):
            t = (t or '').strip()
            if not t:
                return
            if not is_caller_visible(t):
                return
            t_norm = re.sub(r'\s+', '', t)
            t_norm = re.sub(r'\[[^\]]*\]', '[..]', t_norm)
            if t_norm not in targets:
                targets.append(t_norm)

        for m in re.finditer(rf'({lvalue})\s*(?:=(?!=)|\+=|-=|\*=|/=|%=|<<=|>>=|&=|\|=|\^=)', body):
            add(m.group(1))
        for m in re.finditer(rf'({lvalue})\s*(?:\+\+|--)', body):
            add(m.group(1))
        for m in re.finditer(rf'(?:\+\+|--)\s*({lvalue})', body):
            add(m.group(1))

        # Union with each callee's `assigns` clause (already emitted into
        # output/<callee>.c by an earlier pipeline step).
        for callee_name in (self.function_info.callee_set or set()):
            callee_path = f'{self.output_path}/{callee_name}.c'
            if not os.path.exists(callee_path):
                continue
            try:
                with open(callee_path, 'r', encoding='utf-8') as fh:
                    callee_content = fh.read()
            except OSError:
                continue
            _, contract, _, _ = self._find_function_block(callee_content, callee_name)
            if not contract:
                continue
            am = re.search(r'\bassigns\s+([^;]+);', contract)
            if not am:
                continue
            for part in am.group(1).split(','):
                part = part.strip()
                if not part or part == r'\nothing':
                    continue
                # Callee assigns are already caller-visible by construction
                # (they were filtered when the callee was processed); accept
                # without re-applying the local filter so e.g. `\result` or
                # `*p` from a callee aren't dropped.
                t_norm = re.sub(r'\s+', '', part)
                t_norm = re.sub(r'\[[^\]]*\]', '[..]', t_norm)
                if t_norm not in targets:
                    targets.append(t_norm)

        return ', '.join(targets)

    def _drop_failing_ensures(self, content: str, post_result):
        """Strip `ensures` clauses in the TARGET function's contract whose
        corresponding ``post_result[i]`` is False, in source order.
        Other functions' contracts are untouched.
        """
        if not post_result or all(post_result):
            return content
        pre, contract, func_def, trail = self._find_function_block(
            content, self.function_info.name
        )
        if not contract.strip():
            return content
        pattern = re.compile(r'^(\s*)ensures\b[\s\S]*?;[^\n]*\n', re.MULTILINE)
        idx = [0]

        def replacer(m):
            if idx[0] < len(post_result):
                keep = post_result[idx[0]]
                idx[0] += 1
                return m.group(0) if keep else ''
            return m.group(0)

        new_contract = pattern.sub(replacer, contract)
        return pre + new_contract + func_def + trail

    def _drop_failing_loop_invariants(self, content: str, loop_result):
        """Strip `loop invariant` clauses (anywhere in the file) whose
        corresponding ``loop_result[i]`` is False, in source order.
        """
        if not loop_result or all(loop_result):
            return content
        pattern = re.compile(r'^(\s*)loop\s+invariant\b[\s\S]*?;[^\n]*\n', re.MULTILINE)
        idx = [0]

        def replacer(m):
            if idx[0] < len(loop_result):
                keep = loop_result[idx[0]]
                idx[0] += 1
                return m.group(0) if keep else ''
            return m.group(0)

        return pattern.sub(replacer, content)

    def _houdini_spec(self, content: str) -> str:
        """Final-stage Houdini for the spec layer: iteratively drop failing
        ``ensures`` (in the target's contract) and ``loop invariant``
        clauses until the SpecVerifier accepts the remaining set, the file
        becomes broken syntactically, or no further drops are possible.

        Always called at the end of ``create_specification_by_llm`` to
        ensure the final ``output/<func>.c`` is at least as good as what
        SpecVerifier can certify, even if the LLM refine loop bottomed out
        on a hallucination.
        """
        output_dir = self.output_path
        target = self.function_info.name

        for _ in range(5):
            # Persist current state for the verifier to inspect.
            self.create_c_file(output_dir, f'{target}.c', content)

            verifier = SpecVerifier(self.config, self.logger)
            verifier.run(target)
            post_result = verifier.post_result or []
            loop_result = verifier.loop_result or []
            syntax_ok = verifier.syntax_error == ''

            if syntax_ok and all(post_result) and all(loop_result):
                break  # Houdini converged — current set is verifiably valid

            if not syntax_ok:
                # Syntax already broken — Houdini can only delete clauses,
                # which won't fix syntax errors elsewhere. Bail out.
                break

            before = content
            content = self._drop_failing_ensures(content, post_result)
            content = self._drop_failing_loop_invariants(content, loop_result)
            if content == before:
                break  # nothing left to drop — stop to avoid infinite loop

        self.create_c_file(output_dir, f'{target}.c', content)
        return content

    def _merge_target_only(self, old_content: str, llm_output: str) -> str:
        """Splice the target function's contract+body from ``llm_output`` into
        ``old_content``. Everything else in ``old_content`` (typedefs, logic
        functions, every callee's contract+body, trailer) is preserved
        verbatim, EXCEPT that any NEW top-level `predicate` / `logic` /
        `inductive` declaration introduced by the LLM (and not already in
        ``old_content``) is hoisted into the preamble so the new contract can
        legally reference it.

        Splicing only happens when ``llm_output`` contains a complete target
        block — i.e. both an attached `/*@ ... */` contract AND a function
        definition. If the LLM omits either part the splice is rejected and
        ``old_content`` is returned unchanged: the existing PLACE_HOLDERs
        stay in place for the next refine iteration to retry. No silent
        fallback that mixes old contract with new body.
        """
        if not llm_output:
            return old_content
        target = self.function_info.name
        _, new_contract, new_func, _ = self._find_function_block(llm_output, target)
        if not new_func or not new_contract.strip():
            if self.debug:
                missing = "function definition" if not new_func else "contract"
                self.logger.info(
                    f'_merge_target_only: LLM output for {target} missing {missing}; keeping old_content'
                )
            return old_content
        old_pre, _, old_func, old_trail = self._find_function_block(old_content, target)
        if not old_func:
            if self.debug:
                self.logger.info(
                    f'_merge_target_only: target {target} not in old_content; using LLM output'
                )
            return llm_output

        # Hoist new top-level decls from llm_output into old_pre. Only blocks
        # that appear BEFORE the target function in the LLM output (so we
        # don't grab anything inside the target's contract or body) and whose
        # (kind, name) is not already present in old_content.
        existing = {(k, n) for k, n, _, _ in self._extract_global_decls(old_content)}
        target_pos_llm = llm_output.find(new_func)
        added = []
        added_keys = set()
        for kind, name, block, start in self._extract_global_decls(llm_output):
            if (kind, name) in existing or (kind, name) in added_keys:
                continue
            if target_pos_llm != -1 and start >= target_pos_llm:
                continue
            added.append(block)
            added_keys.add((kind, name))
        hoist = ''.join(added)
        if self.debug:
            if hoist:
                names = ', '.join(f'{k}:{n}' for k, n in added_keys)
                self.logger.info(f'_merge_target_only: hoisted new global decls -> {names}')
            self.logger.info(f'_merge_target_only: spliced {target} contract+body from LLM')
        return old_pre + hoist + new_contract + new_func + old_trail

    def _is_side_effect_free(self) -> bool:
        """Detect whether the current function has observable side effects:
        pointer-member writes (p->f = ...), index writes (p[i] = ...), or
        explicit deref writes ((*p) = ...). Mirrors main._auto_set_only_loop
        but operates on this generator's function rather than the entry func.
        """
        code = self.function_info.code or ""
        side_effect_patterns = [
            r'[A-Za-z_]\w*\s*->\s*[A-Za-z_]\w*\s*(?:\[[^\]]*\])?\s*[+\-*/%&|^]?=(?!=)',
            r'(?<![A-Za-z_\[])[A-Za-z_]\w*\s*\[[^\]]+\]\s*[+\-*/%&|^]?=(?!=)',
            r'\(\s*\*\s*[A-Za-z_]\w*\s*\)\s*[+\-*/%&|^]?=(?!=)',
        ]
        return not any(re.search(p, code) for p in side_effect_patterns)


    def _ensure_acsl_requires(self, content: str) -> str:
        """If `content` has no ACSL `requires` clause adjacent to the function
        definition, synthesize one and inject it right before the function.

        Path:
          - non-recursive_ds (numeric / array / recursive_program):
            translate QCP DSL Require produced by create_precondition.
          - recursive_ds (linked list / tree):
            QCP gives `Require emp` (we skip), so call an LLM precondgen
            with recursive_ds examples to produce predicate + requires
            ACSL directly.
        Idempotent — does nothing when a `requires` is already present.
        """
        func_name = self.function_info.name
        m = re.search(
            rf"(?:[A-Za-z_][\w\*\s]*?\s)+{re.escape(func_name)}\s*\(",
            content,
        )
        if not m:
            return content
        before = content[:m.start()]
        # Only treat the IMMEDIATELY-preceding /*@ ... */ comment as this
        # function's contract — earlier callees have their own contracts that
        # must NOT be confused with this function's. (The previous
        # last-2000-chars heuristic picked up Check's `requires` and made the
        # injector falsely believe boo already had a contract.)
        before_stripped = before.rstrip()
        if before_stripped.endswith("*/"):
            opener = before_stripped.rfind("/*", 0, len(before_stripped) - 2)
            if opener != -1:
                attached_contract = before_stripped[opener:]
                if re.search(r"\brequires\b", attached_contract):
                    return content

        convertor = SpecificationConvertor(self.function_info, self.llm_config)

        # Classify source. In the SE path, reserve LLM precondgen for
        # recursive data structures only; array preconditions should come from
        # the structural QCP→ACSL translation. When SE is disabled globally,
        # keep the existing LLM fallback behavior for arrays.
        category = ""
        src = ""
        try:
            from example_retriever import classify, get_examples_for
            file_path = getattr(self.function_info, 'file_path', None)
            if file_path:
                with open(file_path, 'r', encoding='utf-8') as fh:
                    src = fh.read()
                category = classify(src)
        except Exception as e:
            self.logger.info(f"category check skipped: {e}")

        acsl_requires = ""
        use_llm_precondgen = (
            category == "recursive_ds"
            or (category == "array" and not self.config.use_se)
        )

        if use_llm_precondgen:
            # Pass examples only for recursive_ds (lseg/listrep patterns).
            # For array the prompt's built-in array example suffices and we
            # don't want to bloat the prompt unnecessarily.
            examples_block = ""
            if category == "recursive_ds" and src:
                try:
                    _, examples_block = get_examples_for(src)
                except Exception as e:
                    self.logger.info(f"examples loading failed: {e}")
            try:
                acsl_requires = convertor.precondgen_annotations(content, examples_block)
                if acsl_requires:
                    self.logger.info(f"{category} precondgen produced:\n{acsl_requires}")
            except Exception as e:
                self.logger.info(f"{category} precondgen failed: {e}")
        else:
            acsl_requires = convertor.inconvert_requires(self.function_info.annotation or "")
            if acsl_requires and self.debug:
                self.logger.info(f"injecting translated ACSL requires:\n{acsl_requires}")

        if not acsl_requires:
            return content
        return before.rstrip() + "\n\n" + acsl_requires + "\n" + content[m.start():]

    def _inject_acsl_requires_into_file(self, file_path: str) -> None:
        """Write function-level ACSL requires into a specific intermediate file."""
        content = self.precond_manager.read_file_content(file_path)
        if not content:
            return
        updated = self._ensure_acsl_requires(content)
        if updated != content:
            directory = os.path.dirname(file_path)
            filename = os.path.basename(file_path)
            self.create_c_file(directory, filename, updated)

    def _inject_acsl_requires_before_loop_gen(self) -> None:
        """Write function-level ACSL requires into the 3_output file only."""
        self._inject_acsl_requires_into_file(
            f"{self.generated_loop_c_file_path}/{self.function_info.name}.c"
        )


    def create_specification_by_llm(self) -> None:

        input_path = f"{self.generated_loop_c_file_path}/{self.function_info.name}.c"

        content = self.precond_manager.read_file_content(input_path)

        jump_flag = False

        # Skip pre/post-condition generation only for:
        #   1. the program entry point (`main`)
        #   2. void functions with no observable side effects
        if self.function_info.name in self.ignore_list:
            print(f'ignore {self.function_info.name} (entry point)')
            jump_flag = True
        elif self.function_info.func_type == 'void' and self._is_side_effect_free():
            print(f'ignore {self.function_info.name} (side-effect-free void)')
            jump_flag = True
        elif self.function_info.func_type == 'void':
            ensure_statement = '  assigns PLACE_HOLDER; \n  ensures PLACE_HOLDER;   '
        else:
            ensure_statement = '  assigns PLACE_HOLDER;   \n  ensures PLACE_HOLDER; \n    ensures \\result == PLACE_HOLDER_RESULT;  '


        if not jump_flag:
            # If the loop-annotated file has no function-level `requires`,
            # synthesize an ACSL precondition by translating the QCP DSL
            # `Require ...` produced by create_precondition.
            content = self._ensure_acsl_requires(content)
            content = self.precond_manager.add_ensures_to_function(content, self.function_info.name,ensure_statement)

        if self.debug:
            self.logger.info(f'content before specgen: \n{content}')

        convertor = SpecificationConvertor(self.function_info, self.llm_config)


        # Generate specification annotations.
        # LLM input: full file. LLM output: only the target function block
        # (per specgen.txt rule). _merge_target_only splices the new target
        # block back into the original full file so any callee contracts the
        # LLM may have rewritten/dropped are restored verbatim.
        if not jump_flag:
            old_full = content
            llm_output = convertor.specgen_annotations(content)
            content = self._merge_target_only(old_full, llm_output)

        if self.debug:
            self.logger.info(f'content after specgen: \n{content}')

        # Remove duplicate type definitions to avoid compilation errors
        content = self._remove_duplicate_definitions(content)

        # Create C file
        self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)


        # Track the best candidate seen across refine iterations so a later
        # LLM call that makes things worse cannot overwrite the best output.
        # Sort key:
        #   (1) score = (syntax_ok, valid_ratio, satisfy_ratio)
        #   (2) clause_count of the target function's contract — same-score
        #       candidates with more ensures/requires/assigns/loop invariant
        #       lines win, so we don't drop a richer spec for a poorer one
        #   (3) iter_index t — newer wins on full tie
        best_content = content
        best_key = ((False, 0.0, 0.0), 0, -1)
        # Snapshot best's verifier output so a later iteration that scores
        # lower can roll content back to best AND reuse best's error list
        # for the next refine prompt — refine should always operate on the
        # cleanest known state, not on the latest LLM-corrupted state.
        best_state = {
            'syntax_error': '',
            'post_result': [],
            'assert_result': [],
            'loop_result': [],
            'assigns_result': [],
            'instance_result': [],
            'post_error_list': [],
            'assert_error_list': [],
            'loop_error_list': [],
            'assigns_error_list': [],
        }
        correct_flag = False

        def _grade(verifier):
            post = verifier.post_result or []
            asrt = verifier.assert_result or []
            loop = verifier.loop_result or []
            inst = getattr(verifier, 'instance_result', None) or []
            assigns = getattr(verifier, 'assigns_result', None) or []
            syntax_ok = verifier.syntax_error == ''
            # valid bucket = "contract-level proof obligations": post / loop /
            # callee instance / assigns. Each is a goal that fails when the
            # contract is wrong. assigns lives here (not in satisfy) because
            # an assigns failure means the contract under-claims, a
            # contract-level fix.
            total_v = post + loop + inst + assigns
            valid_ratio = (sum(1 for x in total_v if x) / len(total_v)) if total_v else 0.0
            # satisfy bucket = real `assert` proof obligations only.
            satisfy_ratio = (sum(1 for x in asrt if x) / len(asrt)) if asrt else 0.0
            return syntax_ok, valid_ratio, satisfy_ratio

        def _count_target_clauses(text):
            # Only count clauses inside the TARGET function's own contract;
            # callee-spec clauses don't reflect this candidate's quality.
            _, contract, _, _ = self._find_function_block(text or '', self.function_info.name)
            return len(re.findall(r'\b(ensures|requires|assigns|loop\s+invariant)\b', contract))

        for t in range(self.config.refine_count):

                verifier = SpecVerifier(self.config,self.logger)
                verifier.run(self.function_info.name)

                # Get verification results (assuming list is returned)
                post_result = verifier.post_result
                assert_result = verifier.assert_result
                loop_result = verifier.loop_result
                assigns_result = getattr(verifier, 'assigns_result', None) or []
                syntax_error = verifier.syntax_error


                    # Determine verification results.
                    # `assigns` joined the valid bucket once it was split out
                    # from `assert_result`; include it in the gate so an
                    # assigns failure triggers refine_spec, not break.
                valid = (
                    bool(post_result) and all(post_result)
                    and all(loop_result) and all(assigns_result)
                )
                syntax = syntax_error ==''
                satisfy =  all(assert_result)

                score = _grade(verifier)
                cur_key = (score, _count_target_clauses(content), t)
                if cur_key >= best_key:
                    best_content = content
                    best_key = cur_key
                    # Snapshot the full verifier state when we accept a new
                    # best so the next iteration can refine from this state.
                    best_state = {
                        'syntax_error': syntax_error,
                        'post_result': list(post_result or []),
                        'assert_result': list(assert_result or []),
                        'loop_result': list(loop_result or []),
                        'assigns_result': list(assigns_result),
                        'instance_result': list(getattr(verifier, 'instance_result', None) or []),
                        'post_error_list': list(verifier.post_error_list or []),
                        'assert_error_list': list(verifier.assert_error_list or []),
                        'loop_error_list': list(verifier.loop_error_list or []),
                        'assigns_error_list': list(getattr(verifier, 'assigns_error_list', None) or []),
                    }

                if syntax and valid and satisfy:
                    correct_flag = True
                    break

                # Roll back to best before refining: if this iteration
                # regressed (broken syntax / lower valid_ratio than best),
                # the LLM should not be asked to "fix" the broken state —
                # it should instead operate on the cleanest known version
                # with that version's error feedback. When the current
                # state IS best, this is a no-op.
                if cur_key < best_key:
                    content = best_content
                    self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)
                    if self.debug:
                        self.logger.info(
                            f'spec refine iter {t}: rolling back to best before refine '
                            f'(this iter score < best)'
                        )

                refine_syntax_error = best_state['syntax_error']
                refine_post_result = best_state['post_result']
                refine_error_list = (
                    best_state['post_error_list']
                    + best_state['assert_error_list']
                    + best_state['loop_error_list']
                    + best_state['assigns_error_list']
                )

                if refine_syntax_error:

                    old_full = content
                    llm_output = self.repair_spec(refine_syntax_error, content)
                    content = self._merge_target_only(old_full, llm_output)
                    self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)

                else:

                    content = self.mark_failed_postcondition(content, refine_post_result)

                    self.logger.info(f'postconditon before refine: \n{content}')

                    old_full = content
                    llm_output = self.refine_spec(refine_error_list, content)
                    content = self._merge_target_only(old_full, llm_output)

                    self.logger.info(f'postconditon after refine: \n{content}')

                    self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)

        if not correct_flag and best_key > ((False, 0.0, 0.0), 0, -1):
            # Refine exhausted without all-pass; roll back to the best
            # candidate so we don't ship a worse-than-best output.
            content = best_content
            self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)
            if self.debug:
                best_score, best_count, best_t = best_key
                self.logger.info(
                    f'spec refine exhausted; rolling back to best candidate '
                    f'(syntax={best_score[0]}, valid={best_score[1]:.2f}, '
                    f'satisfy={best_score[2]:.2f}, clauses={best_count}, iter={best_t})'
                )

        # Final Houdini pass — drop any `ensures` (target contract only) or
        # `loop invariant` clauses still failing verification. This is the
        # spec-layer counterpart to inv_gen's `hudini` and runs even when
        # `correct_flag` is True (no-op in that case since nothing fails).
        if not jump_flag:
            content = self._houdini_spec(content)

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

        convertor = SpecificationConvertor(self.function_info, self.llm_config)
        
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

        jump_flag = False

        if self.function_info.name in self.ignore_list:
            jump_flag = True
        elif self.function_info.func_type == 'void' and self._is_side_effect_free():
            jump_flag = True

        if jump_flag:
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

                    old_full = content
                    llm_output = self.repair_spec(syntax_error, content)
                    content = self._merge_target_only(old_full, llm_output)
                    self.create_c_file(self.output_path, f'{self.function_info.name}.c', content)

                elif not valid or not satisfy:

                    error_list = (
                        verifier.post_error_list
                        + verifier.assert_error_list
                        + verifier.loop_error_list
                        + getattr(verifier, 'assigns_error_list', [])
                    )

                    content = self.mark_failed_postcondition(content, post_result)

                    self.logger.info(f'postconditon before refine: \n{content}')

                    old_full = content
                    llm_output = self.refine_spec(error_list, content)
                    content = self._merge_target_only(old_full, llm_output)

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
            self.logger.info(f'automated generated QCP specification of {self.function_info.name}.c : \n{content}')
        self.create_c_file(self.annotated_loop_c_file_path, f'{self.function_info.name}.c', content)

    def create_specification(self):
        # SE-success path: SE produces ensures (via QCP→ACSL), `assigns` is
        # filled in by static analysis (compute_function_assigns). LLM is
        # never invoked here. The legacy `if_assigns()` branch that used
        # `modify_specification_by_llm` to ask the LLM to write `assigns`
        # for ptr-struct parameters is removed — static analysis covers
        # both ptr-struct and non-ptr-struct functions uniformly.
        required_type = self.create_required_type()

        annotated_callee_str = self.create_callee_specifications(self.function_info.callee_set)

        if required_type in annotated_callee_str:
            required_type = ''

        function_header = self.function_info.code.split('{')[0]

        file_path = f"{self.generated_loop_c_file_path}/{self.function_info.name}.c"

        convertor = SpecificationConvertor(self.function_info, self.llm_config)

        if self.function_info.require:
            only_pre = f'''/*@
            {self.function_info.require}
            */'''
        else:
            only_pre = str()

        self.function_info.specification = convertor.inconvert_annotations(self.function_info.annotation)

        # SE-only path with `use_se=True`: SE's QCP→ACSL translation
        # produces ensures clauses but not an `assigns` clause. Inject a
        # statically-computed one (mirror of `inv_gen.compute_loop_assigns`)
        # so the contract is complete without involving the LLM.
        if (
            self.function_info.specification
            and getattr(self.config, 'use_se', True)
            and not re.search(r'\bassigns\b', self.function_info.specification)
        ):
            computed = self.compute_function_assigns()
            assigns_clause = (
                f'\nassigns {computed};' if computed else '\nassigns \\nothing;'
            )
            idx = self.function_info.specification.rfind('*/')
            if idx != -1:
                self.function_info.specification = (
                    self.function_info.specification[:idx]
                    + assigns_clause
                    + '\n'
                    + self.function_info.specification[idx:]
                )

        code = extract_function(file_path,self.function_info)[0][2]

        groups = code.split('{')

        skip = (
            self.function_info.name in self.ignore_list
            or (self.function_info.func_type == 'void' and self._is_side_effect_free())
        )
        if skip:
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
    
    

    
    def _load_category_hints(self) -> str:
        """Concatenate the universal hint block with the category-specific one
        chosen by `example_retriever.classify`. Falls back to universal-only
        if classification is unavailable."""
        hints_dir = "prompt/error_hints"
        try:
            with open(f"{hints_dir}/universal.txt", "r", encoding="utf-8") as f:
                universal = f.read()
        except OSError:
            universal = ""

        category = ""
        try:
            from example_retriever import classify
            file_path = getattr(self.function_info, 'file_path', None)
            if file_path:
                with open(file_path, "r", encoding="utf-8") as fh:
                    category = classify(fh.read())
        except Exception:
            category = ""

        category_block = ""
        if category in ("numeric", "array", "recursive_ds", "recursive_program"):
            try:
                with open(f"{hints_dir}/{category}.txt", "r", encoding="utf-8") as f:
                    category_block = f.read()
            except OSError:
                category_block = ""

        parts = [p for p in (universal, category_block) if p]
        return "\n\n".join(parts)

    def repair_spec(self,error_message, c_code):
        """Call model to generate ACSL specification"""
        with open("prompt/error.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        category_hints = self._load_category_hints()
        error_prompt = prompt_template.format(
            error_str=error_message,
            c_code=c_code,
            category_hints=category_hints,
        )

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

        definitions_str = '''
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        '''

        
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

        # Read the 3_output file directly so we pick up any predicate / logic /
        # inductive blocks AND the function-level `requires` clauses produced
        # by the early SE / LLM precondgen injection. The previous
        # implementation rebuilt the template from `function_info.require` +
        # a bare `PLACE_HOLDER` and silently dropped the injected contract,
        # so the loop-invariant LLM never saw the precondition.
        input_path = f"{self.generated_loop_c_file_path}/{self.function_info.name}.c"
        try:
            with open(input_path, 'r', encoding='utf-8') as fh:
                full = fh.read()
        except OSError:
            full = ''

        preamble, contract, func_def, _ = self._find_function_block(
            full, self.function_info.name
        )
        if not func_def:
            # Fall back to in-memory function code if the file isn't readable.
            func_def = self.function_info.code
            preamble = ''
            contract = ''

        # Pull every /*@ ... */ block in the preamble that defines a
        # logic / predicate / inductive symbol — these are the early-injected
        # background declarations the LLM must see when filling invariants.
        pred_blocks = []
        for m in re.finditer(r'/\*@.*?\*/', preamble, re.DOTALL):
            block = m.group(0)
            if re.search(r'\b(predicate|logic|inductive)\b', block):
                pred_blocks.append(block)
        pred_blocks_str = ('\n'.join(pred_blocks) + '\n') if pred_blocks else ''

        # Decide which function-level contract to feed the LLM.
        if contract.strip():
            # Use the contract from the file; it carries the early-injected
            # `requires` clauses (e.g. `requires listrep(l);` for recursive_ds).
            template = contract
        elif require_str:
            template = f'''/*@
    {require_str}
    */
    '''
        else:
            template = ''

        # Handle test functions
        if not template.strip():
            content = (
                f'{required_type}\n' + pred_blocks_str + f'{definitions_str}\n'
                + annotated_callee_str + f'{func_def}'
            )

        # Handle functions with no parameters and void return
        else:
            content = (
                f'{required_type}\n' + pred_blocks_str + f'{definitions_str}\n'
                + annotated_callee_str + f'{template}\n{func_def}'
            )
        
       
        # Debug output
        if self.debug:
            
             self.logger.info('Content of loop template: ' + content)
             self.logger.info('ACSL loop skeleton before LLM:\n' + content)

        return content
