#include <iostream>
#include <numeric>
#include "utils.hpp"

int main() {
    std::vector<int> random_vector{ generate_random_vector(1000, 100) };

    for (std::vector<int>::iterator it{ random_vector.begin() }; it != random_vector.end(); ++it)
        std::cout << *it << ", ";

    std::cout << std::endl;

    int valueToFind;
    std::cout << "Entrez un entier a trouver :" << std::endl;
    std::cin >> valueToFind;


    std::vector<int>::iterator it = std::find(random_vector.begin(), random_vector.end(), valueToFind);

    if (it != random_vector.end()) {
        std::cout << valueToFind << " trouver a la position : " << std::distance(random_vector.begin(), it) << std::endl;
        std::cout << "Occurence de " << valueToFind << " : " << std::count(random_vector.begin(), random_vector.end(), valueToFind) << std::endl;
    }

    std::sort(random_vector.begin(), random_vector.end());

    std::cout << "Somme du vecteur : " << std::accumulate(random_vector.begin(), random_vector.end(), 0) << std::endl;

    std::string inputSentence{ "The signature does not need to have const &." };
    std::cout << "Phrase : " << inputSentence << std::endl;
    std::cout << "Taille du premier mot : " << get_first_word_size(inputSentence) << std::endl;

    for (std::string word : split_string(inputSentence))
    {
        std::cout << word << std::endl;
    }

    std::cout << "bateau : " << is_palindrome("bateau") << std::endl;
    std::cout << "radar : " << is_palindrome("radar") << std::endl;

    return 0;
}