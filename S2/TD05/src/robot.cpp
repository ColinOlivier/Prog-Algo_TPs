#include <iostream>
#include <cstdlib>
#include <numeric>

#include "robot.hpp"

std::string random_name(size_t size) {
    std::string name{ "" };
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for (size_t i{ 0 }; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix{};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i{ 0 }; i < size; ++i) {
        // random name 
        std::string robotName{ random_name(2) };
        // random cost
        float cost{ static_cast<float>(std::rand()) / RAND_MAX * 1000.0f };
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes)
{
    std::unordered_map<std::string, std::vector<float>> map;
    for (std::pair<std::string, float> robots_fixe : robots_fixes)
    {
        if (map.find(robots_fixe.first) != map.end())
            map[robots_fixe.first].push_back(robots_fixe.second);
        else
            map.insert(std::make_pair(robots_fixe.first, std::vector<float>{robots_fixe.second}));
    }
    return map;
}

float fixies_summary(std::vector<float> fixies_vector)
{
    return std::accumulate(fixies_vector.begin(), fixies_vector.end(), 0.f);
}