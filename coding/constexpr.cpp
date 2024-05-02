//
// Created by dlut2102 on 2024/4/29.
//
#include<iostream>
using namespace std;
//auto len=[](int i){return 2*i;};
//constexpr int getlen(int i)
//{
//    return 2*i;
//}
//int get_len(int i)
//{
//    return 2*i;
//}
//int arr[len(5)];
//int arr1[getlen(5)];
//int arr2[get_len(5)];
class A
{
public:
    constexpr A():x1(5){}
    constexpr int get(){return x1;}
    static constexpr int a=10;
private:
    int x1;
};
consteval int  f(int a)
{
    return a*a;
}
int main()
{
    constexpr int b=f(5);
    constexpr int bb=f(6);
    
    int n=20;
    //cin>>n;
    //&n;
    cout<<&A::a<<endl;
    int a[f(5)];
    cout<< sizeof(a)/sizeof(a[0]);
    return 0;
}