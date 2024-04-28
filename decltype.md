
[decltype 说明符](https://zh.cppreference.com/w/cpp/language/decltype#Popover19-toggle:~:text=decltype%20%E8%AF%B4%E6%98%8E%E7%AC%A6)
推导实体和表达式类型


gcc 扩展 typeof可以获取变量类型
```cpp
int a=10;
typeof(a) b=10;
```
typeid 可以返回一个type_info类型的对象，记录了类型的标识符和类型名
只能在运行时做类型甄别，不能在编译器识别

```cpp
cout<<typeid(typeid(int)).name()<<endl;//N10__cxxabiv123__fundamental_type_infoE
cout<<typeid(int).name()<<endl;//i
cout<<typeid(double).name()<<endl;//d
cout<<typeid(float).name()<<endl;//f
cout<<typeid(bool).name()<<endl;//b
cout<<typeid(char).name()<<endl;//c
cout<<typeid(string).name()<<endl;//NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
int arr[5]={1,2,3};  
double arr1[5]={1,2,3};  
cout<<typeid(arr).name()<<endl;//A5_i  
cout<<typeid(arr1).name()<<endl;//A5_d
```

decltype用法与typeof类似，能够鉴别对象或表示式的类别

![image.png](https://yaaame-1317851743.cos.ap-beijing.myqcloud.com/20240428201152.png)


在C++中，“&&”符号表示右值引用类型。它通常与移动语义相关联，允许在不必要复制的情况下有效地从一个对象转移资源（如内存）到另一个对象。

```cpp
const int && foo(){return 40;}
struct A
{
    double a;
};
```

![image.png](https://yaaame-1317851743.cos.ap-beijing.myqcloud.com/20240428202441.png)


const右值引用无法绑定到左值
![image.png](https://yaaame-1317851743.cos.ap-beijing.myqcloud.com/20240428203509.png)

但是可以这么修改
![image.png](https://yaaame-1317851743.cos.ap-beijing.myqcloud.com/20240428203645.png)

decltype(e)会同步e的cv限定符