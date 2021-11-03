#pragma once
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include"SeqStack.cpp"

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
    biTree(std::string _string)
    {
        str = _string;
        len = _string.length();
        genTreeNode(1, root);
    }

    bool treeEmpty() { return root == nullptr; }

    void assign(cNode& node, char c) {node.data = c;}

    int Depth(){return treeDepth(root);}

    bool insertChild(cNode& node, int i, char val)
    {
        if (i == 1 && node.left != nullptr)return false;
        else if (i == 2 && node.right != nullptr)return false;
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

    void preOrderRecursive(void (*p)(cNode*&)) { preOrder(root, p); }

    void preOrderBasic(void (*p)(cNode*&)){PreOrderBasic(p);}

    void inOrderBasic(void (*p)(cNode*&)){InOrderBasic(p);}

    void inOrderRecursive(void (*p)(cNode*&)){InOrderRecursive(root,p);}

    void postOrderRecursive(void (*p)(cNode*&)){PostOrderRecursive(root,p);}

    cNode* Root() { return root; }
private:
    void preOrder(cNode* n, void (*p)(cNode*&))
    {
        if (n == nullptr) return;
        p(n);
        preOrder(n->left, p);
        preOrder(n->right, p);
    }

    void InOrderRecursive(cNode* n,void (*p)(cNode*&))
    {
        if (n == nullptr)return;
        InOrderRecursive(n->left,p);
        p(n);
        InOrderRecursive(n->right,p);
    }

    void InOrderBasic(void (*p)(cNode*&))
    {
        cNode* tmp = nullptr;
        stack<cNode*> a;
        if (root != nullptr)
        {
            tmp = root;
        }
        while (true)
        {
            if (tmp != nullptr)
            {
                a.push(tmp);
                tmp = tmp->left;
            }
            else if (!a.isEmpty())
            {
                tmp = a.top();
                p(tmp);
                tmp = tmp->right;
            }
            else
                break;
        }
    }

    void PreOrderBasic(void (*p)(cNode*&))
    {
        stack<cNode*> a;
        if (root!=nullptr)
            a.push(root);
        cNode* tmp;
        while (!a.isEmpty())
        {
            tmp = a.top();
            p(tmp);
            if (tmp->right !=nullptr)
                a.push(tmp->right);
            if(tmp->left != nullptr)
                a.push(tmp->left);
        }
    }

    void genTreeNode(int n, cNode*& node)
    {
        if (n >= len + 1 || str[n - 1] == '#')
        { 
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

    void PostOrderRecursive(cNode* node,void (*p)(cNode*&))
    {
        if (node!=nullptr)
        {
            PostOrderRecursive(node->left,p);
            PostOrderRecursive(node->right,p);
            p(node);
        }
    }
    
    cNode* root;
    std::string str;
    int len;
};