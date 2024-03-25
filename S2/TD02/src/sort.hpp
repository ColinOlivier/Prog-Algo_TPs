#include <vector>
#include <optional>

bool is_sorted(std::vector<int> const& vec);

void bubble_sort(std::vector<int>& vec);

void merge_sort_merge(std::vector<int>& vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<int>& vec, size_t const left, size_t const right);
void merge_sort(std::vector<int>& vec);

void counting_sort(std::vector<int>& vec, int const max);
void counting_sort(std::vector<int>& vec);

std::optional<size_t> search(std::vector<int>& vec, int const search_value, size_t const left, size_t const right);
std::optional<size_t> search(std::vector<int>& vec, int const search_value);