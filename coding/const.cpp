//
// Created by dlut2102 on 2024/5/2.
//
#include<iostream>
#include<thread>
#include<atomic>
#include<vector>
using namespace std;
int get_0()
{
    return 0;
}
constexpr int get_1()
{
    return 1;
}
#define index1 get_1()
constexpr void get_sum(int n)
{
    n=99999999;
    int sum=0;
    do {
        sum+=n;
    }while(--n);
    //return sum;
}

class A
{
public:
    int a=10;
};
int main()
{
    
    A *a =new A{10};
    A *p=a;
    p->a=20;
    cout<<a->a<<endl;
    
    
    int i=5;
    auto get_size = [](int i) { return i * 2; };
    char buffer1[get_size(i)];
    
    int n=10;
    vector<thread> pool;
   // pool.emplace_back(get_sum);
    //pool.emplace_back(get_sum);

    //cout<<get_sum(9999999)<<endl;
    //cin>>n;
    switch(n)
    {
        case index1:
            cout<<"hello"<<endl;
        default:
            cout<<endl;
    }
    return 0;
    
}