#include "abstract_syntax_tree.h"

// 构造函数
AbstractSyntaxTree::AbstractSyntaxTree(Node* root)
        : root_(root) {}

// 获取根节点
Node* AbstractSyntaxTree::GetRoot() {
    return root_;
}

// 设置根节点
void AbstractSyntaxTree::SetRoot(Node* root) {
    root_ = root;
}