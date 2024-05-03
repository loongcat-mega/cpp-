
## 创建线程
创建线程thread(fun_name)
```cpp
thread th([](int a){cout<<a<<endl;},10);
```

## 等待线程执行完毕
等待线程执行完毕join,阻塞式的
如果没有join，主程序如果比线程函数早结束，就会报错
```cpp
thread th([]{cout<<"yes";});  
thread th1([]{cout<<"no";});  
th.join();  
th1.join();
```
## 分离线程

分离线程detach，分离子线程和主线程,主线程结束 子线程依旧可以运行

```cpp
th1.detach();
```
![image.png](https://yaaame-1317851743.cos.ap-beijing.myqcloud.com/20240503225049.png)

控制台没有输出任何内容，因为主线程结束之后，控制台接收不到输出



joinable()判断线程是不是可以调用join/detach
```cpp
thread th([](int a){cout<<a<<endl;},10);  
if(bool b=th.joinable();b)  
    th.join();
```


如果传参是引用，则需使用ref函数
```cpp
int a=10;
thread th1([](int& a){a++;},ref(a));
 
```
运行的过程中要注意对象传输的对象是否被提前释放掉了(指针/引用传参)


## 多线程数据共享问题

如果多个线程同时访问同一个变量，并且至少有一个线程对该变量进行了写操作，那么就会出现数据竞争问题。

```cpp
//
// Created by dlut2102 on 2024/5/3.
//
#include<iostream>
#include<thread>
#include<vector>
using namespace std;
namespace s1
{
    int a=0;
    int i=0;
    void change()
    {
        for(;i<100000;i++)
            a++;
    }
    void threadpool()
    {
        vector<thread>pool;
        for(int j=0;j<10;j++)
            pool.emplace_back(change);

        for(thread& t : pool)
            t.join();
        
    }
    
}
int main()
{
   
    s1::threadpool();
    cout<<s1::a<<endl;
    return 0;
}
```

结果不定，大概率不是100000
因为多个线程共同访问了共享资源a

### 互斥量

修改共享资源之前加锁



```cpp
//
// Created by dlut2102 on 2024/5/3.
//
#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
using namespace std;
namespace s1
{
    int a=0;
    
    mutex mtu;
    void change()
    {
        for(int i=0;i<10000;i++)
        {
            mtu.lock();
            a++;
            mtu.unlock();
        }
    }
    void threadpool()
    {
        vector<thread>pool;
        for(int j=0;j<3;j++)
            pool.emplace_back(change);

        for(thread& t : pool)
            t.join();
        
    }
    
}
int main()
{
   
    s1::threadpool();
    cout<<s1::a<<endl;
    return 0;
}
```

#### 可能会产生死锁问题

互斥和持有并等待

```cpp
namespace s2
{
    mutex x1,x2;
    void f1()
    {
        for(int i=0;i<5000;i++)
        {
            x1.lock();
            x2.lock();
            x1.unlock();
            x2.unlock();
        }
        

    }
    void f2()
    {
        for(int i=0;i<5000;i++)
        {
            x2.lock();
            x1.lock();
            x1.unlock();
            x2.unlock();
        }
      
    }
    void contrast()
    {
        thread t1,t2;
        t1=thread(f1);
        t2=thread(f2);
        t1.join();
        t2.join();
        
        cout<<"fasdfds"<<endl;
    }
    
}
```

