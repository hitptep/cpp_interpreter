#ifndef TOKEN_H
#define TOKEN_H

#include <string>

// TokenType枚举
enum class TokenType {
    PLUS,
    MINUS,
    MUL,
    DIV,
    NUMBER,
    LPAREN,
    RPAREN,
    EOF_TOKEN
};

// Token类
class Token {
public:
    // 构造函数
    Token(TokenType type, const std::string& value);

    // 获取TokenType
    TokenType GetTokenType() const;

    // 获取Token的值
    std::string GetValue() const;

private:
    // TokenType
    TokenType type_;

    // Token的值
    std::string value_;
};

#endif // TOKEN_H