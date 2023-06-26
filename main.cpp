#include <iostream>
#include "lexer.h"
#include "parser.h"
#include "ast/abstract_syntax_tree.h"

int main() {
    // 读取用户输入的数学表达式
    std::string input;
    std::cout << "Enter a math expression: ";
    std::getline(std::cin, input);

    // 创建Lexer对象和Parser对象
    Lexer lexer(input);
    Parser parser(lexer);

    // 解析数学表达式并获取抽象语法树
    AbstractSyntaxTree* ast = parser.Parse();

    // 计算表达式的值并输出结果
    int result = ast->GetRoot()->Evaluate();
    std::cout << "Result: " << result << std::endl;

    return 0;
}