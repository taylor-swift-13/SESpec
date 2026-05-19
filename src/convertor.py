from __future__ import annotations

import openai
import re
from Utils.main_class import *
from config import LLMConfig
from collections import Counter
from llm import *
 

class SpecificationConvertor:

    def __init__(self, function_info: FunctionInfo = None, llm_config: LLMConfig = None):
        self.function_info = function_info
        # When no llm_config is supplied (legacy callers), fall back to defaults.
        # All in-pipeline callers should pass the user-selected llm_config so
        # that LLM calls inside specgen_annotations/assign_annotations actually
        # use the requested model instead of the dataclass default.
        self.llm_config = llm_config if llm_config is not None else LLMConfig()
        self.post_map = self.create_post_map()
        self.z3_map = self.create_z3_map()
        self.inv_map =self.create_inv_map()

       
        
        
    def optimize_acsl(self,acsl_code):
    
        ensures_pattern = r'ensures\s+(.+?);'
        all_ensures = re.findall(ensures_pattern, acsl_code, re.DOTALL)

        if not all_ensures:
            return acsl_code 

        post_conditions = []
        ensures_parts = []
        for stmt in all_ensures:
            if '==>' in stmt:
                pre, post = stmt.split('==>', 1)
                
                pre_cleaned = pre.strip()
                post_cleaned = post.strip()
                ensures_parts.append({'original': stmt, 'pre': pre_cleaned, 'post': post_cleaned})
                
                post_conditions.extend(
                    [expr.strip() for expr in re.split(r'\s*&&\s*', post_cleaned)]
                )
            else:
                
                ensures_parts.append({'original': stmt, 'pre': None, 'post': stmt.strip()})
                post_conditions.extend(
                    [expr.strip() for expr in re.split(r'\s*&&\s*', stmt.strip())]
                )

        
        if not post_conditions:
            return acsl_code

        expr_counts = Counter(post_conditions)
        
        common_exprs = [
            expr for expr, count in expr_counts.items() if count == len(all_ensures)
        ]

        
        if not common_exprs:
            return acsl_code

        
        common_ensures = (
            f"ensures {' && '.join(common_exprs)};" if common_exprs else ""
        )
        
        
        modified_ensures_stmts = []
        for part in ensures_parts:
            
            modified_post = part['post']
            for expr in common_exprs:
                
                modified_post = re.sub(
                    r'^\s*' + re.escape(expr) + r'\s*&&\s*',
                    '',
                    modified_post,
                    count=1,
                )
                modified_post = re.sub(
                    r'\s*&&\s*' + re.escape(expr) + r'\s*$',
                    '',
                    modified_post,
                    count=1,
                )
                modified_post = re.sub(
                    r'\s*&&\s*' + re.escape(expr) + r'\s*&&\s*',
                    ' && ',
                    modified_post,
                    count=1,
                )
                modified_post = re.sub(r'^\s*' + re.escape(expr) + r'\s*$', '', modified_post, count=1)
                modified_post = modified_post.strip()
            
            
            if part['pre'] is not None:
                if modified_post:
                    modified_stmt = f"ensures {part['pre']} ==> {modified_post};"
                else:
                    
                    modified_stmt = f"ensures {part['pre']} ==> ;"
            else:
                modified_stmt = f"ensures {modified_post};"

            modified_ensures_stmts.append(modified_stmt)

        
        result_code = common_ensures + "\n\n" + "\n".join(modified_ensures_stmts)
        return result_code


    def extract_var_map_from_file(self,condition):

        # 根据 || 分割条件表达式
        # sub_conditions = [s.strip().strip('()') for s in condition.split("||")]

        def remove_outer_parentheses(s):
            s = s.strip()
            if len(s) >=2 and s[0] == '(' and s[-1] == ')':
                return s[1:-1]
            else:
                return s

        def split_conditions(condition):
            # 按括号外的 "||" 分割
            sub_conditions = re.split(r'\|\|(?![^(]*\))', condition)
            # 去掉每部分的首尾空格和括号
            return [remove_outer_parentheses(s) for s in sub_conditions]
        
        sub_conditions = split_conditions(condition)

        # 存储所有 var_map 的列表
        var_maps = []
        path_conds = []
        results = []

        def split_path_and_state(expression):

            if '&&' not in expression:

                if '__return' not in expression:
                    # state
                    path = None
                    result = None
                    state = expression.strip()
                else :
                    # result
                    path = None
                    result = expression.strip()
                    state = None

            else: 
                parts = expression.split('&&')
                
                if '__return' not in parts[-1]:
                    state = parts[-1]
                    path_parts = []
                    result_parts = []
                    path_flag = 1
                    for part in parts [:-1]:
                        if '__return' not in part and path_flag:
                            path_parts.append(part)
                        else:
                            path_flag = 0
                            result_parts.append(part)
                    
                    if path_parts == []:
                        path =None
                    else:
                        path = '&&'.join(path_parts)

                    if result_parts == []:
                        result =None
                    else:
                        result = '&&'.join(result_parts)
                
                else:
                    state = None
                    path_parts = []
                    result_parts = []
                    path_flag = 1
                    for part in parts:
                        if '__return' not in part and path_flag:
                            path_parts.append(part)
                        else:
                            path_flag = 0
                            result_parts.append(part)
                    
                    if path_parts == []:
                        path =None
                    else:
                        path = '&&'.join(path_parts)

                    if result_parts == []:
                        result =None
                    else:
                        result = '&&'.join(result_parts)

            return path, state,result
            
 
        
        def fix_brackets(s: str) -> str:
            stack = []
            to_remove = set()  # 记录需要Deleted的多余括号位置
            bracket_pairs = {')': '(', ']': '[', '}': '{'}
            
            # 第一次遍历：检查括号合法性并标记多余括号
            for i, char in enumerate(s):
                if char in bracket_pairs.values():  # 左括号入栈
                    stack.append((char, i))
                elif char in bracket_pairs:        # 右括号尝试匹配
                    if stack and stack[-1][0] == bracket_pairs[char]:
                        stack.pop()  # 匹配成功，弹出左括号
                    else:
                        to_remove.add(i)  # 多余右括号，标记Deleted
            
            # 标记未匹配的左括号（需要补右括号）
            missing_right = [i for _, i in stack]
            
            # 第二次遍历：修复字符串
            result = []
            for i, char in enumerate(s):
                if i not in to_remove:  # Kept非多余括号
                    result.append(char)
            
            # 补全缺失的右括号（按左括号出现顺序反向补全）
            for i in sorted(missing_right, reverse=True):
                # 在左括号后插入对应的右括号
                pos = i + 1
                right_bracket = {v: k for k, v in bracket_pairs.items()}[s[i]]
                result.insert(pos, right_bracket)
            
            return ''.join(result).strip()

        def parse_expressions(s):

            # (a==0)*(b==(1*2))*(...)
            # 不在 () 里 * 是 分隔符，在 () 里的是 乘
            # a == 1 * 5 需要特判
            
            if s.count('==') == 1:
                s = f'({s})'
            var_map = {}
            remaining = s.strip()
            stack = []
            expr_start = 0
            i = 0
            n = len(remaining)
            
            while i < n:
                char = remaining[i]
                
                # 处理括号层级
                if char == '(':
                    stack.append(i)
                elif char == ')':
                    if stack:
                        stack.pop()
                
                # 遇到逻辑运算符且不在括号内时，分割表达式
                if i < n-1 and remaining[i:i+2] in ('&&', '* ') and not stack:
                    # 提取当前表达式
                    expr = remaining[expr_start:i].strip()
                    # 解析表达式中的键值对
                    eq_pos = expr.find('==')
                    if eq_pos != -1:

                        var = expr[:eq_pos].strip(' ()')
                        
                        
                        value = fix_brackets(expr[eq_pos+2:])
              

                        var_map[var] = value
                    expr_start = i + 2
                    i += 1  # Skip运算符的第二个字符
                
                i += 1
            
            # 处理最后一个表达式
            expr = remaining[expr_start:].strip()
            eq_pos = expr.find('==')
            if eq_pos != -1:

                var =expr[:eq_pos].strip(' ()')
    
                value = fix_brackets(expr[eq_pos+2:])
       
                var_map[var] = value
                
            return var_map
        
       
        
        for sub_condition in sub_conditions:

                path,state,result = split_path_and_state(sub_condition)
                
                path_cond = path
                path_conds.append(path_cond)
                
                var_map = None  # 为每个子条件创建一个新的 var_map

                if state:
                    var_map = parse_expressions(state)

                var_maps.append(var_map)  # 将 var_map 添加到列表中

                results.append(result)


        

        return var_maps,path_conds,results

    # def create_require_str(self) -> str:
    #     """
    #     生成需要插入到临时.c文件的precondition
    #     """
    #     require_list = []
    #     ptr_lists =[]
    #     syntax_str =''
       
    #     def parse_parameters_assertion(parameter_list:[List[Parameter]],require_list:list[str],ptr_lists:list[list[str]],syntax_str:str):
    #         if not parameter_list:
    #             return None
            
    #         local_ptr_list = []
            
    #         for parameter in parameter_list:

    #             if parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
    #                 require_list.append(rf'\valid({syntax_str}{parameter.name})')
    #                 local_ptr_list.append(f'{syntax_str}{parameter.name}')

    #                 old_syntax_str = syntax_str
                                   
                    
    #                 if parameter.ptr_depth == 1:
    #                     access_name = parameter.name
    #                 else:
    #                     access = '*' * (parameter.ptr_depth - 1)
    #                     access_name =f'({access}{parameter.name})'

    #                 syntax_str = syntax_str + access_name + '->'


    #                 ptr_list = parse_parameters_assertion(parameter.type.parameter_list, require_list ,ptr_lists, syntax_str)
    #                 ptr_lists.append(ptr_list)

    #                 syntax_str = old_syntax_str
    #                 continue

    #             # 是一个指针,非结构体,数组参数
    #             if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
    #                 #分别添加数组的数组符号,地址,长度
    #                 next_parameter = parameter_list[parameter_list.index(parameter) + 1]

    #                 require_list.append(rf'\valid({syntax_str}{parameter.name}+(0..{next_parameter}))')
    #                 local_ptr_list.append(f'{syntax_str}{parameter.name}+(0..{next_parameter})')
                    
    #                 if parameter.array_length == 'INT_MAX':
                        
    #                     require_list.append(f'{next_parameter.name} > 0 && {next_parameter.name} < 100')

    #                 continue

    #             # 是一个非指针,非结构体,数组参数
    #             if not parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                   
    #                 require_list.append(rf'\valid({syntax_str}{parameter.name}+ (0..{parameter.array_length}))')
    #                 local_ptr_list.append(f'{syntax_str}{parameter.name}+(0..{parameter.array_length})')

    #                 continue


    #             if not parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                   
    #                 old_syntax_str = syntax_str

    #                 syntax_str = syntax_str + parameter.name + '.'
    #                 ptr_list =parse_parameters_assertion(parameter.type.parameter_list,require_list,ptr_lists, syntax_str)
    #                 ptr_lists.append(ptr_list)
    #                 syntax_str = old_syntax_str
    #                 continue
                

    #             # 是一个指针,非结构体,非数组参数
    #             if parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
    #                 #分别添加数组的数组符号,地址,长度
                    
    #                 require_list.append(rf'\valid({syntax_str}{parameter.name})')
    #                 local_ptr_list.append(f'{syntax_str}{parameter.name}')
                    
    #                 continue
                
    #         return local_ptr_list
                
        
    #     parse_parameters_assertion(self.function_info.parameter_list,require_list,ptr_lists,syntax_str) 

        
    #     if require_list == []:
    #         require_str = None
                
    #     else:
    #         require = " && ".join(require_list)
    #         require_str = f' requires {require} ;'   
            
    #         for ptr_list in ptr_lists:
    #             if ptr_list != [] and len(ptr_list) > 1:
    #                 ptr_str = ','.join(ptr_list)
    #                 require_str += f'\n requires \separated({ptr_str}) ;'
            
    #     return require_str

    def create_require_str(self) -> str:
        require_list = []
        ptr_list =[]
        syntax_str =''
       
        def parse_parameters_assertion(parameter_list:[List[Parameter]],require_list:list[str],ptr_list:list[str],syntax_str:str):
            if not parameter_list:
                return None
            

    
            for parameter in parameter_list:

                if parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                    require_list.append(rf'\valid({syntax_str}{parameter.name})')
                    ptr_list.append(f'{syntax_str}{parameter.name}')

                    old_syntax_str = syntax_str
                                   
                    
                    if parameter.ptr_depth == 1:
                        access_name = parameter.name
                    else:
                        access = '*' * (parameter.ptr_depth - 1)
                        access_name =f'({access}{parameter.name})'

                    syntax_str = syntax_str + access_name + '->'
                    
                    parse_parameters_assertion(parameter.type.parameter_list, require_list ,ptr_list, syntax_str)
                    
                    syntax_str = old_syntax_str
                    continue

                # 是一个指针,非结构体,数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    #分别添加数组的数组符号,地址,长度
                    idx = parameter_list.index(parameter)
                    if idx + 1 < len(parameter_list):
                        next_parameter = parameter_list[idx + 1]
                        require_list.append(rf'\valid({syntax_str}{parameter.name}+(0..{next_parameter.name} - 1))')
                        ptr_list.append(f'{syntax_str}{parameter.name}+(0..{next_parameter.name} - 1)')
                        if parameter.array_length == 'INT_MAX':
                            require_list.append(f'{next_parameter.name} > 0 && {next_parameter.name} < 100')
                    else:
                        require_list.append(rf'\valid({syntax_str}{parameter.name}+(0..100))')
                        ptr_list.append(f'{syntax_str}{parameter.name}+(0..100)')

                    continue

                # 是一个非指针,非结构体,数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                   
                    # require_list.append(rf'\valid({syntax_str}{parameter.name}+ (0..{parameter.array_length}))')
                    # ptr_list.append(f'{syntax_str}{parameter.name}+(0..{parameter.array_length})')

                    continue


                if not parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                   
                    old_syntax_str = syntax_str

                    syntax_str = syntax_str + parameter.name + '.'
                    parse_parameters_assertion(parameter.type.parameter_list,require_list,ptr_list, syntax_str)
                    syntax_str = old_syntax_str
                    continue
                


                # 是一个指针,非结构体,非数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    #分别添加数组的数组符号,地址,长度
                    
                    require_list.append(rf'\valid({syntax_str}{parameter.name})')
                    ptr_list.append(f'{syntax_str}{parameter.name}')
                    
                    continue
        
            if require_list == []:
                require_str = None
            else:
                require = " && ".join(require_list)
                require_str = f' requires {require} ;'   
            
            if ptr_list != [] and len(ptr_list) > 1:
                ptr_str = ','.join(ptr_list)
                require_str += f'\n requires \separated({ptr_str}) ;'
            
            return require_str
        
        return parse_parameters_assertion(self.function_info.parameter_list,require_list,ptr_list,syntax_str) 
        


    def create_exists_str(self) -> str:
        """
        生成需要插入到临时.c文件的precondition
        """
        require_list = []
        exists_list =[]
        syntax_str = ''
        value_str = ''
        def parse_parameters_assertion(parameter_list:[List[Parameter]],require_list:list[str], exists_list:list[str] , syntax_str:str, value_str:str):
            if not parameter_list:
                return None
            
            for parameter in parameter_list:

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
                    
                    parse_parameters_assertion(parameter.type.parameter_list, require_list ,exists_list, syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue


                # 是一个指针,非结构体,非数组参数
                #目前作为数组处理,等待后续使用clang进行分析再改进
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    continue
        

                # 是一个指针,非结构体,数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    #分别添加数组的数组符号,地址,长度
                    if parameter.array_length == 'INT_MAX':
                        idx = parameter_list.index(parameter)
                        exists_list.append(f'{value_str}{parameter.name}_l')
                        if idx + 1 < len(parameter_list):
                            next_parameter = parameter_list[idx + 1]
                            require_list.append(f'store_int_array({syntax_str}{parameter.name}, {next_parameter.name}, {value_str}{parameter.name}_l)')
                            require_list.append(f'{next_parameter.name} > 0 && {next_parameter.name} < 100')
                        else:
                            require_list.append(f'store_int_array({syntax_str}{parameter.name}, 100, {value_str}{parameter.name}_l)')
                    else:
                        require_list.extend([f'store_int_array({syntax_str}{parameter.name},{value_str}{parameter.array_length}, {value_str}{parameter.name}_l)',
                                            ])
                        exists_list.append(f'{value_str}{parameter.name}_l')

                    continue

                # 是一个非指针,结构体,非数组参数
                if not parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                   
                    old_syntax_str = syntax_str
                    old_value_str = value_str
                

                    syntax_str = syntax_str + parameter.name + '.'
                    value_str = value_str + parameter.name + '_'
                    # 进入结构体的参数列表进行递归处理;
                    parse_parameters_assertion(parameter.type.parameter_list,require_list,exists_list, syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue

                #目前只默认为intType的数组
                # 是一个非指针,非结构体,数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    require_list.append(f'store_int_array({syntax_str}{parameter.name}, {parameter.array_length}, {value_str}{parameter.name}_l)')
                    exists_list.append(f'{value_str}{parameter.name}_l')
                    continue

                # 是一个非指针,非结构体,非数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    continue

                else:
                    raise ValueError(f'遇到了意料之外的数据Type:{syntax_str}{parameter.name}')

            
            if exists_list == []:
                return None

            exists_str = f''' exists  {' '.join(exists_list)},    
    {' && '.join(require_list)} &&
    '''     
            
            return exists_str
        
        return parse_parameters_assertion(self.function_info.parameter_list,require_list, exists_list, syntax_str, value_str) 
    
    def create_z3_map(self):
        vars_map = []
        value_str = ''
        syntax_str = ''
        vars_map.append(('\\result',r'result'))
        def parse_parameters_assertion(parameter_list:[List[Parameter]],vars_map, syntax_str :str,value_str:str):
            if not parameter_list:
                return []
            
            for parameter in parameter_list:

                if parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:


                    vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))

                    
                    old_syntax_str = syntax_str
                    old_value_str = value_str
                    
                    if parameter.ptr_depth == 1:
                        access_name = parameter.name
                    else:
                        access = '*' * (parameter.ptr_depth - 1)
                        access_name =f'({access}{parameter.name})'


                    syntax_str = syntax_str + access_name + '->'
                    value_str = value_str + access_name + '_'
                    # 进入结构体的参数列表进行递归处理;
                    parse_parameters_assertion(parameter.type.parameter_list, vars_map, syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue


                # 是一个指针,非结构体,非数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    #分别添加数组的数组符号,地址,长度
                    access = '*' * (parameter.ptr_depth)

                    vars_map.append((rf'{access}\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}_v'))
                    vars_map.append((rf'\old({access}{syntax_str}{parameter.name})',f'{value_str}{parameter.name}_old_v'))
                    vars_map.append((rf'{access}{syntax_str}{parameter.name}',f'{value_str}{parameter.name}_v'))
                    
                    if value_str != '' and syntax_str != '':

                        vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))
                        vars_map.append((rf'\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}'))

                    
                    continue
        

                # 是一个指针,非结构体,数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    #分别添加数组的数组符号,地址,长度
                    vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))
                    vars_map.append((rf'\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}'))
                   
                    if parameter.array_length != 'INT_MAX':
                        for i in range(parameter.array_length if isinstance(parameter.array_length, int) else 100):
                            vars_map.append((rf'\old({syntax_str}{parameter.name}[{i}])',f'old_{value_str}{parameter.name}_{i}'))
                            vars_map.append((rf'{syntax_str}{parameter.name}[{i}]',f'{value_str}{parameter.name}_{i}'))
                    else:
                         for i in range(100):
                            vars_map.append((rf'\old({syntax_str}{parameter.name}[{i}])',f'old_{value_str}{parameter.name}_{i}'))
                            vars_map.append((rf'{syntax_str}{parameter.name}[{i}]',f'{value_str}{parameter.name}_{i}'))
                    continue

                # 是一个非指针,结构体,非数组参数
                if not parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                    

                    vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))
                    vars_map.append((rf'\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}'))

                    old_syntax_str = syntax_str
                    old_value_str = value_str


                    syntax_str = syntax_str +  parameter.name + '.'
                    value_str = value_str + parameter.name + '_'


                    # 进入结构体的参数列表进行递归处理;
                    parse_parameters_assertion(parameter.type.parameter_list, vars_map,  syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue

                #目前只默认为intType的数组
                # 是一个非指针,非结构体,数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                   
                    vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))
                    vars_map.append((rf'\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}'))
                  
                    
                    for i in range(parameter.array_length if isinstance(parameter.array_length, int) else 100):
                        vars_map.append((rf'\old({syntax_str}{parameter.name}[{i}])',f'old_{value_str}{parameter.name}_{i}'))
                        vars_map.append((f'{syntax_str}{parameter.name}[{i}]',f'{value_str}{parameter.name}_{i}'))
                    
                    continue

                # 是一个非指针,非结构体,非数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    if value_str != '' and syntax_str != '':
                       
                        vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))
                        vars_map.append((rf'\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}'))


                    else:

                        vars_map.append((f'{syntax_str}{parameter.name}',f'{value_str}{parameter.name}'))
                        vars_map.append((rf'\old({syntax_str}{parameter.name})',f'old_{value_str}{parameter.name}'))
                    
                    continue

                else:
                    raise ValueError(f'遇到了意料之外的数据Type:{syntax_str}{parameter.name}')

            
           
            return vars_map
        
        return parse_parameters_assertion(self.function_info.parameter_list,vars_map, syntax_str ,value_str) 

    def create_post_map(self):
        vars_list =[]
        value_str = ''
        syntax_str = ''
        def parse_parameters_assertion(parameter_list:[List[Parameter]],vars_list, syntax_str :str,value_str:str):
            if not parameter_list:
                return []
            
            for parameter in parameter_list:

                if parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:


                   
                    vars_list.append((f'{value_str}{parameter.name}','110',f'{syntax_str}{parameter.name}'))

                    
                    old_syntax_str = syntax_str
                    old_value_str = value_str
                    
                    if parameter.ptr_depth == 1:
                        access_name = parameter.name
                    else:
                        access = '*' * (parameter.ptr_depth - 1)
                        access_name =f'({access}{parameter.name})'


                    syntax_str = syntax_str + access_name + '->'
                    value_str = value_str + access_name + '_'
                    # 进入结构体的参数列表进行递归处理;
                    parse_parameters_assertion(parameter.type.parameter_list, vars_list, syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue


                # 是一个指针,非结构体,非数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    #分别添加数组的数组符号,地址,长度
                    access = '*' * (parameter.ptr_depth)


                    vars_list.append((f'{value_str}{parameter.name}_v','100',rf'\\old({access}{syntax_str}{parameter.name})'))
                    
                    if value_str != '' and syntax_str != '':
                        
                        vars_list.append((f'{value_str}{parameter.name}','100',rf'\\old({syntax_str}{parameter.name})'))
                    
                    continue
        

                # 是一个指针,非结构体,数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    #分别添加数组的数组符号,地址,长度
                    vars_list.append((f'{value_str}{parameter.name}','101',f'{syntax_str}{parameter.name}'))

                   
                    if parameter.array_length != 'INT_MAX':
                        for i in range(parameter.array_length if isinstance(parameter.array_length, int) else 100):
                            vars_list.append((f'{value_str}{parameter.name}_{i}','100',rf'\\old({syntax_str}{parameter.name}[{i}])'))

                          
                    continue

                # 是一个非指针,结构体,非数组参数
                if not parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                    vars_list.append((f'{value_str}{parameter.name}','010',f'{syntax_str}{parameter.name}'))

                    old_syntax_str = syntax_str
                    old_value_str = value_str


                    syntax_str = syntax_str +  parameter.name + '.'
                    value_str = value_str + parameter.name + '_'


                    # 进入结构体的参数列表进行递归处理;
                    parse_parameters_assertion(parameter.type.parameter_list, vars_list,  syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue

                #目前只默认为intType的数组
                # 是一个非指针,非结构体,数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    vars_list.append((f'{value_str}{parameter.name}','001',f'{syntax_str}{parameter.name}'))

                    length = parameter.array_length if isinstance(parameter.array_length, int) else 100
                    for i in range(length):
                        vars_list.append((f'{value_str}{parameter.name}_{i}','100',rf'\\old({syntax_str}{parameter.name}[{i}])'))

                    continue

                # 是一个非指针,非结构体,非数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    if value_str != '' and syntax_str != '':
                        vars_list.append((f'{value_str}{parameter.name}','100',rf'\\old({syntax_str}{parameter.name})'))

                    else:
                        vars_list.append((f'{value_str}{parameter.name}','000',f'{syntax_str}{parameter.name}'))      
                    
                    continue

                else:
                    raise ValueError(f'遇到了意料之外的数据Type:{syntax_str}{parameter.name}')

            
           
            return vars_list
        
        return parse_parameters_assertion(self.function_info.parameter_list,vars_list, syntax_str ,value_str) 


    def create_inv_map(self):
        vars_list =[]
        value_str = ''
        syntax_str = ''
        def parse_parameters_assertion(parameter_list:[List[Parameter]],vars_list, syntax_str :str,value_str:str):
            
            if not parameter_list:
                return []
            
            for parameter in parameter_list:

                if parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:

                   
                    vars_list.append((f'{value_str}{parameter.name}','110',f'{syntax_str}{parameter.name}'))

                    
                    old_syntax_str = syntax_str
                    old_value_str = value_str
                    
                    if parameter.ptr_depth == 1:
                        access_name = parameter.name
                    else:
                        access = '*' * (parameter.ptr_depth - 1)
                        access_name =f'({access}{parameter.name})'


                    syntax_str = syntax_str + access_name + '->'
                    value_str = value_str + access_name + '_'
                    # 进入结构体的参数列表进行递归处理;
                    parse_parameters_assertion(parameter.type.parameter_list, vars_list, syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue


                # 是一个指针,非结构体,非数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    #分别添加数组的数组符号,地址,长度
                    access = '*' * (parameter.ptr_depth)


                    vars_list.append((f'{value_str}{parameter.name}_v','100',rf'\\at({access}{syntax_str}{parameter.name},Pre)'))
                    
                    if value_str != '' and syntax_str != '':
                        
                        vars_list.append((f'{value_str}{parameter.name}','100',rf'\\at({syntax_str}{parameter.name},Pre)'))
                    
                    continue
        

                # 是一个指针,非结构体,数组参数
                if parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    #分别添加数组的数组符号,地址,长度
                    vars_list.append((f'{value_str}{parameter.name}','101',f'{syntax_str}{parameter.name}'))

                   
                    if parameter.array_length != 'INT_MAX':
                        for i in range(parameter.array_length if isinstance(parameter.array_length, int) else 100):
                            vars_list.append((f'{value_str}{parameter.name}_{i}','100',rf'\\at({syntax_str}{parameter.name}[{i}],Pre)'))

                          
                    continue

                # 是一个非指针,结构体,非数组参数
                if not parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                    vars_list.append((f'{value_str}{parameter.name}','010',f'{syntax_str}{parameter.name}'))

                    old_syntax_str = syntax_str
                    old_value_str = value_str


                    syntax_str = syntax_str + parameter.name + '.'
                    value_str = value_str + parameter.name + '_'


                    # 进入结构体的参数列表进行递归处理;
                    parse_parameters_assertion(parameter.type.parameter_list, vars_list,  syntax_str, value_str)
                    
                    syntax_str = old_syntax_str
                    value_str = old_value_str
                    continue

                #目前只默认为intType的数组
                # 是一个非指针,非结构体,数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length != -1:
                    vars_list.append((f'{value_str}{parameter.name}','001',f'{syntax_str}{parameter.name}'))

                    for i in range(parameter.array_length if isinstance(parameter.array_length, int) else 100):
                        vars_list.append((f'{value_str}{parameter.name}_{i}','100',rf'\\at({syntax_str}{parameter.name}[{i}],Pre)'))

                    continue

                # 是一个非指针,非结构体,非数组参数
                if not parameter.is_ptr and not parameter.is_struct and parameter.array_length == -1:
                    if value_str != '' and syntax_str != '':
                        vars_list.append((f'{value_str}{parameter.name}','100',rf'\\at({syntax_str}{parameter.name},Pre)'))

                    else:
                        vars_list.append((f'{value_str}{parameter.name}','000',f'{syntax_str}{parameter.name}'))      
                    
                    continue

                else:
                    raise ValueError(f'遇到了意料之外的数据Type:{syntax_str}{parameter.name}')

            
           
            return vars_list
        
        return parse_parameters_assertion(self.function_info.parameter_list,vars_list, syntax_str ,value_str) 

    @staticmethod
    def _split_acsl_params(params: str) -> list[str]:
        params = params.strip()
        if not params or params == "void":
            return []

        out = []
        depth = 0
        start = 0
        for i, ch in enumerate(params):
            if ch in "([{":
                depth += 1
            elif ch in ")]}":
                depth = max(0, depth - 1)
            elif ch == "," and depth == 0:
                part = params[start:i].strip()
                if part:
                    out.append(part)
                start = i + 1
        tail = params[start:].strip()
        if tail:
            out.append(tail)
        return out

    @staticmethod
    def _qcp_return_type(kind: str, return_type: str | None) -> str:
        if kind == "predicate":
            return "Prop"
        ret = (return_type or "").strip().lower()
        if ret == "boolean":
            return "Prop"
        return "Z"

    @classmethod
    def _qcp_extern_from_acsl_signature(
        cls,
        kind: str,
        return_type: str | None,
        name: str,
        params: str,
    ) -> str:
        arg_count = len(cls._split_acsl_params(params))
        ret_type = cls._qcp_return_type(kind, return_type)
        type_expr = " -> ".join(["Z"] * arg_count + [ret_type]) if arg_count else ret_type
        return f"/*@ Extern Coq ({name} : {type_expr}) */"

    @classmethod
    def acsl_helpers_to_qcp_externs(cls, acsl_code: str) -> list[str]:
        """Infer QCP extern declarations for ACSL predicate/logic helpers."""
        decls = []
        seen = set()

        def add(decl: str) -> None:
            decl = re.sub(r"\s+", " ", decl.strip())
            if decl and decl not in seen:
                seen.add(decl)
                decls.append(decl)

        annotation_text = "\n".join(
            block.group(1)
            for block in re.finditer(r"/\*@([\s\S]*?)\*/", acsl_code or "")
        )
        signature_re = re.compile(
            r"\b(?:(predicate)|logic\s+(integer|int|boolean))\s+"
            r"([A-Za-z_][A-Za-z0-9_]*)"
            r"(?:\s*\{[^}]*\})?\s*"
            r"\(([^)]*)\)\s*=",
            re.MULTILINE,
        )
        for match in signature_re.finditer(annotation_text):
            if match.group(1):
                kind = "predicate"
                return_type = None
            else:
                kind = "logic"
                return_type = match.group(2)
            add(cls._qcp_extern_from_acsl_signature(kind, return_type, match.group(3), match.group(4)))

        return decls

    @staticmethod
    def insert_qcp_externs(qcp_code: str, decls: list[str]) -> str:
        missing = [decl for decl in decls if decl and decl not in qcp_code]
        if not missing:
            return qcp_code

        insert_text = "\n".join(missing) + "\n\n"
        matches = list(re.finditer(r"/\*@\s*(?:Extern|Import)\s+Coq[\s\S]*?\*/\s*", qcp_code))
        if matches:
            pos = matches[-1].end()
            return qcp_code[:pos] + insert_text + qcp_code[pos:]

        include_matches = list(re.finditer(r"^\s*#\s*include\s+\"[^\"]+\"\s*$", qcp_code, flags=re.MULTILINE))
        if include_matches:
            pos = include_matches[-1].end()
            return qcp_code[:pos] + "\n\n" + insert_text + qcp_code[pos:]

        return insert_text + qcp_code


    def convert_annotations(self, annotations):

        if len(self.inv_map) > 0:
            sorted_inv_map = sorted(self.inv_map, key=lambda x: len(x[2]), reverse=True)
        
          
            for item in sorted_inv_map:
                old_expr = item[2]
                new_expr = item[0]
            
               
                old_expr_unescaped = old_expr.replace('\\\\', '\\')
                annotations = annotations.replace(old_expr_unescaped, new_expr)
            
              

        

        if self.function_info:
            exists_str = self.create_exists_str()
            
        else:
            exists_str = None


        index = annotations.find("*/")
        if index == -1:
            # Malformed / empty annotations (e.g. LLM returned nothing
            # after an API connection error). Nothing to convert.
            return annotations
        before = annotations[:index + 2]
        after = annotations[index + 2:]

        def strip_comments(text: str) -> str:
            text = re.sub(r"/\*[^@][\s\S]*?\*/", "", text)
            text = re.sub(r"//.*", "", text)
            return text

        def clause_is_complete(text: str) -> bool:
            stripped = text.strip()
            if not stripped.endswith(";"):
                return False
            body = stripped[:-1].strip()
            quantifier_only = re.fullmatch(
                r"\\(?:forall|exists)\s+(?:int|integer)\s+[^;]+",
                body,
            )
            return quantifier_only is None

        def extract_loop_invariants(block: str) -> list[str]:
            content = block.strip()
            if content.startswith("/*@"):
                content = content[3:]
            if content.endswith("*/"):
                content = content[:-2]
            content = strip_comments(content)

            invariants = []
            current = []
            collecting = False
            for raw_line in content.splitlines():
                line = raw_line.strip()
                if not line:
                    continue
                if line.startswith("*"):
                    line = line[1:].strip()
                if re.match(r"^loop\s+invariant\b", line):
                    if current:
                        invariants.append(" ".join(current).strip().rstrip(";"))
                    current = [re.sub(r"^loop\s+invariant\b", "", line, count=1).strip()]
                    collecting = True
                    if clause_is_complete(current[0]):
                        invariants.append(current[0].strip().rstrip(";"))
                        current = []
                        collecting = False
                    continue
                if re.match(r"^loop\s+(assigns|variant)\b", line):
                    if current:
                        invariants.append(" ".join(current).strip().rstrip(";"))
                    current = []
                    collecting = False
                    continue
                if collecting:
                    current.append(line)
                    if clause_is_complete(" ".join(current)):
                        invariants.append(" ".join(current).strip().rstrip(";"))
                        current = []
                        collecting = False
            if current:
                invariants.append(" ".join(current).strip().rstrip(";"))
            return [inv for inv in invariants if inv]

        def array_param_map() -> dict[str, str]:
            mapping = {}
            if not self.function_info:
                return mapping

            def visit(parameters, syntax_prefix="", value_prefix=""):
                if not parameters:
                    return
                for parameter in parameters:
                    if parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                        access_name = parameter.name if parameter.ptr_depth == 1 else f"({'*' * (parameter.ptr_depth - 1)}{parameter.name})"
                        visit(parameter.type.parameter_list, syntax_prefix + access_name + "->", value_prefix + access_name + "_")
                    elif not parameter.is_ptr and parameter.is_struct and parameter.array_length == -1:
                        visit(parameter.type.parameter_list, syntax_prefix + parameter.name + ".", value_prefix + parameter.name + "_")
                    elif not parameter.is_struct and parameter.array_length != -1:
                        mapping[f"{syntax_prefix}{parameter.name}"] = f"{value_prefix}{parameter.name}_l"

            visit(self.function_info.parameter_list)
            return mapping

        def convert_quantifier(match):
            kind = match.group(1)
            variables = [
                var.strip()
                for var in match.group(2).split(",")
                if var.strip()
            ]
            prefix = "forall" if kind == "forall" else "exists"
            return " ".join(f"{prefix} ({var}:Z)," for var in variables)

        def expand_chained_relations(expr: str) -> str:
            atom = r"(?:[A-Za-z_][A-Za-z0-9_]*(?:\[[^\]]+\])?|[0-9]+)"
            pattern = re.compile(rf"\b({atom})\s*(<=|<)\s*({atom})\s*(<=|<)\s*({atom})\b")
            previous = None
            while previous != expr:
                previous = expr
                expr = pattern.sub(lambda m: f"{m.group(1)} {m.group(2)} {m.group(3)} && {m.group(3)} {m.group(4)} {m.group(5)}", expr)
            return expr

        def simplify_trivial_true(expr: str) -> str:
            expr = re.sub(r"\btrue\s*&&\s*", "", expr)
            expr = re.sub(r"\s*&&\s*\btrue\b", "", expr)
            expr = re.sub(r"\(\s*true\s*\)", "true", expr)
            return expr.strip()

        array_mapping = array_param_map()

        def convert_expr(expr: str) -> str:
            expr = expr.strip()
            expr = re.sub(r"^[A-Za-z_][A-Za-z0-9_]*\s*:\s*", "", expr)
            expr = re.sub(r"\\valid(?:_read)?\s*\([^)]*\)", "true", expr)
            expr = re.sub(r"\\separated\s*\([^)]*\)", "true", expr)
            expr = re.sub(r"\\at\(\s*([^,]+?)\s*,\s*Pre\s*\)", lambda m: f"{m.group(1).strip()}@pre", expr)
            expr = re.sub(r"\\(forall|exists)\s+(?:int|integer)\s+([^;]+);", convert_quantifier, expr)
            expr = expr.replace("==>", "=>")
            expr = expr.replace("\\true", "true").replace("\\false", "false")
            expr = expr.replace("\\null", "0").replace("NULL", "0")
            expr = expr.replace("(integer)", "").replace("(int)", "")
            for source, target in sorted(array_mapping.items(), key=lambda item: len(item[0]), reverse=True):
                expr = re.sub(rf"(?<![A-Za-z0-9_]){re.escape(source)}\s*\[", f"{target}[", expr)
            expr = expand_chained_relations(expr)
            expr = expr.replace(";", "")
            expr = re.sub(r"\s+", " ", expr)
            return simplify_trivial_true(expr)

        invariants = []
        for invariant in extract_loop_invariants(before):
            converted = convert_expr(invariant)
            if converted and converted != "true":
                invariants.append(f"({converted})")

        body_parts = []
        if exists_str:
            exists_part = exists_str.strip()
            if exists_part.endswith("&&"):
                exists_part = exists_part[:-2].rstrip()
            if exists_part:
                body_parts.append(exists_part)
        body_parts.extend(invariants if invariants else ["emp"])
        invariant = " &&\n    ".join(body_parts)

        before = f'''/*@ Inv
    {invariant}
    */
    ''' 

        return before+after
    

    def precondgen_annotations(self, code: str, examples: str = "") -> str:
        """LLM precondition generator for recursive data structure programs.
        Returns an ACSL block (predicates + requires) extracted from the
        single ```acsl fenced block the model must produce. Empty string on
        any failure / unparseable response — caller treats it as no-op.
        """
        with open("prompt/func/precondgen.txt", "r", encoding="utf-8") as fh:
            template = fh.read()
        prompt = template.format(code=code, examples=examples)

        llm = Chatbot(self.llm_config)
        try:
            response = llm.chat(prompt)
        except Exception as e:
            print(f"precondgen API call failed: {e}")
            return ""
        response = re.sub(r"<think>[\s\S]*?</think>", "", response, flags=re.DOTALL)
        response = re.sub(r">\s*Reasoning\s*[\s\S]*?(?=\n\n|$)", "", response, flags=re.IGNORECASE)
        # Pull the ACSL block — accept ```acsl, ```c, or any unlabeled fence.
        blocks = re.findall(r"```(?:acsl|c)?\s*([\s\S]*?)```", response)
        if not blocks:
            return ""
        # Concatenate every /*@ ... */ across all fenced blocks (model may use
        # one fence per declaration). Anything outside /*@ ... */ is dropped —
        # this is what protects us from a model that tries to echo the
        # function body.
        acsl_chunks = []
        for blk in blocks:
            acsl_chunks.extend(re.findall(r"/\*@[\s\S]*?\*/", blk))
        return "\n\n".join(acsl_chunks)


    def inconvert_requires(self, qcp_annotation: str) -> str:
        """Translate the QCP DSL `Require ...` clauses produced by
        `create_precondition` into an ACSL `requires` block.

        Mapping:
          Require emp                              → (empty)
          Require *p == p_v                        → requires \\valid(p);
          Require **p == p_v                       → requires \\valid(p);
          Require (p->f) == p_f_v                  → requires \\valid(p);
          Require store_int_array(a, n, a_l)       → requires \\valid(&a[0] + (0..n-1));
                                                     requires \\forall integer i; 0 <= i < n ==> 0 <= a[i] <= 100;
                                                     requires n >= 0;
          Require A && B                           → split into multiple requires
          numeric / boolean conjuncts (n>0 etc.)   → copied verbatim
        """
        if not qcp_annotation:
            return ""

        m = re.search(r"Require\s+(.+?)(?:\n|\*/)", qcp_annotation, re.DOTALL)
        if not m:
            return ""
        body = m.group(1).strip()
        if not body or body == "emp":
            return ""

        def split_top_level_and(s):
            parts, depth, start = [], 0, 0
            i = 0
            while i < len(s):
                c = s[i]
                if c in "([":
                    depth += 1
                elif c in ")]":
                    depth -= 1
                elif depth == 0 and s[i:i + 2] == "&&":
                    parts.append(s[start:i].strip())
                    i += 2
                    start = i
                    continue
                i += 1
            tail = s[start:].strip()
            if tail:
                parts.append(tail)
            return parts

        def strip_outer_parens(t):
            t = t.strip()
            while len(t) >= 2 and t[0] == '(' and t[-1] == ')':
                inner = t[1:-1]
                # only strip if the parens balance at the outermost level
                d, bal = 0, True
                for ch in inner:
                    if ch == '(':
                        d += 1
                    elif ch == ')':
                        d -= 1
                        if d < 0:
                            bal = False
                            break
                if not bal or d != 0:
                    break
                t = inner.strip()
            return t

        clauses = []
        seen = set()

        def add(c):
            c = c.strip().rstrip(';').strip()
            if c and c not in seen:
                seen.add(c)
                clauses.append(c)

        for raw in split_top_level_and(body):
            conj = strip_outer_parens(raw)
            if not conj:
                continue

            # store_int_array(a, n, a_l)  →  \valid(&a[0] + (0..n-1)) + n >= 0
            #
            # ACSL does NOT implicitly decay a C array to a pointer, so when
            # `a` is a struct array field (e.g. pIp->pkv : int[10]) writing
            # `\valid(a + (0..n-1))` triggers
            #   "no implicit conversion between a C array and a pointer.
            #    ... Ignoring logic specification of function ..."
            # Always emit `&a[0]` (or strip a leading `&` first if QCP already
            # produced `&pIp->pkv`) so the term is unambiguously `int*`.
            m2 = re.match(r"store_int_array\s*\(\s*([^,]+?)\s*,\s*([^,]+?)\s*,\s*[^\)]+\)\s*$", conj)
            if m2:
                arr, n = m2.group(1).strip(), m2.group(2).strip()
                array_value = arr[1:].strip() if arr.startswith("&") else arr
                arr_ptr = f"&{array_value}[0]"
                add(f"\\valid({arr_ptr} + (0..{n}-1))")
                add(f"\\forall integer i; 0 <= i < {n} ==> 0 <= {array_value}[i] <= 100")
                # Struct-field arrays (e.g. pIp->pkv): also require the parent
                # pointer to be valid so the field deref is well-defined.
                if "->" in array_value or "." in array_value:
                    root = re.match(r"^(\w+)", array_value)
                    if root:
                        add(f"\\valid({root.group(1)})")
                continue

            # <ptr-expr> == <ghost>_v   →   \valid(<root pointer>)
            m3 = re.match(r"^(.+?)\s*==\s*[A-Za-z_]\w*_v\s*$", conj)
            if m3:
                lhs = strip_outer_parens(m3.group(1))
                # *p, **p, ***p  →  \valid(p)
                stripped = lhs.lstrip('*').strip()
                stripped = strip_outer_parens(stripped)
                # p->f, p->f.g, p[i]   →  \valid(<root>)
                m4 = re.match(r"^(\w+)", stripped)
                if m4:
                    add(f"\\valid({m4.group(1)})")
                continue

            # QCP snapshot equalities for scalar fields/locals, e.g.
            # pIp->len == pIp_len. These introduce ghost names that are not
            # valid ACSL preconditions; memory validity is handled by the
            # corresponding pointer/array clauses. Keep ordinary x == y
            # constraints unless the RHS is exactly the flattened LHS name.
            m_snapshot = re.match(
                r"^([A-Za-z_]\w*(?:\s*(?:->|\.)\s*[A-Za-z_]\w*)*)\s*==\s*([A-Za-z_]\w*)$",
                conj,
            )
            if m_snapshot:
                lhs = re.sub(r"\s*(?:->|\.)\s*", "_", m_snapshot.group(1).strip())
                rhs = m_snapshot.group(2).strip()
                if rhs == lhs:
                    continue

            # Pure numeric / boolean — keep as-is
            add(conj)

        if not clauses:
            return ""
        return "/*@\n" + "\n".join(f"  requires {c};" for c in clauses) + "\n*/"


    def inconvert_annotations(self, annotations):


        def updated_condition_str(condition_str, predefined_vars):
            # 定义需要排除的关键字和量词
            EXCLUDED_KEYWORDS = {
                'exists', 'forall', '__return', 'store_int_array',
                'Size_of', 'signed', 'unsigned', 'int', 'Ez_val',
            }
            
            # 严格变量正则（匹配标准变量名）
            variable_pattern = r'(?<!\w)([a-zA-Z_]\w*)(?!\w)'
            
            # 提取所有候选变量
            candidates = set(re.findall(variable_pattern, condition_str))
            bound_vars = set()
            for m in re.finditer(r'\b(?:exists|forall)\s+([^,]+),', condition_str):
                bound_vars.update(
                    var.strip()
                    for var in m.group(1).split()
                    if var.strip()
                )
            
            # 多级过滤
            new_vars = []
            for var in candidates:
                if (var not in predefined_vars and               # 不在预定义集合中
                    var.lower() not in EXCLUDED_KEYWORDS and     # 不是关键字
                    var not in bound_vars and
                    not any(var.startswith(array_name) for array_name in array_names) and
                    not var.lstrip('-').isdigit() and            # 不是数字
                    (re.search(r'_\d+$', var) or 'retval_' in var) and
                    not any(op in var for op in {'+', '-', '*', '/', '%'})  # 不含操作符
                ):
                    new_vars.append(var)
            
            new_vars = sorted(new_vars)

            # 将新变量添加到exists声明中
            if not new_vars:
                    return condition_str
            
                # 在exists后追加新变量
            if 'exists' in condition_str:
                    # 提取already exists的变量
                    exists_part = condition_str.split('exists')[1].split(',')[0]
                    existing_vars = [v.strip() for v in exists_part.split() if v.strip()]
                
                    
                    # 添加新变量（不重复）
                    vars_to_add = [v for v in new_vars if v not in existing_vars]
                    if vars_to_add:
                        # 在第一个exists后插入新变量
                        parts = condition_str.split('exists', 1)
                        
                        updated_str = f"{parts[0]}exists {' '.join(vars_to_add)} {parts[1]}"
                    else:
                        updated_str = condition_str
            else:
                    updated_str = f"exists {' '.join(new_vars)}, {condition_str}"
                
            
            return updated_str


        post_map = self.post_map

        ensure = annotations.split('Ensure') [-1][:-2].strip()

        def split_top_level(expr: str, sep: str) -> list[str]:
            parts = []
            depth = 0
            start = 0
            i = 0
            while i < len(expr):
                ch = expr[i]
                if ch in "([":
                    depth += 1
                elif ch in ")]":
                    depth = max(0, depth - 1)
                elif depth == 0 and expr.startswith(sep, i):
                    part = expr[start:i].strip()
                    if part:
                        parts.append(part)
                    i += len(sep)
                    start = i
                    continue
                i += 1
            tail = expr[start:].strip()
            if tail:
                parts.append(tail)
            return parts

        def strip_outer_parens(expr: str) -> str:
            expr = expr.strip()
            while len(expr) >= 2 and expr[0] == "(" and expr[-1] == ")":
                depth = 0
                balanced = True
                for idx, ch in enumerate(expr):
                    if ch == "(":
                        depth += 1
                    elif ch == ")":
                        depth -= 1
                        if depth == 0 and idx != len(expr) - 1:
                            balanced = False
                            break
                        if depth < 0:
                            balanced = False
                            break
                if not balanced or depth != 0:
                    break
                expr = expr[1:-1].strip()
            return expr

        def normalize_pointer_offsets(text):
            if not text:
                return text
            size = r'(?:4|\(?\s*Size_of\s+signed\s+int\s*\)?)'
            text = re.sub(
                rf'(\b[A-Za-z_]\w*(?:\s*(?:->|\.)\s*[A-Za-z_]\w*)*)\s*\+\s*([A-Za-z_]\w*)\s*\*\s*{size}',
                r'\1 + \2',
                text,
            )
            text = re.sub(
                rf'(\b[A-Za-z_]\w*)\s*\+\s*\(\s*([A-Za-z_]\w*)\s*\*\s*{size}\s*\)',
                r'\1 + \2',
                text,
            )
            return text

        def direct_qcp_post_to_acsl(qcp_ensure: str) -> str | None:
            if "__return" not in qcp_ensure:
                return None

            array_prefixes = []
            predefined_vars = set()
            for item in post_map or []:
                predefined_vars.add(item[0])
                if item[1] in ('101', '001'):
                    array_prefixes.append((f'{item[0]}_l', item[2]))

            def drop_array_logic_vars(vars_text: str) -> list[str]:
                result = []
                for var in vars_text.split():
                    var = var.strip()
                    if not var:
                        continue
                    if any(var.startswith(prefix) for prefix, _ in array_prefixes):
                        continue
                    result.append(var)
                return result

            def replace_arrays(text: str) -> str:
                for prefix, acsl_name in sorted(array_prefixes, key=lambda item: len(item[0]), reverse=True):
                    pattern = re.compile(rf'\b{re.escape(prefix)}(?:_\d+)?\b')
                    text = pattern.sub(acsl_name, text)
                return text

            def replace_scalar_names(text: str) -> str:
                for name, kind, acsl_name in sorted(post_map or [], key=lambda item: len(item[0]), reverse=True):
                    if kind in ('101', '001'):
                        continue
                    text = re.sub(r'\b' + re.escape(name) + r'\b', acsl_name, text)
                return text

            def extract_leading_exists(expr: str) -> tuple[list[str], str]:
                exists_vars = []
                expr = expr.strip()
                while True:
                    match = re.match(r'^exists\s+([^,]+),\s*(.*)$', expr, flags=re.DOTALL)
                    if not match:
                        break
                    exists_vars.extend(drop_array_logic_vars(match.group(1)))
                    expr = match.group(2).strip()
                return exists_vars, expr

            def replace_inner_quantifiers(text: str) -> str:
                def repl(match):
                    vars_list = drop_array_logic_vars(match.group(2))
                    if not vars_list:
                        return ''
                    quant = "\\forall" if match.group(1) == "forall" else "\\exists"
                    return f"{quant} integer {', '.join(vars_list)}; "
                return re.sub(r'\b(forall|exists)\s+([^,()]+),', repl, text)

            def free_ghost_vars(text: str, bound_vars: set[str]) -> list[str]:
                excluded = {
                    'exists', 'forall', 'integer', 'int', 'signed', 'unsigned',
                    'Size_of', 'store_int_array', 'Ez_val', 'result',
                    'old', 'null',
                }
                variables = []
                for var in re.findall(r'\b[A-Za-z_]\w*_\d+\b', text):
                    if var in bound_vars or var in excluded or var in predefined_vars:
                        continue
                    if any(var.startswith(prefix) for prefix, _ in array_prefixes):
                        continue
                    if var not in variables:
                        variables.append(var)
                return variables

            def to_acsl_expr(text: str) -> str:
                text = strip_outer_parens(text)
                text = replace_arrays(text)
                text = replace_scalar_names(text)
                text = re.sub(r'\b([A-Za-z_]\w*)@pre\b', r'\\old(\1)', text)
                text = text.replace('__return', '\\result')
                text = text.replace('=>', '==>')
                text = text.replace('NULL', '\\null')
                text = normalize_pointer_offsets(text)
                text = replace_inner_quantifiers(text)
                if self.function_info and self.function_info.func_type and '*' in self.function_info.func_type:
                    text = re.sub(r'\\result\s*==\s*0\b', r'\\result == \\null', text)
                    text = re.sub(r'0\s*==\s*\\result\b', r'\\result == \\null', text)
                text = re.sub(r'\s+', ' ', text)
                return text.strip()

            ensures = []
            for raw_case in split_top_level(qcp_ensure, '||'):
                case = strip_outer_parens(raw_case)
                exists_vars, body = extract_leading_exists(case)
                conjuncts = split_top_level(body, '&&')
                result_parts = []
                path_parts = []
                for conj in conjuncts:
                    conj = strip_outer_parens(conj)
                    if not conj or conj.startswith('store_int_array'):
                        continue
                    if '__return' in conj:
                        result_parts.append(conj)
                    else:
                        path_parts.append(conj)

                if not result_parts:
                    continue

                raw_for_quant = ' && '.join(path_parts + result_parts)
                bound = set(exists_vars)
                for match in re.finditer(r'\b(?:forall|exists)\s+([^,()]+),', raw_for_quant):
                    bound.update(match.group(1).split())
                for var in free_ghost_vars(raw_for_quant, bound):
                    if var not in exists_vars:
                        exists_vars.append(var)

                path_conjuncts = [to_acsl_expr(part) for part in path_parts]
                result_conjuncts = [to_acsl_expr(part) for part in result_parts]
                path = ' && '.join(f"({part})" for part in path_conjuncts if part)
                result = ' && '.join(f"({part})" for part in result_conjuncts if part)
                if not result:
                    continue

                if path:
                    body = f"{path} ==> {result}"
                else:
                    body = result
                if exists_vars:
                    body = f"\\exists integer {', '.join(exists_vars)}; {body}"
                ensures.append(f"ensures {body};")

            if not ensures:
                return None

            if self.function_info.require:
                generated_str = self.create_require_str()
                if generated_str and generated_str not in self.function_info.require and self.function_info.require not in generated_str:
                    require_str = f'''{generated_str}
{self.function_info.require}
'''
                else:
                    require_str = self.function_info.require
            else:
                require_str = self.create_require_str()

            if require_str:
                return f'''/*@
{require_str}
{chr(10).join(ensures)}
*/
'''
            return f'''/*@
{chr(10).join(ensures)}
*/
'''

        direct_acsl = direct_qcp_post_to_acsl(ensure)
        if direct_acsl:
            return direct_acsl

       

        ensure_list=[]
        array_names = []
        var_names = []

        if post_map:
            for vars in post_map:
                var_names.append(vars[0])
                if vars[1] == '101':
                    array_names.append(f'{vars[0]}_l')
        
        ensures = ensure.split('||')
        updated_ensures = []
        for part in ensures:

            if 'exists' in ensure:
                part = updated_condition_str(part ,var_names)

            updated_ensures.append(part)
        
        ensure ='||'.join(updated_ensures)
            

        var_maps,path_conds,results = self.extract_var_map_from_file(ensure)
       

        for var_map, path_cond, result in zip(var_maps, path_conds, results):
        
            # print(f"Variable Map: {var_map}")
            # print(f"Path Condition: {path_cond}")
            # print(f"Result: {result}")

           
            def fix_brackets(s: str) -> str:
                stack = []
                to_remove = set()  # 记录需要Deleted的多余括号位置
                bracket_pairs = {')': '(', ']': '[', '}': '{'}
                left_to_right = {'(': ')', '[': ']', '{': '}'}

                # 第一次遍历：检查括号合法性并标记多余括号
                for i, char in enumerate(s):
                    if char in bracket_pairs.values():  # 左括号入栈
                        stack.append((char, i))
                    elif char in bracket_pairs:        # 右括号尝试匹配
                        if stack and stack[-1][0] == bracket_pairs[char]:
                            stack.pop()  # 匹配成功，弹出左括号
                        else:
                            to_remove.add(i)  # 多余右括号，标记Deleted

                # 收集所有未匹配的左括号（需要补右括号）
                missing_right = [left_to_right[char] for char, _ in stack]

                # 第二次遍历：构造修复后的字符串
                result = []
                for i, char in enumerate(s):
                    if i not in to_remove:  # Kept合法字符
                        result.append(char)

                # 贪心补全右括号：统一追加到末尾
                result.extend(missing_right)

                return ''.join(result).strip()

            if path_cond:
                path_cond = fix_brackets(path_cond)
            if result:
                result =  fix_brackets(result)
            
            
         



            def replace_quantifier(match):
                quantifier = match.group(1).strip()  # exists 或 forall
                variables = match.group(2).strip().split()  # 变量列表（如 ["a", "b", "c"]）
                # 去掉 variables中的以 array_names 中的任一项开头的
                variables = [var for var in variables if not any(var.startswith(array_name) for array_name in array_names)]
                # 格式化为 "\quantifier int var1, var2;"
                # 如果 variables 为空, 则返回去掉量词匹配部分的剩余部分
                if not variables:
                    return ''
                return f"\\{quantifier} int {', '.join(variables)}; "

            # 正则表达式匹配 exists/forall 后的所有变量直到逗号或行尾
            pattern = r"(exists|forall)\s+([a-zA-Z_@][\w@]*(?:\s+[a-zA-Z_@][\w@]*)*)\s*,?"

           

            state = None
            state_list =[]
            if var_map:
                for key in var_map:
                    state_list.append(f'{key} == {var_map[key]}')
                    if state_list:
                        state = '&&'.join(state_list)
            
            if path_cond:
                path_cond = re.sub(pattern, replace_quantifier, path_cond)

            if state:
                state = re.sub(pattern, replace_quantifier, state)


            # 把基于存在量词和逻辑变量的数组表示转为直接表示


            if post_map:

                for vars in post_map:


                    # var@pre <- \old(var)
                    if state :
                        state = state.replace(f'{vars[0]}@pre',f'\old({vars[0]})')
                    if result :
                        result = result.replace(f'{vars[0]}@pre',f'\old({vars[0]})')    
                    if path_cond : 
                        path_cond = path_cond.replace(f'{vars[0]}@pre',f'\old({vars[0]})') 

                    
                    # 000
                    # x 为整数, p 为结构体指针  p_x <- \old(p->x)
                    # p_q_x <- \old(p->q->x)

                    # 100
                    # 指针 p_v <- *(\old(p)) 
                    # 嵌套指针 p_x_v <- *(\old(p->x))
                    # 多层指针 p_v <- **(\old(p)) 
                    if vars[1] in ('100', '000'):

                        replacement = vars[2]
                        
                        # 定义替换函数（确保完整变量匹配）
                        def replace_var(text, var, replacement):
                            # 使用正则匹配单词边界（避免替换 "xx" 里的 "x"）
                            pattern = re.compile(r'\b' + re.escape(var) + r'\b')
                            return pattern.sub(replacement, text)

                        # 执行替换
                        if state:
                            state = replace_var(state, vars[0], replacement)
                        if result:
                            result = replace_var(result, vars[0], replacement)
                        if path_cond:
                            path_cond = replace_var(path_cond, vars[0], replacement)


                    if vars[1] in ('101', '001'):

                        logic_var = f'{vars[0]}_l'
                        logic_var_pattern = re.compile(rf'\b{re.escape(logic_var)}(?:_\d+)?\b')  

                        def replace_logic_var(text):
                            return logic_var_pattern.sub(vars[2], text)

                        if state:
                            state = replace_logic_var(state)
                        if result:
                            result = replace_logic_var(result)
                        if path_cond:
                            path_cond = replace_logic_var(path_cond)

                    
                
            
            # 如果 state 中有 __return, 其实是 result， 此时没有 state
            # state = state.replace('__return','\\result')
            # state = state.replace('=>','==>')


            if state:
                state = state.replace('__return','\\result')
                state = state.replace('=>','==>')

            if result :
                result = result.replace('__return','\\result')
                result = result.replace('=>','==>')


            if path_cond :
                path_cond = path_cond.replace('__return','\\result')
                path_cond = path_cond.replace('=>','==>')

            state = normalize_pointer_offsets(state)
            result = normalize_pointer_offsets(result)
            path_cond = normalize_pointer_offsets(path_cond)
            

            if path_cond != None and result !=None and state!=None:
                ensure_item = f'''
ensures {path_cond} ==> {state};
ensures {path_cond} ==> {result};
'''
            elif path_cond != None and state!=None:
                ensure_item = f'''
ensures {path_cond} ==> {state};
'''         
            elif result !=None and state!=None:
                ensure_item = f'''
ensures {state};
ensures {result};
'''         
            elif path_cond != None and result!=None:
                ensure_item = f'''
ensures {path_cond} ==> {result};
'''      

            elif state!=None: 
                ensure_item = f'''
ensures {state};
'''
            elif result!=None: 
                ensure_item = f'''
ensures {result};
'''         
            else :
                ensure_item = str()

            ensure_list.append(ensure_item)

        ensure_str = ''.join(ensure_list)

        ensure_str = self.optimize_acsl(ensure_str)


        


        # if self.function_info.require:
        #     require_str = self.function_info.require
        # else:
        #     require_str = self.create_require_str()
        
        if self.function_info.require:
            generated_str = self.create_require_str()
            if generated_str not in self.function_info.require and self.function_info.require not in generated_str:
                require_str = f'''{generated_str}
{self.function_info.require}
'''
            else:
                require_str = self.function_info.require
        else:
            require_str = self.create_require_str()

        if require_str and ensure_str:
            annotations = f'''/*@
{require_str}
{ensure_str}
*/
'''
        elif ensure_str:
            annotations = f'''/*@
{ensure_str}
*/
'''
        else:
            annotations = ''
        return annotations


    

    def filter_condition(self, condition):


        

        if not condition:
            return condition
        
        conditons = condition.split('&&')
        new_conditons = []

        for item in conditons:
            if 'store_int_array' not in item:
                new_conditons.append(item)

        condition = '&&'.join(new_conditons)
        

        def replace_acsl_at_pre(condition):
            pattern = r'((?:\*?[a-zA-Z_]\w*|(?:\*?[a-zA-Z_]\w*)\[[^\]]+\]))@pre'
            replaced_condition = re.sub(pattern, lambda m: rf'\at({m.group(1)},Pre)', condition)
            return replaced_condition
        
        condition = replace_acsl_at_pre(condition)


        inv_map = self.inv_map


        if inv_map:

            for vars in inv_map:
                
                # var@pre <- \old(var)
                
                condition = condition.replace(f'{vars[0]}@pre',rf'\at({vars[0]},Pre)')

                    
                if vars[1] in ('100', '000'):

                    replacement = vars[2]
                        
                    # 定义替换函数（确保完整变量匹配）
                    def replace_var(text, var, replacement):
                        # 使用正则匹配单词边界（避免替换 "xx" 里的 "x"）
                        pattern = re.compile(r'\b' + re.escape(var) + r'\b')
                        return pattern.sub(replacement, text)

                    condition = replace_var(condition, vars[0], replacement)


                if vars[1] in ('101', '001'):

                    logic_var = f'{vars[0]}_l'
                    logic_var_pattern = re.compile(rf'\b{re.escape(logic_var)}(?:_\d+)?\b')  

                    def replace_logic_var(text):
                        return logic_var_pattern.sub(vars[2], text)

                        
                    condition = replace_logic_var(condition)
        return condition

    def assign_annotations(self, annotations):

            llm = Chatbot(self.llm_config)

            """调用Model生成ACSL规约"""

            prompt =  self.get_assign_prompt(annotations)

            try:
                """调用 OpenAI API 获取 ACSL 注释"""
                

                def extract_last_c_code(text):
                    # 匹配 C 代码块（Markdown 代码块 或 以 #include 开头的代码）
                    code_blocks = re.findall(r'```c(.*?)```', text, re.DOTALL)  # Markdown 代码块

                    return code_blocks[-1] if code_blocks else text  # 返回最后一个 C 代码块

                # 处理响应
                assistant_response = llm.chat(prompt)
                assistant_response = re.sub(r'>\s*Reasoning\s*[\s\S]*?(?=\n\n|$)', '', assistant_response, flags=re.IGNORECASE)
                assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
                assistant_response = extract_last_c_code(assistant_response)

                return assistant_response

            except Exception as e:
                print(f"API调用失败: {e}")
                return None

    def get_assign_prompt(self,annotations):
        # 从文件中读取 prompt 模板
        with open("prompt/func/assign.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # 替换模板中的 {code} 占位符
        assign_prompt = prompt_template.format(code = annotations)

        return assign_prompt

            
    def specgen_annotations(self, annotations):

            llm = Chatbot(self.llm_config)

            """调用Model生成ACSL规约"""

            prompt =  self.get_specgen_prompt(annotations)

            try:
                """调用 OpenAI API 获取 ACSL 注释"""
                

                def extract_last_c_code(text):
                    # 匹配 C 代码块（Markdown 代码块 或 以 #include 开头的代码）
                    code_blocks = re.findall(r'```c(.*?)```', text, re.DOTALL)  # Markdown 代码块

                    return code_blocks[-1] if code_blocks else text  # 返回最后一个 C 代码块

                # 处理响应
                assistant_response = llm.chat(prompt)
                assistant_response = re.sub(r'>\s*Reasoning\s*[\s\S]*?(?=\n\n|$)', '', assistant_response, flags=re.IGNORECASE)
                assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
                assistant_response = extract_last_c_code(assistant_response)

                return assistant_response

            except Exception as e:
                print(f"API调用失败: {e}")
                return None

    
    
    def get_specgen_prompt(self,annotations):
         # 从文件中读取 prompt 模板
        with open("prompt/func/specgen.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # When the function body contains a loop, instruct the model to
        # symbolically continue execution from the *last* loop invariant
        # (combined with the negation of the loop condition) through the
        # remaining straight-line code until the function returns, and use the
        # resulting state as the postcondition.
        loop_guide = ''
        if re.search(r'\bloop\s+invariant\b', annotations) or re.search(
            r'\b(for|while|do)\s*[\(\{]', annotations
        ):
            loop_guide = (
                "### Loop-aware postcondition derivation: ###\n"
                "The function below contains at least one loop. To produce a sound "
                "`ensures` clause:\n"
                "- Take the **last** `loop invariant` of the loop together with the "
                "**negation of the loop condition** (loop-exit state).\n"
                "- Symbolically execute every statement after the loop, propagating "
                "the state through assignments, branches, and any nested loops "
                "(applying the same rule recursively).\n"
                "- The `ensures` clause must describe the resulting state at the "
                "function's return point — not the state mid-loop.\n"
                "- Do not weaken the postcondition: every fact derivable from the "
                "loop-exit state plus the post-loop code must be reflected, "
                "including return values and any memory written after the loop.\n"
            )

        # Category-specific ACSL pitfalls (universal + program-type-specific
        # hints). Critical for recursive programs: carries the `decreases`
        # clause requirement and ghost-logic-mirror pattern that the LLM
        # otherwise omits on first attempt (the hint previously only injected
        # at syntax-error repair time, too late for cases that pass syntax
        # check first try).
        category_hints = ''
        try:
            from example_retriever import load_category_hints
            file_path = getattr(self.function_info, 'file_path', None)
            src = ''
            if file_path:
                with open(file_path, 'r', encoding='utf-8') as fh:
                    src = fh.read()
            category_hints = load_category_hints(src)
        except Exception:
            category_hints = ''

        # 替换模板中的 {code} 占位符
        specgen_prompt = prompt_template.format(
            code=annotations,
            loop_guide=loop_guide,
            category_hints=category_hints,
        )

        return specgen_prompt

    
if __name__ == "__main__":
   conv = SpecificationConvertor()

   input = r'''
    /*@
      loop invariant (1 < \at(n, Pre)) ==> (((max == a[0])&&(i == 1)&&(n == \at(n, Pre))&&(a == \at(a, Pre))) || (1 <= i <= n && \forall integer j; 0 <= j < i ==> max >= a[j]));
      loop invariant (1 < \at(n, Pre)) ==> (((max == a[0])&&(i == 1)&&(n == \at(n, Pre))&&(a == \at(a, Pre))) || (1 <= i <= n && \forall integer j; 0 <= j < i ==> max >= a[j]));
      loop invariant (!(1 < \at(n, Pre))) ==> ((max == a[0])&&(i == 1)&&(n == \at(n, Pre))&&(a == \at(a, Pre)));
      loop invariant n == \at(n, Pre);
      loop invariant a == \at(a, Pre);
    */

'''
   print(conv.convert_annotations_(input))
