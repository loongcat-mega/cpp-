//
// Created by dlut2102 on 2024/4/28.
//
#include<iostream>
using namespace std;
void f() noexcept(true){cout<<"NONO"<<endl;}
void ff()noexcept(false){}
template <class T>
T copy(const T &o) noexcept(noexcept(T(o))){}
//template<class T> 
//void swap(T& a, T& b) 
//noexcept(noexcept(T(std::move(a))) && noexcept(a.operator=(std::move(b)))) 
//{ 
//    T tmp(std::move(a)); a = std::move(b); b = std::move(tmp);
//}

template<typename T> 
void swap(T& a, T& b)
noexcept(noexcept(swap_impl(a, b, std::integral_constant<bool, noexcept(T(std::move(a))) 
        && noexcept(a.operator=(std::move(b)))>())))
{ 
    swap_impl(a, b, std::integral_constant<bool, noexcept(T(std::move(a))) 
            &&noexcept(a.operator=(std::move(b)))>()); 
}


int main()
{
    cout<<boolalpha;
    cout<<noexcept(f())<<endl;//true
    cout<<noexcept(ff())<<endl;//false
    cout<<noexcept(true)<<endl;//true
    cout<<noexcept(false)<<endl;//true
    int a=copy(8);
    return 0;
}