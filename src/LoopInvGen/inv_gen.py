import argparse
import json
import re
import os
import logging
from .loop_analysis import LoopAnalysis
from .output_verify import OutputVerifier
from .loop_processor import LoopProcessor
from config import MainConfig,LLMConfig
from llm import *
from convertor import SpecificationConvertor
from Utils.main_class import FunctionInfo
from example_retriever import get_examples_for
from spec_gen import SpecGenerator

os.environ["TOKENIZERS_PARALLELISM"] = "false"


# Shared guide strings injected into inv_gen.txt template. Kept module-level
# so the two prompt builders below share the exact same text without each
# carrying a ~12-line literal copy (previously duplicated 3 times in the
# `_db*` methods).
_PREDICATE_GUIDE = (
    '- If your invariant references a logic function or predicate not already '
    'defined in the file (e.g. `list_length(p)`, `sum(a, n)`, `sorted(a)`), '
    'you MUST add its complete definition as its own top-level '
    '`/*@ logic <type> <name>(...) = ...; */` or '
    '`/*@ predicate <name>(...) = ...; */` block, placed BEFORE the function. '
    'Referencing an undefined name fails with `unbound logic function <name>. '
    'Ignoring ... annotation` and Frama-C silently drops the entire annotation. '
    'If the file already has a placeholder `PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION`, '
    'fill it with the definition; otherwise emit a new `/*@ ... */` block before '
    'the function. Prefer reusing predicates already in the file (e.g. `listrep`, '
    '`lseg`) over inventing a new helper.'
)

_VERIFICATION_GUIDE = (
    '- Please first try to directly use the verification goal as the loop '
    'invariant at `PLACE_HOLDER_VERFICATION_GOAL`. Often, the verification goal '
    '(assertion) also holds throughout the loop; in that case, it can be used '
    'directly as the invariant.'
)

_STRENGTH_GUIDE = '- Generate loop invariants with equality constraints as comprehensively as possible.'


