既是说明符，又是运算符
只关心是否抛出异常

作为说明符，在函数末尾添加noexpect即可，表示该函数声明为不会抛出异常的函数，如果函数抛出异常，则会终止程序

noexpect可以接受一个bool类型的常量表达式，决定该函数是否可以抛出异常，默认情况是true

作为运算符，noexpect(f)表示该函数是否可以抛出异常

```cpp
#include<iostream>
using namespace std;
void f() noexcept{}
void ff(){}
int main()
{
    cout<<boolalpha;
    cout<<noexcept(f())<<endl;//true
    cout<<noexcept(ff())<<endl;//false
    return 0;
}
```

为了解决移动构造问题？(c++11引入)

默认构造、默认拷贝构造、默认赋值函数、默认移动构造函数、默认移动赋值函数、默认析构函数等都默认使用noexpect
使用noexpect的对应的函数在类型的基类和成员中也具有noexpect声明

**使用时要谨慎，确保函数一定不会抛出异常才使用noexpect声明**

或者

**抛出异常就直接终止**