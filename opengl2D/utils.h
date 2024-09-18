#pragma once
#include <chrono>
#include <iostream>
struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<double> duration = (std::chrono::duration<double>)(0);
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        duration *= 1000.f;
        std::cout << "it took -> " << duration.count() << "ms\n";
    }
};