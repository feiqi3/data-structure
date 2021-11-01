#include<iostream>
#include<string>
#include"SeqStack.cpp"
#include"BiTree.cpp"
using namespace std;

int main()
{
    string str;
    cin>>str;
    biTree a(str);
    cout<<"preOrder traverse in traverse way:  ";
    a.preOrderBasic([](cNode*& c){cout<<c->data<<" ";});
    cout<<endl;
    cout<<"preOrder traverse in recursive way:  ";
    a.preOrderRecursive([](cNode*& c){cout<<c->data<<" ";});
    cout<<endl; 
    cout<<"inOrder traverse in recursive way:  ";
    a.inOrderRecursive([](cNode*& c){cout<<c->data<<" ";});
    cout<<endl;
    cout<<"inOrder traverse in traverse way:  ";
    a.inOrderBasic([](cNode*& c){cout<<c->data<<" ";});
    cout<<endl;
    cout<<"PostOrder traverse in recursive way:  ";
    a.postOrderRecursive([](cNode*& c){cout<<c->data<<" ";});
    cout<<endl;
}