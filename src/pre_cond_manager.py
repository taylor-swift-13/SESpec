import re
from typing import Dict

class PreconditionsManager:
    
    # qcp
    Require: Dict[str, str]
    # acsl
    requires: Dict[str, str]

    input_file_path: str

    def read_file_content(self, file_path: str) -> str:
        """读取文件内容"""
        try:
            with open(file_path, 'r', encoding='utf-8') as f:
                return f.read()
        except Exception as e:
            print(f"Error reading file: {e}")
            return ""

    def extract_acsl_requires_improved(self, c_code: str) -> Dict[str, str]:
        """提取ACSL注释中的requires语句，返回函数名到requires的映射"""
        
        # 更灵活的正则表达式，匹配各种ACSL注释格式
        function_pattern = re.compile(
            r"/\*@\s*"              # 匹配 /*@ 开始
            r"([\s\S]*?)"           # 非贪婪匹配注释内容
            r"\*/\s*"               # 匹配 */ 结束
            r"(?:[\w\s\*]+\s+)*"    # 匹配可能的函数返回Type (非捕获)
            r"(\w+)\s*\("           # 捕获函数名
            r"[^)]*\)\s*\{?"        # 匹配参数列表和可能的函数体左花括号
        )

        matches = function_pattern.finditer(c_code)
        results = {}

        for match in matches:
            acsl_content = match.group(1)
            function_name = match.group(2)

            requires_lines = []
            # 遍历ACSL注释的每一行
            for line in acsl_content.splitlines():
                stripped_line = line.strip()
                # 匹配各种require格式
                if (stripped_line.startswith('requires') or 
                    stripped_line.startswith('@ require') or
                    stripped_line.startswith('@requires') or
                    stripped_line.startswith('ensures') or
                    stripped_line.startswith('@ ensures') or
                    stripped_line.startswith('@ensures')):
                    requires_lines.append(line)

            if requires_lines:
                full_requires_block = "\n".join(requires_lines)
                cleaned_block = full_requires_block.strip()
                results[function_name] = cleaned_block

        return results

    def add_ensures_to_function(self, file_content: str, function_name: str, ensures_statement: str = "ensures PLACE_HOLDER;") -> str:
        """
        在指定函数的最后一个requires下添加ensures语句
        
        Args:
            file_content: 文件内容
            function_name: 函数名
            ensures_statement: 要添加的ensures语句，默认为"ensures PLACE_HOLDER;"
            
        Returns:
            修改后的文件内容
        """
        # 构建函数注释的正则表达式
        function_comment_pattern = re.compile(
            r"(/\*@\s*"              # 匹配 /*@ 开始
            r"([\s\S]*?)"           # 非贪婪匹配注释内容
            r"\*/\s*"               # 匹配 */ 结束
            r"(?:[\w\s\*]+\s+)*"    # 匹配可能的函数返回Type (非捕获)
            rf"{re.escape(function_name)}\s*\("  # 匹配指定函数名
            r"[^)]*\)\s*\{?)"       # 匹配参数列表和可能的函数体左花括号
        )
        
        def replace_function_comment(match):
            comment_content = match.group(1)
            # 检查是否已经有ensures语句
            if "ensures" not in comment_content:
                # 分析注释内容，Found最后一个requires的位置
                lines = comment_content.split('\n')
                new_lines = []
                last_requires_index = -1
                
                # Found最后一个requires语句的索引
                for i, line in enumerate(lines):
                    stripped_line = line.strip()
                    if (stripped_line.startswith('requires') or 
                        stripped_line.startswith('@ require') or
                        stripped_line.startswith('@requires')):
                        last_requires_index = i
                
                if last_requires_index != -1:
                    # 在最后一个requires后插入ensures
                    for i, line in enumerate(lines):
                        new_lines.append(line)
                        if i == last_requires_index:
                            # 在最后一个requires后添加ensures
                            # 保持相同的缩进
                            indent = len(line) - len(line.strip()) + 7
                            if line.strip().startswith('@'):
                                # 如果requires以@开头，ensures也应该以@开头
                                ensures_line = ' ' * indent + '@ ' + ensures_statement
                            else:
                                ensures_line = ' ' * indent + ensures_statement
                            new_lines.append(ensures_line)
                else:
                    # 如果没有Foundrequires，直接返回原内容
                    return comment_content
                
                return '\n'.join(new_lines)
            else:
                # 如果已经有ensures，不做修改
                return comment_content
        
        # 替换文件内容
        modified_content = function_comment_pattern.sub(replace_function_comment, file_content)
        return modified_content

    def __init__(self, input_file_path: str, preconditions: Dict[str, str] = None):
        self.input_file_path = input_file_path
        
        # 读取文件内容
        file_content = self.read_file_content(input_file_path)
        
        # 提取requires
        self.requires = self.extract_acsl_requires_improved(file_content)
        
        # print(self.requires)

        self.Require = preconditions

    def update_requires(self):
        """更新requires"""
        file_content = self.read_file_content(self.input_file_path)
        self.requires = self.extract_acsl_requires_improved(file_content)


# Test代码
if __name__ == "__main__":
    # TestCheckCal_24.c文件
    test_file = "input/pIp/CheckCal_24.c"
    
    print("=== TestPreCondManager ===")
    print(f"Test文件: {test_file}")
    print()
    
    try:
        manager = PreconditionsManager(test_file)
        print(f"\n总共Found {len(manager.requires)} 个函数的requires")
        
        # 读取文件内容
        with open(test_file, 'r', encoding='utf-8') as f:
            original_content = f.read()
        
        # Test添加ensures到CheckCalFun函数
        print("\n=== Test添加ensures到CheckCalFun函数 ===")
        modified_content = manager.add_ensures_to_function(original_content, "CheckCalFun")
        
        # 显示修改前后的对比
        print("修改前:")
        print(original_content)
        print("\n" + "="*50 + "\n")
        print("修改后:")
        print(modified_content)
        
        # 保存修改后的文件
        output_file = "input/pIp/CheckCal_24_modified.c"
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write(modified_content)
        print(f"\n修改后的文件已保存到: {output_file}")
        
    except Exception as e:
        print(f"Test失败: {e}")
        import traceback
        traceback.print_exc()


