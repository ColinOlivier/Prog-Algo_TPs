#include <vector>
#include <iostream>
#include "sort.hpp"
#include "utils.hpp"
#include "ScopedTimer.hpp"

int main()
{
    std::vector<int> array{ generate_random_vector(10000) };
    {
        ScopedTimer timer("Bubble sort timer");
        bubble_sort(array);
    }

    array = generate_random_vector(10000);
    {
        ScopedTimer timer("Merge sort timer");
        merge_sort(array);
    }

    array = generate_random_vector(10000);
    {
        ScopedTimer timer("Counting sort timer");
        counting_sort(array);
    }

    array = generate_random_vector(10000);
    {
        ScopedTimer timer("Algorithm sort timer");
        std::sort(array.begin(), array.end());
    }

    int search_value = 8;
    std::vector<int> search_array{ 1, 2, 2, 3, 4, 8, 12 };

    std::cout << "index of " << search_value << " on ";
    display_vector(search_array);
    std::cout << " : " << search(search_array, search_value).value_or(-1) << std::endl;

    search_value = 15;
    search_array = { 1, 2, 3, 3, 6, 14, 12, 15 };

    std::cout << "index of " << search_value << " on ";
    display_vector(search_array);
    std::cout << " : " << search(search_array, search_value).value_or(-1) << std::endl;

    search_value = 16;
    search_array = { 2, 2, 3, 4, 5, 8, 12, 15, 16 };

    std::cout << "index of " << search_value << " on ";
    display_vector(search_array);
    std::cout << " : " << search(search_array, search_value).value_or(-1) << std::endl;

    search_value = 6;
    search_array = { 5, 6, 7, 8, 9, 10, 11, 12, 13 };

    std::cout << "index of " << search_value << " on ";
    display_vector(search_array);
    std::cout << " : " << search(search_array, search_value).value_or(-1) << std::endl;

    search_value = 10;
    search_array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::cout << "index of " << search_value << " on ";
    display_vector(search_array);
    std::cout << " : " << search(search_array, search_value).value_or(-1) << std::endl;

    return 0;
}