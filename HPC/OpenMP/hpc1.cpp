#include <bits/stdc++.h>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#define N 100
#define P 4

double a[N], b[N];
double partial_sums[P];
std::mutex mtx;
std::condition_variable cv;
int count = 0;

void barrier(int thread_id) {
    std::unique_lock<std::mutex> lock(mtx);
    count++;
    if (count == P) {
        count = 0;
        cv.notify_all();
    } else {
        cv.wait(lock);
    }
}

void ParallelFunction(int my_id) {
    int start = (N/P) * my_id;
    int end = (N/P) * (my_id + 1) - 1;
    double s = 0.0;
    for (int i = start; i <= end; i++)
        s += a[i] * b[i];
    partial_sums[my_id] = s;
    barrier(my_id);
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < P; i++)
        threads.emplace_back(ParallelFunction, i);
    ParallelFunction(P - 1); 

    double dot_product = 0.0;
    for (int i = 0; i < P; i++)
        dot_product += partial_sums[i];
    std::cout << "The dot product = " << dot_product << std::endl;
    for (auto& thread : threads)
        thread.join();

    return 0;
}



