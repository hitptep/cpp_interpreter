#ifndef NODE_H
#define NODE_H

#include <string>
#include "../token/token.h"

// Node类
class Node {
public:
    // 析构函数
    virtual ~Node() {}

    // 获取节点类型
    virtual std::string GetNodeType() const = 0;

    // 计算节点的值
    virtual int Evaluate() const = 0;
};

// 数字节点类
class NumberNode : public Node {
public:
    // 构造函数
    NumberNode(int value);

    // 获取节点类型
    std::string GetNodeType() const override;

    // 获取数字的值
    int GetValue() const;

    // 计算节点的值
    int Evaluate() const override;

private:
    // 数字的值
    int value_;
};

// 二元运算符节点类
class BinaryOperatorNode : public Node {
public:
    // 构造函数
    BinaryOperatorNode(Node* left, TokenType op_type, Node* right);

    // 析构函数
    ~BinaryOperatorNode() override;

    // 获取节点类型
    std::string GetNodeType() const override;

    // 获取左节点
    Node* GetLeft() const;

    // 获取右节点
    Node* GetRight() const;

    // 获取操作符类型
    TokenType GetOpType() const;

    // 计算节点的值
    int Evaluate() const override;

private:
    // 左节点
    Node* left_;

    // 右节点
    Node* right_;

    // 操作符类型
    TokenType op_type_;
};

#endif // NODE_H