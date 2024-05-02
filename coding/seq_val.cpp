//
// Created by dlut2102 on 2024/5/2.
//
#include<iostream>
using namespace std;
int fa(int a)
{
    cout<<"fa"<<endl;
    return a;
}
int fb(int a)
{
    cout<<"fb"<<endl;
    
    return a;
}
int fc(int a)
{
    cout<<"fc"<<endl;
    
    return a;
}
int get_sum(int a,int b,int c)
{
    cout<<"sum"<<endl;
    
    return a+b+c;
}
int main()
{
    int a=get_sum(fa(1),fb(2),fc(3));
    return 0;
}