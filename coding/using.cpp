//
// Created by dlut2102 on 2024/5/1.
//
#include<iostream>
#include<map>
#include<cassert>
using namespace std;
template<class T> 
using int_map = map<int, T>;
void foo(int ){cout<<"int"<<endl;}
void foo(char* ){cout<<"char *"<<endl;}
using lli = long long int;
int main()
{
    nullptr_t  p1;
    int_map<string>is;
    const int *p=p1;
    cout<< typeid(nullptr).name();
    assert(p== nullptr);
    cout<<(1 <=>8 > 0)<<endl;
    //foo(NULL);
    return 0;
}