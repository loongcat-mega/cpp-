//
// Created by dlut2102 on 2024/4/28.
//
#include<iostream>
using namespace std;
const int && foo(){return 40;}
struct A
{
    double a;
};
template<class T1,class T2>
auto sum(T1 a,T2 b)-> decltype(a+b)
{
    return a+b;
}
int main()

{
    int va=15;
    double vb=2.5;
    cout<<sum(va,vb)<<endl;
    cout<<sum(vb,va)<<endl;
    decltype(sum(10,10)) vva;
    int a=10;
    auto &tid=typeid(int);
    decltype(a) b=20;
    decltype((a)) c=a; 
    cout<<a<<" "<<b<<" "<<c<<endl;
    cout<<typeid(typeid(int)).name()<<endl;//N10__cxxabiv123__fundamental_type_infoE
    cout<<typeid(int).name()<<endl;//i
    cout<<typeid(double).name()<<endl;//d
    cout<<typeid(float).name()<<endl;//f
    cout<<typeid(bool).name()<<endl;//b
    cout<<typeid(char).name()<<endl;//c
    int arr[5]={1,2,3};
    double arr1[5]={1,2,3};
    cout<<typeid(arr).name()<<endl;//An_i
    cout<<typeid(arr1).name()<<endl;//An_d
    cout<<typeid(string).name()<<endl;//NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    
    
    
    A aaa;
    decltype(aaa.a) a1=0 ;
    double d=1.5;
    decltype((aaa.a)) b1=d ;
    decltype(foo()) c1=move(a) ;
    //或者将c1声明为左值引用
    decltype(foo()) &c2=a ;
    
    
    cout<<a1<<","<<b1<<","<<c1<<endl;
    
    int i=0;
    cout<<&(++i)<<endl; 
    
}