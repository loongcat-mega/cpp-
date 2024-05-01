//
// Created by dlut2102 on 2024/4/28.
//
#include<iostream>
using namespace std;
namespace clstest
{
    class A
    {
    public:
        A(){cout<<"默认构造"<<endl;}
        A(const A&a){cout<<"拷贝构造"<<endl;}
        ~A(){cout<<"析构"<<endl;}
        void show(){cout<<"this is show()\n";}
    };
    A get()
    {
        A a;
        // cout<<"get:"<<&a<<endl;
        return a;
    }

    class X {
    public:
        X() {}
        X( X&x) {}
        X& operator = ( const X& x) { return *this; }
    };
    X make_x()
    {
        return X();
    }
    int main()
    {
        X x1;
        X x2(x1);
        x2=x1;
        X x3(make_x());
        x3 = make_x();
        make_x();
        A && a=get();
        a.show();
    }

}
 class BigMemoryPool
{ 
public: 
    static const int PoolSize = 4096; 
    BigMemoryPool() : pool_(new char[PoolSize]) {} 
    ~BigMemoryPool() { if (pool_ != nullptr) { delete[] pool_; } }
    BigMemoryPool(const BigMemoryPool& other) : pool_(new char[PoolSize]) 
    { std::cout << "copy big memory pool." << std::endl; memcpy(pool_, other.pool_, PoolSize); }
private: 
    char *pool_; 
}; 
BigMemoryPool get_pool(const BigMemoryPool& pool)
{ 
    return pool;
} 
BigMemoryPool make_pool()
{ 
    BigMemoryPool pool; 
    return get_pool(pool);
}
class C{
public:
    C (){};
    C (const C&c ){cout<<"copy \n";};
};
C getC()
{
    C c;
    return c;
}
int main() 
{
    //BigMemoryPool my_pool (make_pool());
    //int &bbb=10;
    C && c=getC();
}

