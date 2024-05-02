//
// Created by dlut2102 on 2024/5/2.
//
#include<iostream>
using namespace std;
template<class T>
class A
{
public:
    static const int num{8};
    static const int num1=8;
    static const string s{"hello"};
    static  string s1;
    inline static string s2="olleh";
};
template<class T>
string A<T>::s1="world";
int main()
{
    return 0;
}