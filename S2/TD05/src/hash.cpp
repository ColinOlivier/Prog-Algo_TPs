#include <numeric>
#include <cmath>
#include "hash.hpp"

size_t folding_string_hash(std::string const& s, size_t max) {
    return std::accumulate(s.begin(), s.end(), 0) % max;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max) {
    size_t str_sum{ 0 };
    for (size_t i = 0; i < s.size(); i++)
        str_sum += s[i] * i;

    return str_sum % max;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m) {
    size_t hash{ 0 };
    unsigned int power{ 1 };
    for (size_t i = 0; i < s.size(); i++) {
        hash += (s[i] * power) % m;
        power *= p;
    }
    return hash;
}