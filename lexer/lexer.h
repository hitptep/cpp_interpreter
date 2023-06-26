#ifndef LEXER_H
#define LEXER_H

#include <string>
#include "../token/token.h"

// Lexer类
class Lexer {
public:
    // 构造函数
    Lexer(const std::string& input);

    // 获取下一个Token
    Token GetNextToken();

private:
    // 输入的代码
    std::string input_;

    // 当前位置
    int current_pos_;
};

#endif // LEXER_H