#pragma once
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
template<typename T>
struct Node
{
    T data;
    Node* left;
    Node* right;
};

typedef Node<char> cNode;

class biTree
{
public:

    biTree(const char* _string, int Len)
    {
        str = _string;
        len = Len;
        genTreeNode(1, root);
    }

    bool treeEmpty() { return root == nullptr; }

    void assign(cNode& node, char c) { node.data = c; }

    int Depth()
    {
        return treeDepth(root);
    }

    bool insertChild(cNode& node, int i, char val)
    {
        if (i == 1 && node.left != nullptr)
            return false;
        else if (i == 2 && node.right != nullptr)
            return false;
        if (i == 1)
        {
            node.left = new cNode;
            node.left->data = val;
        }
        if (i == 2)
        {
            node.right = new cNode;
            node.right->data = val;
        }
        return true;
    }

    static cNode* leftChild(cNode n) { return n.left; }

    static cNode* rightChild(cNode n) { return n.right; }

    void preOderTraverse(void (*p)(cNode)) { preOder(root, p); }



    cNode* Root() { return root; }
private:
    void preOder(cNode* n, void (*p)(cNode))
    {
        if (n == nullptr) return;
        p(*n);
        preOder(n->left, p);
        preOder(n->right, p);
    }

    void genTreeNode(int n, cNode*& node)
    {
        if (n >= len || str[n - 1] == '#') { 
            node = nullptr;
            return;
        }
        node = new cNode;
        node->data = str[n-1];
        genTreeNode(2 * n, node->left);
        genTreeNode(2 * n + 1, node->right);
    }

    int treeDepth(cNode* n)
    {
        if (n == nullptr)return 0;
        return std::max(1 + treeDepth(n->left), 1 + treeDepth(n->right));
    }

    cNode* root;
    const char* str;
    int len;
};