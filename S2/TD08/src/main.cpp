#include "encoding.hpp"
#include <iostream>

int main() {
    std::cout << runLengthEncoding("AAAABBBCCDAA") << std::endl;
    std::cout << runLengthDecoding("12A3B2C1D2A") << std::endl;
    std::cout << runLengthEncodingContrChar("AAAABBBCCDAA") << std::endl;
    std::cout << runLengthDecodingContrChar("*4A*3B*2CD*2A") << std::endl;
    return 0;
}