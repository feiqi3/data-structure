#include"List.hpp"


int main()
{
    List<int> a;
    a.push_back(10);
    a.push_back(123);
    a.push_back(3);
    a.itemSet(6);
    //std::cout<<a.locate(13,[](int a,int b){return int(a==b);});
    a.listPrint([](int a){printf("%d ",a);});

}