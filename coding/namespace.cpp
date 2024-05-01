//
// Created by dlut2102 on 2024/4/29.
//
#include<iostream>
using namespace std;
namespace s1
{
    inline namespace chv2
    {
        void foo()
        {
            cout<<"version 1.0.1\n";
        }
    }
    namespace ch
    {
        void foo()
        {
            cout<<"version 1.0.0\n";
        }
    }
    int main()
    {
        foo();
        return 0;
    }
   
}
namespace s2
{
    void foo()
    {
        cout<<"this is namesapce s2\n";
    }
}
using namespace s1;
//using namespace s2;
int main()
{
    s1::main();
    s2::foo();
    return 0;
}