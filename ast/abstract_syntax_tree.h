#ifndef ABSTRACT_SYNTAX_TREE_H
#define ABSTRACT_SYNTAX_TREE_H

#include "node.h"

// 抽象语法树类
class AbstractSyntaxTree {
public:
    // 构造函数
    AbstractSyntaxTree(Node* root);

    // 获取根节点
    Node* GetRoot();

    // 设置根节点
    void SetRoot(Node* root);

private:
    // 根节点
    Node* root_;
};

#endif // ABSTRACT_SYNTAX_TREE_H