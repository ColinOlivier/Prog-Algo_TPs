#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>

std::vector<int> generate_random_vector(size_t const size, int const max = 100);
unsigned int get_first_word_size(std::string const& str);

std::vector<std::string> split_string(std::string const& str);

bool is_palindrome(std::string const& str);