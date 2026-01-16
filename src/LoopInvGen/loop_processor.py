import argparse
import subprocess
import os
import re
import json
from Utils.main_class import *
from config import MainConfig

class LoopProcessor:
    def __init__ (self, info : FunctionInfo, config: MainConfig):
        """
        Initialize LoopProcessor object.
        :param file_name: Filename (without extension)
        """
        
        self.function_info = info
        self.file_name = info.name
        self.code = info.code
        self.loop_contents = None  # Store loop content
        self.sorted_indices = None  # Store sorted indices
        self.loop_entries = []  # Store extracted loop entries

        self.goal_file = f"../goal/{self.file_name}_goal.v"
        self.proof_auto_file = f"../goal/{self.file_name}_proof_auto.v"
        self.proof_manual_file = f"../goal/{self.file_name}_proof_manual.v"
        # self.input_file = f"symexe/input/{self.file_name}.c"
        # self.output_file =f"symexe/output/{self.file_name}.c"
        # self.iter_file = f"../../LoopInvGen_V7/symexe/output/{self.file_name}.c"
        self.input_file = f"../src/{config.annotated_c_file_path}/{self.file_name}.c"
        self.output_file =f"../src/{config.annotated_loop_c_file_path}/{self.file_name}.c"
        self.iter_file = f"../../src/{config.annotated_loop_c_file_path}/{self.file_name}.c"
        self.json_file = f'loop/{self.file_name}.json'

    def delete_file_if_exists(self, file_path):
        """
        Delete file if it exists.
        :param file_path: File path
        """
        file_path = os.path.join('../QCP/test', file_path)
        if os.path.exists(file_path):
           # print(f"File found: {file_path}. Deleting the file.")
            os.remove(file_path)
        #else:
          #  print(f"File not found: {file_path}. No file to delete.")
    
   

    # Find the beginning and end of each loop
    def process_loop(self,code):
    

        def determine_inner_loops(loop_info):
            """
            Determine whether each loop is an inner loop.
            Parameters:
                loop_info: list of tuples, each element is (start_pos, end_pos, loop_index)
            Returns:
                list of bool, indicating whether each loop is an inner loop (in loop_info input order)
            """
            inner_flags = [False] * len(loop_info)
            
            
            # Traverse all loop pairs (i, j)
            for j in range(len(loop_info)):
                s_j, e_j, idx_j = loop_info[j]
                for i in range(len(loop_info)):
                    if i == j:
                        continue
                    s_i, e_i, idx_i = loop_info[i]
                    # If loop i completely contains loop j: i starts earlier and ends later
                    if s_i < s_j and e_i > e_j:
                        inner_flags[j] = True
                        break  # As long as it's contained by one outer loop, it can be determined as inner
            
            return inner_flags
        # Split code into single character list
        code_list = list(code)
        
        # Find all for or while loop positions
        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        matches = list(re.finditer(loop_pattern, code))
        loop_contents = []
        loop_indices=[]
        
        # Process each loop
        for idx, match in enumerate(matches):
            # Loop start position
            loop_start = match.start()    

            at_index = loop_start

            loop_head= code_list[at_index] 
            
            code_list[at_index-1] = f'\n {code_list[at_index -1 ]}/*@ Print user assertion at number LoopEntry_{idx}*/ \n'
            code_list[at_index] = f'/*@ Inv emp */ /*{idx}*/ \n {code_list[at_index]}'

            
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

            # Push (at_index,end_index, idx) into list
            loop_indices.append((at_index,end_index, idx))
          

            # Extract loop content
            loop_content = loop_head + ''.join(code_list[loop_start +1:end_index])

           
            # Modify comments to ACSL format
            assert_pattern = r'/\*@\s*(.*?)\s*\*/'
    
            # Replace with /*@ assert xxxxxx ;*/
            loop_content = re.sub(assert_pattern, r'/*@ assert \1; */', loop_content)

            loop_content = loop_content.replace('=>','==>')
            
            
            # Print loop content
            # print(f"LoopContent_{idx}:\n{loop_content}\n")
            loop_contents.append(loop_content)
        
        # print(loop_indices)

        inner_flags = determine_inner_loops(loop_indices)

        
        # Sort by end_index from small to large
        sorted_indices = [x[2] for x in sorted(loop_indices, key=lambda x: x[1])]
        
            
        # Rejoin character list into string
        return ''.join(code_list),loop_contents,sorted_indices,inner_flags
    


    def get_loop_content(self,code,ridx):

        # Find all for or while loop positions
        code_list = list(code)
        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        loop_content = None
        matches = list(re.finditer(loop_pattern, code))
        
        # Process each loop
        for idx, match in enumerate(matches):
            if idx == ridx:
                # Loop start position
                loop_start = match.start()    

                at_index = loop_start

                loop_head = code_list[at_index] 
            
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

                # Extract loop content
                loop_content = loop_head + ''.join(code_list[loop_start +1:end_index])
                break

        return loop_content

    
    def process_loop_file(self,input_file_path,output_file_path):
        # Read original file content
        if input_file_path != None:
            with open(input_file_path, 'r', encoding='utf-8') as infile:
                code = infile.read()
        else:
            code = self.code
        
        # Call process_code to process code
        processed_code = self.process_loop(code)[0]
        loop_contents = self.process_loop(code)[1]
        sorted_indices = self.process_loop(code)[2]
        inner_flags = self.process_loop(code)[3]


        # Write processed code to new file
        with open(output_file_path, 'w', encoding='utf-8') as outfile:
            outfile.write(processed_code)

        return loop_contents,sorted_indices,inner_flags

    def get_loop_entries(self, text):
        """
        Extract LoopEntry_X conditions from text using regular expressions.
        :param text: Input text
        :return: List of extracted loop entries
        """
       
        pattern = r"LoopEntry_(\d+):\s*\n([^\n]*)"
        matches = re.findall(pattern, text)

        self.loop_entries = []
        for match in matches:
            loop_id = int(match[0])  # Extract number
            condition = match[1].strip()  # Extract condition and remove leading/trailing whitespace
            self.loop_entries.append((loop_id, condition))

        # Sort by loop_id
        self.loop_entries.sort(key=lambda x: x[0])
        return self.loop_entries

    def write_loops_to_json(self):
        """
        Write loop content and entries to JSON file.
        """

        if len(self.loop_contents) != len(self.loop_entries):
            print(self.loop_contents)
            print(self.loop_entries)

            diff = abs(len(self.loop_contents) - len(self.loop_entries))

            for i in range(diff):
                id = len(self.loop_entries) + i
                print(id)
                self.loop_entries.append((id,''))

        data = []
        for entry, content in zip(self.loop_entries, self.loop_contents):
            loop_id, condition = entry
            data.append({
                "loop_id": loop_id,
                "condition": condition,
                "content": content
            })

        with open(self.json_file, 'w') as f:
            json.dump(data, f, indent=4)

        print(f"Successfully generated {self.json_file}")

    def run_symexec(self):
        """
        Run symexec command and process output.
        """
        command = [
            "build/symexec",
            f"--goal-file={self.goal_file}",
            f"--proof-auto-file={self.proof_auto_file}",
            f"--proof-manual-file={self.proof_manual_file}",
            f"--input-file={self.iter_file}"
        ]

        try:
            result = subprocess.run(
                command,
                cwd='../QCP/test',
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True
            )

            if result.stderr:
                print(result.stderr.strip())
                self.get_loop_entries(result.stderr)
                self.write_loops_to_json()

        except Exception as e:
            print(f"An error occurred: {e}")

    def init_execute(self):
        # Process input file
        self.loop_contents, self.sorted_indices,self.inner_flags = self.process_loop_file(self.input_file,self.output_file)

        for idx in self.sorted_indices:
            print(f"Loop {idx} : {'Inner' if self.inner_flags[idx] else 'Outer'}")
        print("Sorted indices:", self.sorted_indices)


    def execute(self):

        # Check and delete old files
        for file_path in [self.goal_file, self.proof_auto_file, self.proof_manual_file]:
            self.delete_file_if_exists(file_path)

        # Run symexec command
        self.run_symexec()

    
    def update_loop_content(self,code,new_loop_content,ridx):
        # Split code into single character list

        code_list = list(code)
        
        # Find all for or while loop positions
        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        matches = list(re.finditer(loop_pattern, code))
       
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
        updated_code = (
            ''.join(code_list[:at_index]) +  # Part before loop
            new_loop_content +                   # Replaced loop content
            ''.join(code_list[end_index:])   # Part after loop
        )
            
        # Rejoin character list into string
        return updated_code

    


# def main():
#   # Create parser
#     parser = argparse.ArgumentParser(description="Read file_name from command-line arguments.")
#     parser.add_argument('file_name', type=str, help="The name of the file without extension")

#   # Parse arguments
#     args = parser.parse_args()

#   # Create LoopProcessor object and execute
#     processor = LoopProcessor(args.file_name)
#     processor.init_execute()
#     processor.execute()


# if __name__ == "__main__":
#     main()