#include <stdexcept>
#include "node.h"

// NumberNode的构造函数
NumberNode::NumberNode(int value) : value_(value) {}

// 获取节点类型
std::string NumberNode::GetNodeType() const {
    return "number";
}

// 获取数字的值
int NumberNode::GetValue() const {
    return value_;
}

// 计算节点的值
int NumberNode::Evaluate() const {
    return value_;
}

// BinaryOperatorNode的构造函数
BinaryOperatorNode::BinaryOperatorNode(Node* left, TokenType op_type, Node* right)
        : left_(left), op_type_(op_type), right_(right) {}

// BinaryOperatorNode的析构函数
BinaryOperatorNode::~BinaryOperatorNode() {
    delete left_;
    delete right_;
}

// 获取节点类型
std::string BinaryOperatorNode::GetNodeType() const {
    return "binary_operator";
}

// 获取左节点
Node* BinaryOperatorNode::GetLeft() const {
    return left_;
}

// 获取右节点
Node* BinaryOperatorNode::GetRight() const {
    return right_;
}

// 获取操作符类型
TokenType BinaryOperatorNode::GetOpType() const {
    return op_type_;
}

// 计算节点的值
int BinaryOperatorNode::Evaluate() const {
    int left_value = left_->Evaluate();
    int right_value = right_->Evaluate();

    if (op_type_ == TokenType::PLUS) {
        return left_value + right_value;
    } else if (op_type_ == TokenType::MINUS) {
        return left_value - right_value;
    } else if (op_type_ == TokenType::MUL) {
        return left_value * right_value;
    } else if (op_type_ == TokenType::DIV) {
        return left_value / right_value;
    } else {
        throw std::runtime_error("Unknown operator type.");
    }
}