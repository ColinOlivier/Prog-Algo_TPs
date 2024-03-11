#include "utils.hpp"

void display_vector(std::vector<int> const& vec) {

    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << ", ";
    }

    std::cout << std::endl;
}

std::vector<int> generate_random_vector(size_t const size, int const max) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;});
    return vec;
}