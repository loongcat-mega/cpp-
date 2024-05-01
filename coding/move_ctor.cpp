//
// Created by dlut2102 on 2024/4/29.
//
#include<bits/stdc++.h>
using namespace std;
class A
{
public:
    int *p;
    A()
    {
        p=new int(10);
        cout<<"default ctor\n";
    }
    ~A()
    {
        cout<<"delete ctor\n";
        
        if(p==nullptr)
            delete p;
    }
    A ( const A& a)
    {
        cout<<"copy ctor\n";

        *p=*(a.p);
        //return *this;
    }
    A operator= (const A &&a)
    {
        cout<<"equal ctor\n";
        *p=*(a.p);
        return *this;
    }
    A( A&& a)
    {
        cout<<"move ctor\n";
        
        p=a.p;
        a.p=nullptr;
    }
};
A getA()
{
    A a;
    cout<<"getA() :"<<a.p <<endl;  
    return a;
}
int main()
{
    A a=getA();
    cout<<"main() :"<<a.p <<endl;

    return 0;
}