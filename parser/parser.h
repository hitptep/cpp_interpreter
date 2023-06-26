#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "../ast/abstract_syntax_tree.h"
#include "../ast/node.h"

// Parser类
class Parser {
public:
    // 构造函数
    Parser(Lexer& lexer);

    // 解析输入的代码并返回抽象语法树
    AbstractSyntaxTree* Parse();

private:
    // 递归下降解析表达式
    Node* ParseExpression();

    // 递归下降解析项
    Node* ParseTerm();

    // 递归下降解析因子
    Node* ParseFactor();

    // 词法分析器
    Lexer& lexer_;

    // 当前Token
    Token current_token_;
};

#endif // PARSER_H