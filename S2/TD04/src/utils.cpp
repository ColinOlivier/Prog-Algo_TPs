#include "utils.hpp"

auto const is_space = [](char letter) { return letter == ' '; };

std::vector<int> generate_random_vector(size_t const size, int const max) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;});
    return vec;
}

unsigned int get_first_word_size(std::string const& str) {
    std::string::const_iterator firstSpaceIt{ std::find_if(str.begin(), str.end(), is_space) };

    if (firstSpaceIt == str.end())
        return 0;

    return std::distance(str.begin(), firstSpaceIt);
}

std::vector<std::string> split_string(std::string const& str) {

    std::string::const_iterator spaceIt{ str.begin() };
    std::string::const_iterator nextSpaceIt{ std::find_if(str.begin(), str.end(), is_space) };

    std::vector<std::string> split_string_vector{};
    while (nextSpaceIt != str.end())
    {
        split_string_vector.push_back(std::string(spaceIt, nextSpaceIt));
        spaceIt = nextSpaceIt + 1;
        nextSpaceIt = std::find_if(spaceIt, str.end(), is_space);
    }
    return split_string_vector;
}

bool is_palindrome(std::string const& str)
{
    return std::equal(str.cbegin(), str.cbegin() + str.size() / 2, str.crbegin());
}