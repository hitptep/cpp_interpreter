
#include "lexer.h"
#include <stdexcept>
// 构造函数
Lexer::Lexer(const std::string& input)
        : input_(input), current_pos_(0) {}

// 获取下一个Token
Token Lexer::GetNextToken() {
    // 如果已经到达输入的末尾，则返回EOF Token
    if (current_pos_ >= input_.length()) {
        return Token(TokenType::EOF_TOKEN, "");
    }

    // 获取当前字符
    char current_char = input_[current_pos_];

    // 如果当前字符是一个数字，则解析数字并返回NUMBER Token
    if (isdigit(current_char)) {
        std::string value = "";
        while (isdigit(current_char)) {
            value += current_char;
            current_pos_++;
            current_char = input_[current_pos_];
        }
        return Token(TokenType::NUMBER, value);
    }

    // 如果当前字符是一个操作符，则返回相应的操作符Token
    switch (current_char) {
        case '+':
            current_pos_++;
            return Token(TokenType::PLUS, "+");
        case '-':
            current_pos_++;
            return Token(TokenType::MINUS, "-");
        case '*':
            current_pos_++;
            return Token(TokenType::MUL, "*");
        case '/':
            current_pos_++;
            return Token(TokenType::DIV, "/");
        case '(':
            current_pos_++;
            return Token(TokenType::LPAREN, "(");
        case ')':
            current_pos_++;
            return Token(TokenType::RPAREN, ")");
        default:
            throw std::runtime_error("Invalid character.");
    }
}