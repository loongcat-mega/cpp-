//
// Created by dlut2102 on 2024/4/29.
//
//
// Created by dlut2102 on 2024/4/29.
//
#include<iostream>
using namespace std;
class A
{
public:
    char c1='0';
    int a=10;
    int b=10;
    char c2='1';
    
};
constexpr int fb(int n)
{
    int a=1,b=1,c=1;
    for(int i=3;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main()
{
    int a=10;
    auto pr=[a]()mutable noexcept  ->int {return a*10;};
    auto p= [=](){a*10;};
    cout<<sizeof p<<endl;
//    A aa;
//    auto pa=[&](){cout<<aa.a<<endl;};
//    cout<<sizeof pa<<endl;
    cout<<fb(10)<<endl;
    return 0;
}