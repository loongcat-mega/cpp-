
## 使用默认值初始化

在C++11以前，对非静态数据成员初始化需要用到初始化列表
C++11标准提出了新的初始化 方法，即在声明非静态数据成员的同时直接对其使用=或者{}（见第9 章）初始化。在此之前只有类型为整型或者枚举类型的常量静态数据成 员才有这种声明默认初始化的待遇

- 不要使用()对非静态数据成员初始化
- 不要使用auto声明和初始化非静态数据成员

## 位域的默认初始化


## 总结

非静态数据成员默认初始化在一定程度上解决了初始化列表代码冗 余的问题，尤其在类中数据成员的数量较多或类重载的构造函数数量较 多时，使用非静态数据成员默认初始化的优势尤其明显

