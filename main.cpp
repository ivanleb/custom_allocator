#include <iostream>
#include <vector>
#include <map>
#include "allocator.cpp"


int main(int, char *[]) {
    // auto v = std::vector<int, logging_allocator<int>>{};
    // // v.reserve(5);
    // for (size_t i = 0; i < 2; ++i) {
    //     v.emplace_back(i);
    //     std::cout << std::endl;
    // }

    // for (auto i: v) {
    //     std::cout << i << std::endl;
    // }

    auto m = std::map<int, int, std::less<int>, logging_allocator<std::pair<const int, int>>>{};
    for (size_t i = 0; i < 5; ++i) {
        m[i] = i;
        std::cout << std::endl;
    }

    return 0;
}
