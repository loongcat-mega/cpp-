//
// Created by dlut2102 on 2024/5/1.
//
#include<iostream>
#include<type_traits>
using namespace std;
int main()
{
    int a=10;
    const int n=10;
    static_assert(n>0,"shide");
    return 0;
}