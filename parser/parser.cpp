#include <stdexcept>
#include "parser.h"
#include "../ast/node.h"
// 构造函数
Parser::Parser(Lexer& lexer)
        : lexer_(lexer), current_token_(lexer.GetNextToken()) {}

// 解析输入的代码并返回抽象语法树
AbstractSyntaxTree* Parser::Parse() {
    // 解析表达式
    Node* root = ParseExpression();

    // 创建抽象语法树
    AbstractSyntaxTree* ast = new AbstractSyntaxTree(root);

    return ast;
}

// 递归下降解析表达式
Node* Parser::ParseExpression() {
    // 解析项
    Node* left = ParseTerm();

    // 解析加减号操作符
    while (current_token_.GetTokenType() == TokenType::PLUS ||
           current_token_.GetTokenType() == TokenType::MINUS) {
        TokenType op_type = current_token_.GetTokenType();
        current_token_ = lexer_.GetNextToken();
        Node* right = ParseTerm();
        left = new BinaryOperatorNode(left, op_type, right);
    }

    return left;
}

// 递归下降解析项
Node* Parser::ParseTerm() {
    // 解析因子
    Node* left = ParseFactor();

    // 解析乘除号操作符
    while (current_token_.GetTokenType() == TokenType::MUL ||
           current_token_.GetTokenType() == TokenType::DIV) {
        TokenType op_type = current_token_.GetTokenType();
        current_token_ = lexer_.GetNextToken();
        Node* right = ParseFactor();
        left = new BinaryOperatorNode(left, op_type, right);
    }

    return left;
}

// 递归下降解析因子
Node* Parser::ParseFactor() {
    // 如果当前Token是一个数字，则返回一个NumberNode
    if (current_token_.GetTokenType() == TokenType::NUMBER) {
        Node* node = new NumberNode(std::stoi(current_token_.GetValue()));
        current_token_ = lexer_.GetNextToken();
        return node;
    }

    // 如果当前Token是一个左括号，则解析一个表达式
    if (current_token_.GetTokenType() == TokenType::LPAREN) {
        current_token_ = lexer_.GetNextToken();
        Node* node = ParseExpression();
        if (current_token_.GetTokenType() != TokenType::RPAREN) {
            throw std::runtime_error("Expected ')'.");
        }
        current_token_ = lexer_.GetNextToken();
        return node;
    }

    // 如果当前Token不是一个数字或左括号，则抛出错误
    throw std::runtime_error("Expected number or '('.");
}