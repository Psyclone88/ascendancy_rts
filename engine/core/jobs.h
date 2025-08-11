#pragma once
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <vector>

class JobSystem {
    std::vector<std::thread> workers;
    std::mutex m;
    std::condition_variable cv;
    std::queue<std::function<void()>> q;
    bool stop=false;
public:
    void start(unsigned n=std::thread::hardware_concurrency()){
        for(unsigned i=0;i<(n?n:2);++i){
            workers.emplace_back([this]{
                for(;;){
                    std::function<void()> job;
                    { std::unique_lock<std::mutex> lk(m);
                      cv.wait(lk,[&]{return stop||!q.empty();});
                      if(stop && q.empty()) return;
                      job=std::move(q.front()); q.pop();
                    }
                    job();
                }
            });
        }
    }
    void enqueue(std::function<void()> f){ {std::lock_guard<std::mutex>lk(m); q.push(std::move(f));} cv.notify_one(); }
    void finish(){ {std::lock_guard<std::mutex>lk(m); stop=true;} cv.notify_all(); for(auto& w:workers) w.join(); workers.clear(); stop=false; }
};
extern JobSystem g_jobs;
