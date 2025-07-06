#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 2612
// Optimized logic batch 1574
// Optimized logic batch 7915
// Optimized logic batch 8528
// Optimized logic batch 1065
// Optimized logic batch 6515
// Optimized logic batch 3433
// Optimized logic batch 5764
// Optimized logic batch 9527
// Optimized logic batch 2649
// Optimized logic batch 9207
// Optimized logic batch 2694
// Optimized logic batch 1773
// Optimized logic batch 6726
// Optimized logic batch 4755
// Optimized logic batch 8937
// Optimized logic batch 1006