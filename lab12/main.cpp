#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex cout_mutex;

void threadFunction(int id) {
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Thread " << id << " starting." << std::endl;
    }
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000 + id * 500));
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Thread " << id << " ending. Duration: " << elapsed.count() << " seconds." << std::endl;
    }
}

int main() {
    const int numThreads = 5;
    std::vector<std::thread> threads;
    for(int i = 1; i <= numThreads; ++i){
        threads.emplace_back(threadFunction, i);
    }
    for(auto &t : threads){
        if(t.joinable()){
            t.join();
        }
    }
    return 0;
}