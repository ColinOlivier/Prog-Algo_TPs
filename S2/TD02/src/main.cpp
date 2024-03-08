#include <vector>
#include <iostream>
#include "sort.hpp"

int main()
{
    std::vector<int> array{ 1, 2, 6, 4, 5, 6, 7, 8, 9 };

    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    }
    else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }

    return 0;
}