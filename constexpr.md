
**constexpr 说明符（c++11起）声明可以在编译时对函数或变量求值**。这些变量和函数（给定了合适的函数实参的情况下）即可用于需要编译期常量表达式的地方。 

（c++11之前无法保证常量像字面量一样作为数组长度或case语句的标签）

对象或非静态成员函数 (C++14 前)声明中的 constexpr 说明符蕴含 const。函数或静态数据成员 (C++17 起)声明中的 constexpr 说明符蕴含 inline。如果函数或函数模板的一个声明拥有 constexpr 说明符，那么它的所有声明都必须含有该说明符


## 变量

constexpr 变量必须满足下列要求：

它的类型**必须是字面类型 (LiteralType)**
它必须立即被初始化
它的初始化（包括所有隐式转换、构造函数调用等）的全表达式必须是**常量表达式** 

```cpp
int a=10;
constexpr int b=a;//错误，因为无法用运行期间的变量去初始化一个编译期间的变量

/home/insights/insights.cpp:7:15: error: constexpr variable 'b' must be initialized by a constant expression
    7 | constexpr int b=a;
      |               ^ ~
/home/insights/insights.cpp:7:17: note: read of non-const variable 'a' is not allowed in a constant expression
    7 | constexpr int b=a;
```

c++17之后，lambda表达式在条件允许情况下也可以隐式声明为为constexpr，如下:
```cpp
auto len=[](int i){return 2*i;};  
int arr[len(5)];
```
lambda表达式的值竟然可以作为数组长度

![image.png](https://yaaame-1317851743.cos.ap-beijing.myqcloud.com/20240429100347.png)




## 函数

非虚
不能是try块

不能是协程(c++20起)

c++11起：
函数体必须被弃置或预置，或只含有下列内容： 
空语句（仅分号）
static_assert 声明
不定义类或枚举的 typedef 声明及别名声明
using 声明
using 指令
当函数不是构造函数时，有恰好一条 return 语句 

c++14起：
函数体必须不含： 
goto 语句
带有除 case 和 default 之外的标号的语句 
try 块
asm 声明
不进行初始化的变量定义 
非字面类型的变量定义
静态或线程存储期变量的定义 


使用consteval声明立即函数，确保在编译期间就可以计算








## 构造函数

每个被选用于初始化非静态成员和基类的构造函数必须都是 constexpr 构造函数。
构造函数初始化列表必须为常量表达式，且函数体必须为空 --> 字面量类型(c++11标准太过严格了)





```cpp
class A
{
public:
    A():x1(5){}
    int get(){return x1;}
private:
    int x1;
};

constexpr A a;//报错

/home/insights/insights.cpp:18:17: error: constexpr variable cannot have non-literal type 'const A'
   18 |     constexpr A a;
      |                 ^
/home/insights/insights.cpp:8:7: note: 'A' is not literal because it is not an aggregate and has no constexpr constructors other than copy or move constructors
    8 | class A
      |       ^
1 error generated.
Error while processing /home/insights/insights.cpp.

```
解决方案：
```cpp
class A
{
public:
    constexpr A():x1(5){}
    constexpr int get(){return x1;}
private:
    int x1;
};
```


类展开后为：
```cpp
class A
{
  
  public: 
  inline constexpr A()
  : x1{5}
  {
  }
  
  inline constexpr int get()
  {
    return this->x1;
  }
  
  
  private: 
  int x1;
  public: 
};
```


