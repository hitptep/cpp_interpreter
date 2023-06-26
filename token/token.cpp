#include "token.h"

// 构造函数
Token::Token(TokenType type, const std::string& value)
        : type_(type), value_(value) {}

// 获取TokenType
TokenType Token::GetTokenType() const {
    return type_;
}

// 获取Token的值
std::string Token::GetValue() const {
    return value_;
}