#include <iostream>
#include "hash.hpp"
#include "robot.hpp"
#include "card.hpp"

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(const Card & card) {
            return card.hash();
        }
    };
}

int main() {

    std::cout << folding_string_hash("abc", 99) << std::endl;
    std::cout << folding_string_hash("cba", 99) << std::endl;
    std::cout << folding_string_ordered_hash("abc", 99) << std::endl;
    std::cout << folding_string_ordered_hash("cba", 99) << std::endl;

    std::vector<std::pair<std::string, float>> robots_fix{ get_robots_fix(1000) };

    std::unordered_map<std::string, std::vector<float>> robot_map{ robots_fixes_map(robots_fix) };
    for (const auto& [key, value] : robot_map)
    {
        std::cout << key << " : " << fixies_summary(value) << std::endl;
    }

    std::vector<Card> cards{ get_cards(100) };
    for (const auto& [card, count] : card_count_map(cards))
        std::cout << card_name(card) << " : " << count << std::endl;

    return 0;
}