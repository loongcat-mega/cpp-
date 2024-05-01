//
// Created by dlut2102 on 2024/5/1.
//
#include<iostream>
using namespace std;
class A
{
public:
    int a=0;
    A(int a_):a(a_){};
};
class B:public A
{
public:
    //using A::A;
    int b;
};
int main()
{
    cout<<is_aggregate_v<A> <<endl;
    cout<<is_aggregate_v<B> <<endl;
    B b{10,5};
    cout<<b.a<<endl;
    cout<<b.b<<endl;
    return 0;
}