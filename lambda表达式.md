
```c++
[](){};
[捕获列表](函数参数){函数体};
[]{}不能缺省
()可以缺省
```

#### 捕获列表[]
捕获非静态局部变量
捕获值，捕获的变量不能修改，因为operator()默认是const的，加mutable可以修改,但再次访问会继承上次修改的值，若将Lambda表达式看成仿函数，则捕获值相当于类的成员变量
```c++
int x=0;
auto foo=[x]()mutable{x++;};
foo();//x=1
foo();//x=2
foo();//x=3
```

![image.png](https://yaaame-1317851743.cos.ap-beijing.myqcloud.com/20240428212737.png)


![image.png](https://yaaame-1317851743.cos.ap-beijing.myqcloud.com/20240428212806.png)


捕获引用可以修改
```c++
auto foo=[&x]{x++;};
```

```c++
[this] 捕获this指针
[=]捕获lambda表达式定义作用域的全部变量的值
[&]捕获lambda表达式定义作用域的全部变量的引用

```


```cpp
int a=10;  
auto p= [=](){};  
cout<<sizeof p<<endl;  //1
return 0;
```
展开后：
```cpp
class __lambda_9_12
{
public: 
inline void operator()() const
{
}

// inline /*constexpr */ __lambda_9_12(__lambda_9_12 &&) noexcept = default;

};
```
如果捕获列表的值未被lambda表达式使用，则不会成为类成员

![image.png](https://yaaame-1317851743.cos.ap-beijing.myqcloud.com/20240429104809.png)

如果变量是const而非volatile 的整形或枚举型，并且已经用常量表达式初始化，或者是constexpr且没有mutable成员，则不需要捕获


![image.png](https://yaaame-1317851743.cos.ap-beijing.myqcloud.com/20240429105107.png)

![image.png](https://yaaame-1317851743.cos.ap-beijing.myqcloud.com/20240429105316.png)
