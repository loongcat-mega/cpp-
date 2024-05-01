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
        // ע��: ���ڴ�ʾ���������ڴ涨���Ѿ��㹻��
        // ���� acnt.fetch_add(1, std::memory_order_relaxed);
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

    std::cout << "ԭ�Ӽ�����Ϊ " << acnt << '\n'
              << "��ԭ�Ӽ�����Ϊ " << cnt << '\n'
              << "��ԭ�Ӽ�����Ϊ " << right_ << '\n'
              << "��ԭ�Ӽ�����Ϊ " << left_ << '\n';
}
