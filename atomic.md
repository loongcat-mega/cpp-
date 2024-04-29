每个 std::atomic 模板的实例化和全特化均定义一个原子类型。如果一个线程写入原子对象，同时另一线程从它读取，那么行为有良好定义（数据竞争的细节见内存模型）。 

是一个struct类型

```cpp
    struct atomic<unsigned int> : __atomic_base<unsigned int>
    {
      typedef unsigned int		__integral_type;
      typedef __atomic_base<unsigned int> 	__base_type;

      atomic() noexcept = default;
      ~atomic() noexcept = default;
      atomic(const atomic&) = delete;
      atomic& operator=(const atomic&) = delete;
      atomic& operator=(const atomic&) volatile = delete;

      constexpr atomic(__integral_type __i) noexcept : __base_type(__i) { }

      using __base_type::operator __integral_type;
      using __base_type::operator=;

#if __cplusplus >= 201703L
    static constexpr bool is_always_lock_free = ATOMIC_INT_LOCK_FREE == 2;
#endif
    };
```


多线程：
```cpp
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::atomic_int acnt;
int cnt;

void f()
{
    for (int n = 0; n < 100000; ++n)
    {
        ++acnt;
        ++cnt;
        // 注意: 对于此示例，宽松内存定序已经足够，
        // 例如 acnt.fetch_add(1, std::memory_order_relaxed);
    }
}

int main()
{
    {
        std::vector<std::thread> pool;
        for (int n = 0; n < 10; ++n)
            pool.emplace_back(f);

        for (auto& th : pool)
            th.join();
    }

    std::cout << "原子计数器为 " << acnt << '\n'
              << "非原子计数器为 " << cnt << '\n';
}

```

![image.png](https://yaaame-1317851743.cos.ap-beijing.myqcloud.com/20240429093800.png)

