#include <iostream>
#include <string>

#include "utils.hpp"

int main() {

    std::string str_input;

    std::getline(std::cin, str_input);
    std::vector<std::string> vector_str{ split_string(str_input) };


    std::cout << npi_evaluate(vector_str) << std::endl;

    return 0;
}