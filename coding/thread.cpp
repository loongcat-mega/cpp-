#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::atomic_int acnt;
int cnt;
int right_;
int left_;
void f()
{
    for (int n = 0; n < 100000; ++n)
    {
        ++acnt;
        ++cnt;
        left_++;
        volatile int t=right_;
        t++;
        right_=t;
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
              << "非原子计数器为 " << cnt << '\n'
              << "非原子计数器为 " << right_ << '\n'
              << "非原子计数器为 " << left_ << '\n';
}
