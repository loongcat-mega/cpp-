//
// Created by dlut2102 on 2024/5/1.
//
#include<iostream>
using namespace std;
class A
{
public:
    virtual void foo(int){}
    virtual void fun  (int) final {}
};
class B:public A
{
public:
    virtual void foo(char){cout<<"B overwrite"<<endl;}
    virtual void foo(int)override{cout<<"B override"<<endl;}
    //void fun  (int)  {}
};
int main()
{
    B b;
    b.foo(1);
    b.foo('a');
    return 0;
}