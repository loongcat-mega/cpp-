//
// Created by dlut2102 on 2024/5/1.
//
#include<iostream>
#include<cassert>
using namespace std;
constexpr  bool flag(const int& n)
{
    return n&1;
}
void check(const int &n)
{
    assert(n>0);
}
int main()
{
    int n=8;
    cin>>n;
    check(n);
    if(bool b=flag(n);b)
    {
        cout<<"b"<<endl;
    }
    else if(bool b2=flag(n+1);b2)
    {
        cout<<"b1"<<endl;
        
    }
    const int b=80;
    static_assert(b/81>0);
    return 0;
}