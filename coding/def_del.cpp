//
// Created by dlut2102 on 2024/4/30.
//
#include<iostream>
using namespace std;
class A
{
public:
    int a=10;
    string c="hello";
    A(int n):a(n){}
    A() =default;
    A(const A&)=delete;

    A& operator=(const A&) =delete;
    void * operator new(size_t) =delete;
};
class proxy
{
public:
    int a;
    double b;
    proxy():proxy(0){}
    proxy(int a):proxy(a,0){}
    proxy(double b):proxy(0,b){}
    proxy(int a,double b){commoninit(a,b);}
private:
    void commoninit(int aa,double bb)
    {
        this->a=aa;
        this->b=bb;
    }
};
int main()
{
    A a;
    A&b=a;
    A *p=&a;
    //A *pp=new A;
    int m=0712;
    cout<<m<<endl;
    return 0;
}