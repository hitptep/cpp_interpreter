cmake_minimum_required(VERSION 3.24)
project(interpreter)

set(CMAKE_CXX_STANDARD 14)

include_directories(lexer)

include_directories(parser)

add_executable(interpreter
        ast/abstract_syntax_tree.cpp
        lexer/lexer.cpp
        lexer/lexer.h
        parser/parser.cpp
        parser/parser.h
        token/token.cpp
        main.cpp
        ast/abstract_syntax_tree.h
        token/token.h
        ast/node.h ast/node.cpp)
