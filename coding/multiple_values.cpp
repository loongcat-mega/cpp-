//
// Created by dlut2102 on 2024/4/28.
//
#include<iostream>
#include<tuple>
#include <iomanip>
#include <set>
#include <string>
using namespace std;
auto mv(int a,int b)
{
    return make_tuple(a*b,a+b);
}
auto mv3(int a,int b)
{
    return make_tuple(a*b,a+b,a/b);
}
class A
{
public:
    int a=10;
    int b=20;
    A(int aa=10,int bb=20)
    {
        a=aa;
        b=bb;
    }
    int get(int aa)
    {
        return aa*10;
    }
};
int main()
{
   auto [ra,rb]=mv(10,20);
   auto k=mv3(10,20);
   ;
   cout<<ra<<","<<rb<<endl;
   A AA(5);
   auto [a,b]=AA;
    cout<<a<<","<<b<<endl;
    a=50;
    cout<<AA.a<<","<<AA.b<<endl; 
    
    int arr[3]={1,2,3};
    auto [x,y,z]=arr;
    
    set<string> myset{"hello"};
    for (int i{2}; i; --i)
    {
        if (auto [iter, success] = myset.insert("Hello"); success)
            std::cout << "����ɹ���ֵΪ " << std::quoted(*iter) << "��\n";
        else
            std::cout << "�������Ѵ���ֵ " << std::quoted(*iter) << "��\n";
    }
    for(int i{10};i;i--)
    {
        cout<<"i=="<<i<<endl;
    }
    
}