class InvGenerator:
    def __init__(self,config:MainConfig,info:FunctionInfo,logger:logging.Logger,llm_config:LLMConfig,spec_gen:SpecGenerator = None):

        self.config =config
        self.info = info
        self.convertor = SpecificationConvertor(info, llm_config)
        self.logger = logger
        self.llm_config = llm_config
        self.llm = Chatbot(llm_config)

        self.spec_gen = spec_gen
        self.error_history = []

        self.pass_count = self.config.pass_count
        self.first_pass = None


    
    def update_loop_content(self,code,new_loop_content,ridx):
        # Split code into single character list
        code_list = list(code)
        
        # Find all for or while loop positions
        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        matches = list(re.finditer(loop_pattern, code))
        
        loop_start = 0
        end_index = -1
        
        # Process each loop
        for idx, match in enumerate(matches):

            # Loop start position
            if idx == ridx:
                loop_start = match.start()  

                # Find the first } corresponding to { after the loop
                brace_count = 0
                loop_end = match.end()
                end_index = loop_end
                while brace_count >= 0:
                    if code_list[end_index] == '{':
                        brace_count += 1
                    elif code_list[end_index] == '}':
                        brace_count -= 1
                    end_index += 1

            
        # Replace loop content
        updated_code = (
            ''.join(code_list[:loop_start]) +  # Part before loop
            new_loop_content +                   # Replaced loop content
            ''.join(code_list[end_index:])   # Part after loop
        )
            
        # Rejoin character list into string
        return updated_code
    
    def get_annotated_loop_content(self,code,ridx):
        code_list = list(code)
        
        # Find all for or while loop positions
        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        matches = list(re.finditer(loop_pattern, code))

        at_index = 0
        end_index = -1
       
        # Process each loop
        for idx, match in enumerate(matches):
           
            # Loop start position
            if idx == ridx:

                loop_start = match.start()  
                 
                at_index = -1  # Default value, return -1 if '@' not found
                for i in range(loop_start - 1, -1, -1):  # Start from loop_start - 1, traverse backwards
                    if code_list[i] == '@':
                        at_index = i
                        break  # Found first '@', break loop

                at_index = at_index -2

                # Find the first } corresponding to { after the loop
                brace_count = 0
                loop_end = match.end()
                end_index = loop_end
                while brace_count >= 0:
                    if code_list[end_index] == '{':
                        brace_count += 1
                    elif code_list[end_index] == '}':
                        brace_count -= 1
                    end_index += 1
                

        # Replace loop content
        annotated_loop_content = ''.join(code_list[at_index:end_index]) 
            
        # Rejoin character list into string
        return annotated_loop_content
    
    def extract_var_map_from_state(self,text):
        
        var_map = {}
        # Regular expression matching patterns like "var == value", supporting nested parentheses
        pattern = r'(\w+)\s*==\s*(\((?:[^()]*|\((?:[^()]*|\([^()]*\))*\))*\)|[^()]+)'
        matches = re.findall(pattern, text)

        for var, value in matches:
            # Remove outer parentheses from value (if exists)
            value = value.strip()
            if value.startswith('(') and value.endswith(')'):
                value = value[1:-1]
            var_map[var] = value

        return var_map

    def append_verification_goal_annotations(self,annotations,path_cond,updated_loop_condition):
        invariant_annotation = None

        
        def contains_no_letters(updated_loop_condition):

            if updated_loop_condition == None:
                return True
            # Check if string contains letters
            if  'unknown' in updated_loop_condition:
                return True

            if re.search(r'[a-zA-Z]', updated_loop_condition):
                return False  # Contains letters
            else:
                return True  # No letters
            
        updated_code = []
        if contains_no_letters(updated_loop_condition) :
                if path_cond!=None:
                    invariant_annotation = f"loop invariant  ({path_cond}) ==> (PLACE_HOLDER_VERFICATION_GOAL) ;" 
                else:
                    invariant_annotation = f"loop invariant  PLACE_HOLDER_VERFICATION_GOAL ;" 
        else:
                if path_cond!=None:
                    invariant_annotation = f"loop invariant  ({path_cond}) ==> (({updated_loop_condition}) ==> (PLACE_HOLDER_VERFICATION_GOAL)) ;" 
                else:
                    invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> (PLACE_HOLDER_VERFICATION_GOAL);"
        


        found_first_annotation = False

        for line in annotations.splitlines():
            if not found_first_annotation and '/*@' in line:
            # Append the current line
                updated_code.append(line)
            # Insert the invariant annotations below the first occurrence of /*@
                updated_code.append(f"          {invariant_annotation}")
                found_first_annotation = True
            else:
            # Keep other lines as they are
                updated_code.append(line)

       # Join the list back into a single string and return
        return "\n".join(updated_code)


    
    def append_const_annotations(self,annotations, unchanged_vars,var_map,path_cond=None):
        # n == \at(n,Pre)
        invariant_annotations = []
       
        for var_name in unchanged_vars:
            if var_name in var_map.keys():

                value = self.convertor.filter_condition(var_map[var_name])
                var_name = self.convertor.filter_condition(var_name)
                
                if path_cond !=None :
                    path_cond = self.convertor.filter_condition(path_cond)
                    invariant_annotations.append(f"loop invariant ({path_cond}) ==> ({var_name} == {value});")
                else:
                    invariant_annotations.append(f"loop invariant {var_name} == {value};")
                # Iterate through the annotations

        updated_code = []
        found_first_annotation = False

        for line in annotations.splitlines():
            if not found_first_annotation and '/*@' in line:
            # Append the current line
                updated_code.append(line)
            # Insert the invariant annotations below the first occurrence of /*@
                for inv in invariant_annotations:
                    updated_code.append(f"          {inv}")
                found_first_annotation = True
            else:
            # Keep other lines as they are
                updated_code.append(line)

       # Join the list back into a single string and return
        return "\n".join(updated_code)
    
    
    def append_inner_annotations(self,annotations):
        updated_code = []
        invariant_annotation = f"PLACE_HOLDER_LOOP" 
        found_first_annotation = False

        for line in annotations.splitlines():
            if not found_first_annotation and '/*@' in line:
            # Append the current line
                updated_code.append(line)
            # Insert the invariant annotations below the first occurrence of /*@
                updated_code.append(f"          {invariant_annotation}")
                found_first_annotation = True
            else:
            # Keep other lines as they are
                updated_code.append(line)

       # Join the list back into a single string and return
        return "\n".join(updated_code)


    def append_assignments_annotations(self,annotations):
        updated_code = []
        invariant_annotation = f"loop assigns PLACE_HOLDER_ASSIGNMENTS;"
        found_first_annotation = False

        for line in annotations.splitlines():
            if not found_first_annotation and '/*@' in line:
            # Append the current line
                updated_code.append(line)
            # Insert the invariant annotations below the first occurrence of /*@
                updated_code.append(f"          {invariant_annotation}")
                found_first_annotation = True
            else:
            # Keep other lines as they are
                updated_code.append(line)

       # Join the list back into a single string and return
        return "\n".join(updated_code)


    def compute_loop_assigns(self, loop_content):
        """Static analysis: collect every L-value written in the loop body
        and emit a concrete `loop assigns ...;` clause. Deterministic — no LLM.

        Captures:
          - simple/compound assignment LHS (`x = ...`, `p->f += ...`, `a[i] *= ...`)
          - pre/post increment & decrement (`i++`, `--p->len`)
        Normalizes any `[idx]` form to `[..]` (ACSL "any cell").
        Returns "" if no writes detected.
        """
        body = re.sub(r"/\*[\s\S]*?\*/", "", loop_content or "")
        body = re.sub(r"//.*", "", body)

        # Strip the loop header so its update expression (e.g. `i++` in `for(...)`)
        # still counts but the condition expressions don't pollute the scan.
        m = re.search(r"\b(for|while|do)\b", body)
        if m and m.group(1) == "for":
            # for ( init ; cond ; update ) { body }
            paren_start = body.find("(", m.end())
            if paren_start != -1:
                depth = 1; i = paren_start + 1
                while i < len(body) and depth > 0:
                    if body[i] == "(": depth += 1
                    elif body[i] == ")": depth -= 1
                    i += 1
                # leave the for-update inside body so its `i++` is captured
                # but skip the cond/init by not splitting them out — regex below
                # also matches inside the header which is fine since header
                # writes are loop writes too.

        lvalue = r"[A-Za-z_]\w*(?:\s*->\s*[A-Za-z_]\w*|\s*\.\s*[A-Za-z_]\w*|\s*\[[^\]]*\])*"
        targets = []

        def add(t):
            t = t.strip()
            if not t:
                return
            t_norm = re.sub(r"\s+", "", t)
            t_norm = re.sub(r"\[[^\]]*\]", "[..]", t_norm)
            if t_norm not in targets:
                targets.append(t_norm)

        for m in re.finditer(rf"({lvalue})\s*(?:=(?!=)|\+=|-=|\*=|/=|%=|<<=|>>=|&=|\|=|\^=)", body):
            add(m.group(1))
        for m in re.finditer(rf"({lvalue})\s*(?:\+\+|--)", body):
            add(m.group(1))
        for m in re.finditer(rf"(?:\+\+|--)\s*({lvalue})", body):
            add(m.group(1))

        if not targets:
            return ""
        return f"loop assigns {', '.join(targets)};"


    def append_concrete_assigns(self, annotations, assigns_clause):
        """Insert a concrete `loop assigns ...;` clause right after the first /*@."""
        if not assigns_clause:
            return annotations
        out = []
        inserted = False
        for line in annotations.splitlines():
            out.append(line)
            if not inserted and '/*@' in line:
                out.append(f"          {assigns_clause}")
                inserted = True
        return "\n".join(out)

    

    def append_notin_annotations(self, annotations, var_map , updated_loop_condition,path_cond=None):
        invariant_annotation = None

        init_invariants = []
        for var in var_map:
            init_value = var_map[var]
            init_value = self.convertor.filter_condition(init_value)
            var = self.convertor.filter_condition(var)
            init_invariants.append( f'({var} == {init_value})')

      
        init_invariant = '&&'.join(init_invariants)

        def contains_no_letters(updated_loop_condition):

            if updated_loop_condition == None:
                return True

            if 'unknown' in updated_loop_condition :
                return True
            
            # Check if string contains letters
            if re.search(r'[a-zA-Z]', updated_loop_condition):
                return False  # Contains letters
            else:
                return True  # No letters
            
        if not contains_no_letters(updated_loop_condition):

            if path_cond !=None :
                invariant_annotation = f"loop invariant ({path_cond}) ==> ((!({updated_loop_condition})) ==> ({init_invariant}));"
            else:
                invariant_annotation = f"loop invariant (!({updated_loop_condition})) ==> ({init_invariant});"



        # Iterate through the annotations
        updated_code = []
        found_first_annotation = False

        for line in annotations.splitlines():
            if not found_first_annotation and '/*@' in line:
            # Append the current line
                updated_code.append(line)
            # Insert the invariant annotations below the first occurrence of /*@
                if invariant_annotation:
                    updated_code.append(f"          {invariant_annotation}")
                    found_first_annotation = True
            else:
            # Keep other lines as they are
                updated_code.append(line)

       # Join the list back into a single string and return
        return "\n".join(updated_code)


    def append_array_annotations(self,annotations,array_name,unchanged_arrays):
        updated_code = []
        if array_name in unchanged_arrays:
            invariant_annotation = f"loop invariant PLACE_HOLDER_UNCHANGED_ARRAY_{array_name} ;" 
        else:
            invariant_annotation = f"loop invariant PLACE_HOLDER_ARRAY_{array_name} ;" 
        found_first_annotation = False

        for line in annotations.splitlines():
            if not found_first_annotation and '/*@' in line:
            # Append the current line
                updated_code.append(line)
            # Insert the invariant annotations below the first occurrence of /*@
                updated_code.append(f"          {invariant_annotation}")
                found_first_annotation = True
            else:
            # Keep other lines as they are
                updated_code.append(line)

       # Join the list back into a single string and return
        return "\n".join(updated_code)


    def append_non_inductive_annotations(self,annotations,var_map,updated_loop_condition,key, path_cond=None):

        invariant_annotation = None

        init_invariants = []
        for var in var_map:
            init_value = var_map[var]
            init_value = self.convertor.filter_condition(init_value)
            var = self.convertor.filter_condition(var)
            init_invariants.append( f'({var} == {init_value})')
        
        init_invariant = '&&'.join(init_invariants)
    


        
        def contains_no_letters(updated_loop_condition):

            if updated_loop_condition == None:
                return True
            # Check if string contains letters
            if  'unknown' in updated_loop_condition:
                return True

            if re.search(r'[a-zA-Z]', updated_loop_condition):
                return False  # Contains letters
            else:
                return True  # No letters
            



        if contains_no_letters(updated_loop_condition) :
                if path_cond!=None:
                    invariant_annotation = f"loop invariant  ({path_cond}) ==> (({init_invariant}) || (PLACE_HOLDER_{key})) ;" 
                else:
                    invariant_annotation = f"loop invariant  ({init_invariant}) || (PLACE_HOLDER_{key}) ;" 
        else:
                if path_cond!=None:
                    invariant_annotation = f"loop invariant  ({path_cond}) ==> (({updated_loop_condition}) ==> (({init_invariant}) || (PLACE_HOLDER_{key}))) ;" 
                else:
                    invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> (({init_invariant}) || (PLACE_HOLDER_{key}));"

        updated_code = []
        found_first_annotation = False

        for line in annotations.splitlines():
            if not found_first_annotation and '/*@' in line:
            # Append the current line
                updated_code.append(line)
            # Insert the invariant annotations below the first occurrence of /*@
                updated_code.append(f"          {invariant_annotation}")
                found_first_annotation = True
            else:
            # Keep other lines as they are
                updated_code.append(line)

       # Join the list back into a single string and return
        return "\n".join(updated_code)
    
    
    def append_annotations(self,annotations,updated_loop_condition,key, path_cond=None):
        
        def contains_no_letters(updated_loop_condition):

            if updated_loop_condition == None:
                return True
            # Check if string contains letters
            if  'unknown' in updated_loop_condition:
                return True

            if re.search(r'[a-zA-Z]', updated_loop_condition):
                return False  # Contains letters
            else:
                return True  # No letters
            



        if contains_no_letters(updated_loop_condition) :
                if path_cond!=None:
                    invariant_annotation = f"loop invariant  ({path_cond}) ==> (PLACE_HOLDER_{key}) ;" 
                else:
                    invariant_annotation = f"loop invariant  PLACE_HOLDER_{key} ;" 
        else:
                if path_cond!=None:
                    invariant_annotation = f"loop invariant  ({path_cond}) ==> (({updated_loop_condition}) ==> (PLACE_HOLDER_{key})) ;" 
                else:
                    invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> (PLACE_HOLDER_{key}) ;"
        
        
        updated_code = []
        found_first_annotation = False

        for line in annotations.splitlines():
            if not found_first_annotation and '/*@' in line:
            # Append the current line
                updated_code.append(line)
            # Insert the invariant annotations below the first occurrence of /*@
                updated_code.append(f"          {invariant_annotation}")
                found_first_annotation = True
            else:
            # Keep other lines as they are
                updated_code.append(line)

       # Join the list back into a single string and return
        return "\n".join(updated_code)

    def get_json_at_index(self,json_file, idx):
        with open(json_file, 'r') as file:
            data = json.load(file)  # Read and parse JSON file
            
            if isinstance(data, list) and 0 <= idx < len(data):
                return data[idx]  # Return the idx-th JSON object
            else:
                raise IndexError("Index out of range or data is not a list")
            
    
    def get_c_code(self, c_file_path):
        """Read content from C file and generate user prompt"""
        try:
            with open(c_file_path, 'r') as file:
                c_code = file.read()
        except Exception as e:
            self.logger.error(f"Error reading file {c_file_path}: {e}")
            return None

        return c_code

    def parse_args(self):
        """Set up command line argument parser"""
        parser = argparse.ArgumentParser(description="Run Frama-C WP on a C file.")
        parser.add_argument('file_name', help="Path to the C file to analyze")
        return parser.parse_args()
    
    def repair(self,syntax_error,annotations,output_c_file_path):
        annotations = self.repair_annotations(syntax_error,annotations)  

        if self.config.debug:
            self.logger.info("after repair")
            self.logger.info(annotations)

        # Write ACSL annotations to output file
        with open(output_c_file_path, 'w', encoding='utf-8') as file:
            file.write(annotations)

        return annotations

    def regen(self,validate_result,syntax_error,annotations,output_c_file_path,pre_cond):

        annotations = self.mark_failed_invariants(annotations,validate_result)
        if self.config.debug:
            self.logger.info("after mark")
            self.logger.info(annotations)


        annotations = self.regen_annotations(syntax_error,annotations,pre_cond)  
        if self.config.debug:
            self.logger.info("after regen")
            self.logger.info(annotations)


        # Write ACSL annotations to output file
        with open(output_c_file_path, 'w', encoding='utf-8') as file:
            file.write(annotations)

        return annotations


    def strength(self,error_list,annotations,output_c_file_path):

        annotations = self.strength_annotations(error_list,annotations)
        

        if self.config.debug:
            self.logger.info("after strength")
            self.logger.info(annotations)
        

        # Write ACSL annotations to output file
        with open(output_c_file_path, 'w', encoding='utf-8') as file:
            file.write(annotations)
        
        return annotations

    def adjust(self,validate_result,error_list,annotations,output_c_file_path,pre_cond):
        

        annotations = self.mark_failed_invariants(annotations,validate_result)
        if self.config.debug:
            self.logger.info("after mark")
            self.logger.info(annotations)
           
        
        annotations = self.adjust_annotations(error_list,annotations,pre_cond)
        if self.config.debug:
            self.logger.info("after adjust")
            self.logger.info(annotations)

    
        # Write ACSL annotations to output file
        with open(output_c_file_path, 'w', encoding='utf-8') as file:
            file.write(annotations)

        return annotations
    
    def hudini(self,valid,file_name,annotations,output_c_file_path):
        ht = 0
            
        while valid != True and ht <= 5:
                
            verifier = OutputVerifier(self.config,self.logger)
            verifier.run(file_name)   # Pass complete path

            validate_result = verifier.validate_result

            error_examples = self.mark_failed_invariants(annotations,validate_result)

            self.error_history.append(error_examples)
            
            if len(validate_result) <= 1:
                break

            valid = bool(validate_result) and all(validate_result)


            annotations = self.hudini_annotations(validate_result,annotations)

            if self.config.debug:
                self.logger.info("after hudini")
                self.logger.info(annotations)


            # Write ACSL annotations to output file
            with open(output_c_file_path, 'w', encoding='utf-8') as file:
                    file.write(annotations)

            ht = ht +1
        return annotations
    
    def get_user_prompt(self, loop_content, pre_condition, examples):
        """Template A — basic invariant-gen prompt. Used for the use_se=False
        path and as the baseline (slot 0) variant in the 3-way attempt.
        No strength_guide, no verification_guide, only the predicate-defining
        guide (so the LLM still knows to declare any helper it references)."""
        with open("prompt/loop/inv_gen.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()
        user_prompt = prompt_template.format(
            content=loop_content,
            pre_cond=pre_condition,
            examples=examples,
            strength_guide='',
            predicate_guide=_PREDICATE_GUIDE,
            verification_guide='',
        )
        self.logger.debug("user_prompt")
        self.logger.debug(user_prompt)
        return user_prompt

    def get_user_prompt_template(self, loop_content, pre_condition, examples):
        """Template B — enriched invariant-gen prompt for the use_se=True path.
        Adds strength_guide; verification_guide is auto-injected when the loop
        block contains an inline `/*@ assert ... */` so the LLM is nudged
        toward using the verification goal itself as a loop invariant."""
        with open("prompt/loop/inv_gen.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()
        has_assert = bool(re.search(r'/\*@\s*assert\b', loop_content or ''))
        user_prompt = prompt_template.format(
            content=loop_content,
            pre_cond=pre_condition,
            examples=examples,
            strength_guide=_STRENGTH_GUIDE,
            predicate_guide=_PREDICATE_GUIDE,
            verification_guide=(_VERIFICATION_GUIDE if has_assert else ''),
        )
        self.logger.debug("user_prompt_template")
        self.logger.debug(user_prompt)
        return user_prompt


    def get_simgen_prompt(self, loop_content):
         # Read prompt template from file
        with open("prompt/loop/simgen.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # Replace {code} placeholder in template
        simgen_prompt = prompt_template.format(content=loop_content)
        return simgen_prompt
    

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
            file_path = getattr(self.info, 'file_path', None)
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

    def get_error_prompt(self,error_message, c_code):
         # Read prompt template from file
        with open("prompt/error.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        category_hints = self._load_category_hints()
        error_prompt = prompt_template.format(
            error_str=error_message,
            c_code=c_code,
            category_hints=category_hints,
        )
        return error_prompt
    
    def get_adjust_prompt(self,error_message, c_code):
         # Read prompt template from file
        with open("prompt/loop/adjust.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # Replace {code} placeholder in template
        adjust_prompt = prompt_template.format(error_str = error_message , c_code= c_code)
        return adjust_prompt
    
    def get_regen_prompt(self,error_message, c_code):
         # Read prompt template from file
        with open("prompt/loop/regen.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # Replace {code} placeholder in template
        regen_prompt = prompt_template.format(error_str = error_message , c_code= c_code)
        return regen_prompt
    
    def get_strength_prompt(self,error_message, c_code):
         # Read prompt template from file
        with open("prompt/loop/strength.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # Replace {code} placeholder in template
        strength_prompt = prompt_template.format(error_str = error_message , c_code= c_code)
        return strength_prompt
    
    def repair_annotations(self, error_message, c_code):
        """Call Model to generate ACSL specification"""

        prompt = self.get_error_prompt(error_message, c_code)

        try:
            """Call OpenAI API to get ACSL annotations"""
            

            def extract_last_c_code(text):
                # Match C code blocks (Markdown code blocks or code starting with #include)
                code_blocks = re.findall(r'```c(.*?)```', text, re.DOTALL)  # Markdown code blocks

                return code_blocks[-1] if code_blocks else text  # Return last C code block

            # Process response
            assistant_response = self.llm.chat(prompt)
            assistant_response = re.sub(r'>\s*Reasoning\s*[\s\S]*?(?=\n\n|$)', '', assistant_response, flags=re.IGNORECASE)
            assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
            assistant_response = extract_last_c_code(assistant_response)

            return assistant_response

        except Exception as e:
            self.logger.error(f"API call failed: {e}")
            return None
    
        
    def adjust_annotations(self, error_list, c_code,pre_cond):
            """Call Model to generate ACSL specification"""

            def format_errors(error_list):
                if not error_list:
                    return "No errors found."

                error_str = []

                for index, (desc, location, content) in enumerate(error_list, start=1):
                    desc = desc.splitlines()[0]
                    
                    error_str.append(f"Error {index}: {desc}")
                    # error_str.append(f"Location: {location}")
                    error_str.append(f"Code: {content}")
                    if 'Establishment' in desc:
                        error_str.append(
                            f"Instruction: The current precondition {pre_cond} cannot establish this invariant on loop entry. "
                            f"Either (a) weaken the invariant so the existing precondition implies it on entry, "
                            f"or (b) strengthen the function's `requires` precondition so it implies the invariant on entry — "
                            f"pick whichever better matches the intended behavior."
                        )
                    if 'Preservation' in desc:
                        error_str.append(f"Instruction: You need adjust the invariant to make sure it remains valid after each iteration.")
                    error_str.append("-" * 50)

                return "\n".join(error_str)

            error_str = format_errors(error_list)


            prompt = self.get_adjust_prompt(error_str, c_code)

            try:
                """Call OpenAI API to get ACSL annotations"""
               

                def extract_last_c_code(text):
                    # Match C code blocks (Markdown code blocks or code starting with #include)
                    code_blocks = re.findall(r'```c(.*?)```', text, re.DOTALL)  # Markdown code blocks

                    return code_blocks[-1] if code_blocks else text  # Return last C code block

                # Process response
                assistant_response = self.llm.chat(prompt)
                assistant_response = re.sub(r'>\s*Reasoning\s*[\s\S]*?(?=\n\n|$)', '', assistant_response, flags=re.IGNORECASE)
                assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
                assistant_response = extract_last_c_code(assistant_response)

                return assistant_response

            except Exception as e:
                self.logger.error(f"API call failed: {e}")
                return None
            
    def strength_annotations(self, error_list, c_code):
            """Call Model to generate ACSL specification"""

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


            prompt = self.get_strength_prompt(error_str, c_code)

            try:
                """Call OpenAI API to get ACSL annotations"""
                

                def extract_last_c_code(text):
                    # Match C code blocks (Markdown code blocks or code starting with #include)
                    code_blocks = re.findall(r'```c(.*?)```', text, re.DOTALL)  # Markdown code blocks

                    return code_blocks[-1] if code_blocks else text  # Return last C code block

                # Process response
                assistant_response = self.llm.chat(prompt)
            
                assistant_response = re.sub(r'>\s*Reasoning\s*[\s\S]*?(?=\n\n|$)', '', assistant_response, flags=re.IGNORECASE)
                assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
                assistant_response = extract_last_c_code(assistant_response)

                return assistant_response

            except Exception as e:
                self.logger.error(f"API call failed: {e}")
                return None
    

    def regen_annotations(self, error_list, c_code,pre_cond):
            """Call Model to generate ACSL specification"""

            def format_errors(error_list):
                if not error_list:
                    return "No errors found."

                error_str = []

                for index, (desc, location, content) in enumerate(error_list, start=1):
                    desc = desc.splitlines()[0]
                    error_str.append(f"Error {index}: {desc}")
                    error_str.append(f"Code: {content}")
                    if 'Establishment' in desc:
                        error_str.append(f"Instruction: You need weaken the invariant to be valid under initial conditions{pre_cond}.")
                    if 'Preservation' in desc:
                        error_str.append(f"Instruction: You need adjust the invariant to make sure it remains valid after each iteration and holds at the end of the loop.")
                    if 'Assertion' in desc:
                        error_str.append(f"Instruction: You need strengthen the invariant to make sure postcondition can be implied by the invariant combined with the negation of the loop condition.")
                    
                    error_str.append("-" * 50)

                return "\n".join(error_str)

            error_str = format_errors(error_list)
           

            prompt = self.get_regen_prompt(error_str, c_code)

            try:
                """Call OpenAI API to get ACSL annotations"""
                

                def extract_last_c_code(text):
                    # Match C code blocks (Markdown code blocks or code starting with #include)
                    code_blocks = re.findall(r'```c(.*?)```', text, re.DOTALL)  # Markdown code blocks

                    return code_blocks[-1] if code_blocks else text  # Return last C code block

                # Process response
                assistant_response = self.llm.chat(prompt)

                if self.config.debug:
                    self.logger.debug("regen reasoning")
                    self.logger.debug(assistant_response)
                assistant_response = re.sub(r'>\s*Reasoning\s*[\s\S]*?(?=\n\n|$)', '', assistant_response, flags=re.IGNORECASE)
                assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
                assistant_response = extract_last_c_code(assistant_response)

                return assistant_response

            except Exception as e:
                self.logger.error(f"API call failed: {e}")
                return None


    def hudini_annotations(self, validate_result, annotations):
        # Build matching pattern
        pattern = re.compile(
            r'^(\s*)loop\s+invariant\b[\s\S]*?;(.*?)(\n|$)', 
            flags=re.MULTILINE
        )

        # Use index to track current match
        current_index = [0]  # Use list to enable value modification in closure

        # Replacement handler
        def replacer(match):
            # Get current match result
            if current_index[0] < len(validate_result):
                should_keep = validate_result[current_index[0]]
                current_index[0] += 1
            else:
                # If array length is insufficient, keep by default
                should_keep = True

            # Return empty string to delete false items, keep true items
            return '' if not should_keep else match.group(0)

        # Execute global replacement
        return pattern.sub(replacer, annotations)


    def get_annotations(self, prompt):
        """Call OpenAI API to get ACSL annotations"""
       

        def extract_last_c_code(text):
                # Match C code blocks (Markdown code blocks or code starting with #include)
                code_blocks = re.findall(r'```c(.*?)```', text, re.DOTALL)  # Markdown code blocks

                return code_blocks[-1] if code_blocks else text  # Return last C code block

            # Process response
        assistant_response = self.llm.chat(prompt)
        if self.config.debug:
                    self.logger.debug("invgen reasoning")
                    self.logger.debug(assistant_response)
        assistant_response = re.sub(r'>\s*Reasoning\s*[\s\S]*?(?=\n\n|$)', '', assistant_response, flags=re.IGNORECASE)
        assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
        assistant_response = extract_last_c_code(assistant_response)

        return assistant_response

    
    
    def mark_failed_invariants(self,code, validation_results):
        # Match all loop invariant statements
        invariant_pattern = re.compile(r'loop invariant (.*?);\n', re.DOTALL)
        
        # Find all invariants and their positions
        matches = list(invariant_pattern.finditer(code))
        
        # Create modifiable code list
        code_list = list(code)
        offset = 0
        
        # Traverse validation results and mark failed items
        for idx, valid in enumerate(validation_results):
            if not valid and idx < len(matches):
                match = matches[idx]
                
                # Calculate actual position (considering previous modification offset)
                start = match.start(1) + offset
                end = match.end(1) + offset
                
                # Add marker
                marked = f"{match.group(1)} [INVARIANT FAILED] "
                
                # Replace content and update offset
                code_list[start:end] = list(marked)
                offset += len(marked) - (end - start)
        
        return ''.join(code_list)
    

    
    def create_list_prompt(self,content:str,examples:str) -> str:
    
        # Read prompt template from file
        try:
            with open('prompt/list/spec_gen.txt', 'r', encoding='utf-8') as f:
                prompt_template = f.read()
        except FileNotFoundError:
            print("File not found.")
            return None
        

        prompt = prompt_template.format(content=content,examples=examples)
        return prompt
    
        
    def get_examples(self, loop_code):
        # Classify the whole function (not just the loop) so structural
        # signals like self-referential structs and recursive calls are
        # visible. Fall back to loop_code if file_path read fails.
        try:
            with open(self.info.file_path, "r", encoding="utf-8") as fh:
                source = fh.read()
        except (OSError, AttributeError):
            source = loop_code or ""

        category, examples = get_examples_for(source)
        self.logger.info(f"examples category: {category}")
        self.logger.info("examples:")
        self.logger.info(examples)
        return examples


    def run(self):
        """Main logic"""

        self.llm = Chatbot(self.llm_config)

       
        file_name = self.info.name
        # generated_loop_c_file_path / annotated_loop_c_file_path are absolute
        # paths under workspace_root, so use them directly.
        output_c_file_path = os.path.join(self.config.generated_loop_c_file_path, f"{file_name}.c")
        output_symexe_c_file_path = os.path.join(self.config.annotated_loop_c_file_path, f"{file_name}.c")

        dir_path = '/'.join(output_c_file_path.split('/')[:-1])
        
        if dir_path:  
            os.makedirs(dir_path, exist_ok=True)


        json_file = os.path.join(getattr(self.config, 'workspace_root', '.') or '.', 'loop', f'{file_name}.json')

        processor = LoopProcessor(self.info,self.config)
        processor.init_execute()
        processor.execute()
        sorted_indices = processor.sorted_indices
        inner_flags = processor.inner_flags


       
        for idx in sorted_indices:

            if self.config.debug:
                self.logger.debug(f"INNER_FLAG: {inner_flags[idx]}")

            if idx == sorted_indices[0]:
                # First iteration: seed the 3_output file from the source so
                # the SE-translated ACSL `requires` can be injected BEFORE we
                # build any loop-invariant placeholder skeleton. Without this,
                # the function-level contract would only land in the file
                # after the placeholders are filled, defeating the early
                # injection invariant.
                src_code = self.get_c_code(self.info.file_path)
                with open(output_c_file_path, 'w', encoding='utf-8') as fh:
                    fh.write(src_code)

            # Inject the SE-derived precondition (translated from QCP DSL to
            # ACSL `requires`) before any placeholder is constructed. The
            # injector is idempotent — once a /*@ requires ... */ block is
            # attached to the function it returns the file unchanged.
            self.spec_gen._inject_acsl_requires_before_loop_gen()
            code = self.get_c_code(output_c_file_path)

            loop = self.get_json_at_index(json_file,idx)
            loop_content = processor.get_loop_content(code,idx)
            pre_condition =loop.get('condition')
            pre_condition =self.convertor.filter_condition(pre_condition)
            tag = f'''
        /* >>> LOOP INVARIANT TO FILL <<< */
        '''
            
            annotations_list = []
            
            annotations =f'''
            {tag}
            /*@
            */
            {loop_content}
            ''' 


            simple_annotations  = self.append_inner_annotations(annotations)
            annotations_list.append(simple_annotations)
            

            analysis = LoopAnalysis(json_file,idx,self.logger)
            analysis.run()
            
            unchanged_vars =analysis.global_unchanged_vars
            var_maps = analysis.var_maps
            path_conds =analysis.path_conds
            updated_loop_conditions = analysis.updated_loop_conditions
            array_names = analysis.array_names
            non_inductive_vars = analysis.non_inductive_vars
            unchanged_arrays = analysis.unchanged_arrays

           


            _code = self.update_loop_content(code,annotations,idx)

            simple = False

            # Structural template is part of the SE pipeline: when use_se is on
            # we run the deterministic analysis (assigns + read-only arrays) and
            # bake it into the loop annotation. When use_se is off, skip straight
            # to the LLM-only path.
            if self.config.use_se:

                # Deterministic loop-assigns: scan the loop body and emit a
                # concrete `loop assigns ...;` clause. No LLM involvement.
                assigns_clause = self.compute_loop_assigns(loop_content)
                annotations = self.append_concrete_assigns(annotations, assigns_clause)
                if self.config.debug:
                    self.logger.info(f"computed loop assigns: {assigns_clause}")
                    self.logger.info("after assignments")
                    self.logger.info(annotations)

                if array_names:
                    for array_name in array_names:
                        annotations = self.append_array_annotations(annotations,array_name,unchanged_arrays)

            else:

                if self.config.think:
                    cot = self.get_cot(_code)
                    if self.config.debug:
                        self.logger.info(f'think in natural language: {cot}')

                simple = True

            if not inner_flags[idx] and not simple:
                
                if self.config.think:
                    cot = self.get_cot(_code)
                    if self.config.debug:
                        self.logger.info(f'think in natural language: {cot}')
                    
                    # if self.error_history:
                    #     error_examples = '\n\n'.join(self.error_history)
                    #     cot = self.avoid_error(error_examples)
                    #     if self.config.debug:
                    #         self.logger.info(f'understand the error and avoid it: {cot}')
                    
                for var_map, path_cond,updated_loop_condition in zip(var_maps, path_conds,updated_loop_conditions):
                                path_cond = None


                                annotations  = self.append_const_annotations(annotations,unchanged_vars,var_map,path_cond)
                                if self.config.debug:
                                    self.logger.info("after const")
                                    self.logger.info(annotations)


                                updated_loop_condition = self.convertor.filter_condition(updated_loop_condition)

                                annotations  = self.append_notin_annotations(annotations,var_map,updated_loop_condition,path_cond)
                                if self.config.debug:
                                    self.logger.info("after not in")
                                    self.logger.info(annotations)
                                
                                for key in var_map.keys():
                                    if key not in unchanged_vars:
                                        if key in non_inductive_vars:
                                            annotations  = self.append_non_inductive_annotations(annotations,var_map,updated_loop_condition,key,path_cond)
                                        else:
                                            annotations  = self.append_annotations(annotations,updated_loop_condition,key,path_cond)
                                if self.config.debug:
                                    self.logger.info("after vars")
                                    self.logger.info(annotations)
                                
                                annotations_list.append(annotations)
                                # NOTE: previously a second slot was appended
                                # here with `append_verification_goal_annotations`,
                                # producing a SE+verification_goal candidate.
                                # That slot is no longer constructed — the
                                # single-slot selection below always picks
                                # slot 0 or slot 1, never slot 2.

                                
            else:
                simple = True

            if self.config.recursive_loop:
                annotations_list = [annotations_list[0]]

            # Single-slot selection: keep exactly one candidate template.
            # Layout (after the verification_goal slot was retired):
            #   [0] simple placeholder (no SE info, no PLACE_HOLDER_*)
            #   [1] SE template WITHOUT verification_goal placeholder
            #   [2+] cumulative variants from extra var_maps (discarded)
            #
            # Rule:
            #   use_se=False (or inner_flags[idx]) → slot 0 (simple)
            #   use_se=True                        → slot 1 (SE only)
            #
            # baseline data showed slot 1 was the de-facto winner whenever
            # SE built it; slot 0 stays the fallback for the
            # use_se=False / inner-loop path.
            if simple or len(annotations_list) <= 1:
                selected_idx = 0
                slot_kind = 'simple placeholder'
            else:
                selected_idx = 1
                slot_kind = 'SE only'
            self.logger.info(
                f'[inv-gen] single-slot mode: selected slot {selected_idx + 1}/'
                f'{len(annotations_list)} ({slot_kind}); discarded '
                f'{len(annotations_list) - 1} alternative slots'
            )
            annotations_list = [annotations_list[selected_idx]]

            for i,annotations in enumerate(annotations_list):

                annotations = self.update_loop_content(code,annotations,idx)
                with open(output_c_file_path, 'w', encoding='utf-8') as file:
                    file.write(annotations)
                annotations_list[i] = self.spec_gen.create_general_template_file()
     
            


            if simple:

                self.logger.debug("handle simple loop")
                user_prompt = self.get_simgen_prompt(annotations_list[0])
                annotations_list[0] = self.get_annotations(user_prompt)

            else:
                # Examples are category-specific reference invariants
                # (parity, decrement-chain, listrep, …) loaded by
                # `get_examples`. Skipping the load (use_examples=False) is
                # available for ablation; the prompt template tolerates an
                # empty `{examples}` substitution.
                examples = (
                    self.get_examples(loop_content)
                    if getattr(self.config, 'use_examples', True)
                    else ''
                )

                # Single-slot mode: annotations_list was already sliced to
                # length 1 above. Use the enriched template; its
                # verification_guide is auto-injected when loop_content has
                # an inline /*@ assert */, matching the slot we picked.
                user_prompt = self.get_user_prompt_template(
                    annotations_list[0], pre_condition, examples
                )
                annotations_list[0] = self.get_annotations(user_prompt)




            for annotations in annotations_list:
            
                annotations = annotations.replace(tag,'')

                for var_map, path_cond in zip(var_maps, path_conds):  
                    
                    if path_cond != None:
                        path_cond =self.convertor.filter_condition(path_cond)
                    

                
                    for var in var_map.keys():
                        replacement = self.convertor.filter_condition(var_map[var])

                        if path_cond == None:
                            annotations = annotations.replace(f'\\at({var},Pre)',replacement)

                        else:
                            annos = annotations.split(';')
                            nannos = []

                            for anno in annos:
                                if path_cond in anno:
                                    anno = anno.replace(f'\\at({var},Pre)',replacement)
                                    nannos.append(anno)
                                else:
                                    nannos.append(anno)


                            annotations = ';'.join(nannos)



            first_element = annotations_list.pop(0)
            annotations_list.append(first_element)

            if len(annotations_list) == 3:
                annotations_list = annotations_list[:-1]
            

            correct_flag = False
            loop_invariant = ''

            for annotations in annotations_list:

                if self.config.debug:
                    self.logger.info("candidated loop invariant")
                    self.logger.info(annotations)

        
                # Write ACSL annotations to output file
                with open(output_c_file_path, 'w', encoding='utf-8') as file:
                    file.write(annotations)

                if not inner_flags[idx]:
                    valid = False
                    # Track the best-scoring intermediate candidate so a later
                    # LLM iteration that makes things worse can't overwrite it.
                    # Sort key:
                    #   (1) score = (syntax_ok, valid_ratio, satisfy_ratio)
                    #   (2) clause_count = #(loop invariant ...)
                    #   (3) iter_index t — newer wins on full tie
                    # Tuple-lex `>=` natively orders by these in priority.
                    best_annotations = annotations
                    best_key = ((False, 0.0, 0.0), 0)
                    # Snapshot best's verifier state so the next refine can
                    # operate on the cleanest known candidate plus the
                    # error feedback that was generated for it, instead of
                    # whatever broken state the latest iter produced.
                    best_state = {
                        'syntax_error': '',
                        'validate_result': [],
                        'verify_result': [],
                        'valid_error_list': [],
                        'verify_error_list': [],
                    }

                    def _grade(verifier):
                        v = verifier.validate_result or []
                        w = verifier.verify_result or []
                        syntax_ok = verifier.syntax_error == ''
                        valid_ratio = (sum(1 for x in v if x) / len(v)) if v else 0.0
                        satisfy_ratio = (sum(1 for x in w if x) / len(w)) if w else 0.0
                        return syntax_ok, valid_ratio, satisfy_ratio

                    def _count_invariants(text):
                        return len(re.findall(r'\bloop\s+invariant\b', text or ''))

                    # Single flat refine loop. On 2 consecutive iters where
                    # cur_key < best_key, rollback file to best + truncate
                    # chat history to the snapshot at best time, then
                    # continue. The loop ends with one Houdini call to drop
                    # any still-failing invariants.
                    refine_count = max(0, getattr(self.config, 'refine_count', 9))
                    best_msg_count = self.llm.snapshot_history()
                    regression_count = 0

                    for t in range(refine_count):
                        verifier = OutputVerifier(self.config, self.logger)
                        verifier.run(file_name)

                        validate_result = verifier.validate_result
                        verify_result = verifier.verify_result
                        syntax_error = verifier.syntax_error
                        valid = bool(validate_result) and all(validate_result)
                        syntax = syntax_error == ''
                        satisfy = all(verify_result)

                        score = _grade(verifier)
                        inv_count = _count_invariants(annotations)
                        cur_key = (score, inv_count)
                        self.logger.info(
                            f'[inv-gen] refine {t+1}/{refine_count} '
                            f'score=(syntax={score[0]}, valid={score[1]:.2f}, '
                            f'satisfy={score[2]:.2f}) clauses={inv_count}'
                        )
                        # Strict > = real progress; tie or worse counts as
                        # regression (in-place stalling burns budget too).
                        if cur_key > best_key:
                            best_annotations = annotations
                            best_key = cur_key
                            best_msg_count = self.llm.snapshot_history()
                            regression_count = 0
                            best_state = {
                                'syntax_error': syntax_error,
                                'validate_result': list(validate_result or []),
                                'verify_result': list(verify_result or []),
                                'valid_error_list': list(verifier.valid_error_list or []),
                                'verify_error_list': list(verifier.verify_error_list or []),
                            }
                        else:
                            regression_count += 1

                        if syntax and valid and satisfy:
                            self.logger.info(f'[inv-gen] converged at refine {t+1}')
                            correct_flag = True
                            break

                        # Regression rollback+prune: 2 consecutive iters
                        # without strict improvement (same or lower than
                        # best) → restore file to best AND truncate chat
                        # history to the snapshot at best time. Pruning the
                        # bad / stalled refine exchanges lets the next call
                        # explore differently from the same clean slate.
                        if regression_count >= 2:
                            self.logger.info(
                                f'[inv-gen] regression '
                                f'(2 consecutive iters cur_key<=best_key); '
                                f'rollback file + prune messages to best '
                                f'snapshot (msgs={best_msg_count})'
                            )
                            annotations = best_annotations
                            with open(output_c_file_path, 'w', encoding='utf-8') as file:
                                file.write(annotations)
                            self.llm.truncate_history(best_msg_count)
                            regression_count = 0
                            continue

                        # Use CURRENT verifier output as refine feedback so
                        # chat history and on-disk file stay in sync.
                        refine_error_list = (
                            list(verifier.valid_error_list or [])
                            + list(verifier.verify_error_list or [])
                        )

                        if syntax_error:
                            annotations = self.repair(syntax_error, annotations, output_c_file_path)
                        elif not valid or (not satisfy and idx == sorted_indices[-1] and self.config.only_loop):
                            if valid:
                                annotations = self.strength(refine_error_list, annotations, output_c_file_path)
                            elif (satisfy and idx == sorted_indices[-1] and self.config.only_loop):
                                annotations = self.adjust(validate_result, refine_error_list, annotations, output_c_file_path, pre_condition)
                            else:
                                annotations = self.regen(validate_result, refine_error_list, annotations, output_c_file_path, pre_condition)

                    # Final Houdini: rollback to best and drop any still-
                    # failing invariants. Runs once after the refine budget
                    # is exhausted (no-op if already converged).
                    if not correct_flag:
                        annotations = best_annotations
                        with open(output_c_file_path, 'w', encoding='utf-8') as file:
                            file.write(annotations)
                        self.logger.info(
                            f'[inv-gen] refine exhausted → final Houdini '
                            f'on best (score={best_key[0]}, clauses={best_key[1]})'
                        )
                        annotations = self.hudini(False, file_name, annotations, output_c_file_path)
                        best_annotations = annotations
            

            loop_invariant = annotations
            if self.config.debug:
                self.logger.info("loop invariant annotated")
                self.logger.info(loop_invariant)

                        
            verifier = OutputVerifier(self.config,self.logger)
            verifier.run(file_name) 

            validate_result = verifier.validate_result
            verify_result = verifier.verify_result
            syntax_error = verifier.syntax_error

            valid = bool(validate_result) and all(validate_result)
            syntax = syntax_error ==''
            satisfy = all(verify_result)  

            loop_invariant = self.get_annotated_loop_content(loop_invariant,idx)


            self.logger.info("ACSL format loop invariant")
            self.logger.info(loop_invariant)

            loop_invariant = self.convertor.convert_annotations(loop_invariant)

            self.logger.info("QCP format loop invariant")
            self.logger.info(loop_invariant)
              

            symexe_updated_code  =processor.update_loop_content(self.get_c_code(processor.output_file),loop_invariant,idx)
                    
            if syntax and valid:
                if self.config.debug:
                    self.logger.info("PARTIAL CORRECT INVARIANT")
                    self.logger.info("continue symbolic execution")
                    self.logger.info(annotations)
                # Write ACSL annotations to output file
                with open( output_symexe_c_file_path, 'w', encoding='utf-8') as file:
                        file.write(symexe_updated_code)
                processor.execute()

        
        
        
        verifier = OutputVerifier(self.config,self.logger,True)
        verifier.run(file_name) 

        validate_result = verifier.validate_result
        verify_result = verifier.verify_result
        syntax_error = verifier.syntax_error

        valid = bool(validate_result) and all(validate_result)
        syntax = syntax_error ==''
        satisfy = all(verify_result)

        if syntax and valid and satisfy:
            self.logger.info("CORRECT INVARIANT")


    
    





    def get_cot(self,c_code):
        with open('prompt/loop/cot.txt', 'r', encoding='utf-8') as f:
            prompt_template = f.read()
        
        prompt = prompt_template.format(c_code=c_code)

        response = self.llm.chat(prompt)

        return response   

    def run_pass(self):
        file_name = self.info.name


        self.logger.info(f'file_name: {file_name}')

        
        # Used to record results for each round
        results = []

        # Record earliest satisfying round (initialized to None)
        first_valid_round = None
        first_syntax_round = None
        first_satisfy_round = None


        for t in range(self.pass_count):
            print(f'TRY TIME: {t}')

            self.run()

            verifier = OutputVerifier(self.config, self.logger)
            verifier.run(file_name)

            validate_result = verifier.validate_result
            verify_result = verifier.verify_result
            syntax_error = verifier.syntax_error

            valid = bool(validate_result) and all(validate_result)
            syntax = syntax_error == ''
            satisfy =  all(verify_result)

            # Save this round's result
            results.append({
                    "round": t + 1,   # Count from 1
                    "valid": valid,
                    "syntax": syntax,
                    "satisfy": satisfy
                })

            # If it's the first time satisfying, record it
            
            if syntax and first_syntax_round is None:
                first_syntax_round = t + 1
            if syntax and valid and first_valid_round is None:
                first_valid_round = t + 1
            if syntax and valid and satisfy and first_satisfy_round is None:
                first_satisfy_round = t + 1
            
            if syntax and valid and satisfy:
                break

        # Output earliest satisfying round
        self.logger.info("="*50)
        self.logger.info("first_pass:")
        self.logger.info(f"syntax={first_syntax_round}, valid={first_valid_round},satisfy={first_satisfy_round}")
        self.first_pass ={
            "syntax": first_syntax_round,
            "valid": first_valid_round,
            "satisfy": first_satisfy_round
        }
        self.logger.info("="*50)

        return self.first_pass


 



# if __name__ == "__main__":
#     generator = InvGenerator()
#     generator.run()







