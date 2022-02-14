#include <chrono>
#include <iostream>
#include <thread>

#pragma GCC optimize("-O0")

int main() {
    int data = 0;
    bool finished = false;

    std::thread t([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        // Hmm.
        data = 123;
        finished = true;
    });

    while (!finished) {}
    // Hmm?
    std::cout << data << "\n";

    t.join();
}
