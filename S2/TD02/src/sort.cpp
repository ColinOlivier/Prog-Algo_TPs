#include <algorithm>
#include <iostream>
#include "sort.hpp"
#include "utils.hpp"

bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

// ###################
// ### bubble_sort ###
// ###################

void bubble_sort(std::vector<int>& vec) {

    int nbElementToSkip{ 0 };
    while (nbElementToSkip < vec.size())
    {
        for (size_t i = 0; i < vec.size() - (nbElementToSkip + 1); i++)
        {
            if (vec[i] < vec[i + 1]) continue;
            std::swap(vec[i], vec[i + 1]);
        }
        ++nbElementToSkip;
    }
}

// ##################
// ### merge_sort ###
// ##################

void merge_sort_merge(std::vector<int>& vec, size_t const left, size_t const middle, size_t const right) {

    size_t const left_size{ middle - left + 1 };
    size_t const right_size{ right - middle };

    std::vector<int> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<int> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    size_t left_index{ 0 };
    size_t right_index{ 0 };

    size_t index{ left };

    while (left_index < left_size && right_index < right_size) {
        if (left_vec[left_index] < right_vec[right_index]) {
            vec[index] = left_vec[left_index];
            ++left_index;
        }
        else {
            vec[index] = right_vec[right_index];
            ++right_index;
        }
        ++index;
    }

    while (left_index < left_size) {
        vec[index] = left_vec[left_index];
        ++left_index;
        ++index;
    }
    while (right_index < right_size) {
        vec[index] = right_vec[right_index];
        ++right_index;
        ++index;
    }
}

void merge_sort(std::vector<int>& vec, size_t const left, size_t const right) {

    if ((right - left) < 1) {
        return;
    }

    size_t const middle{ left + ((right - left) / 2) };
    merge_sort(vec, left, middle);
    merge_sort(vec, middle + 1, right);

    merge_sort_merge(vec, left, middle, right);
}

void merge_sort(std::vector<int>& vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

std::optional<size_t> search(std::vector<int>& vec, int const search_value, size_t const left, size_t const right) {
    if (left > right) return {};

    size_t middle = left + (right - left) / 2;

    if (vec[middle] == search_value) return middle;

    if (vec[middle] > search_value)
    {
        return search(vec, search_value, left, middle);
    }

    return search(vec, search_value, middle + 1, right);
}

std::optional<size_t> search(std::vector<int>& vec, int const search_value) {
    return search(vec, search_value, 0, vec.size() - 1);
}