//
// Created by dlut2102 on 2024/4/29.
//
#include<iostream>
#include<limits>
using namespace std;
int main()
{
    cout<<typeid(18ll).name()<<endl;
    cout<<typeid(18).name()<<endl;
    cout<<numeric_limits<int>::max()<<endl;
    cout<<INT_MAX<<endl;
    return 0;
}