#include "encoding.hpp"
#include <cctype>
#include <queue>

std::string runLengthEncoding(std::string str) {
    std::string r_str{};
    size_t repetionCount{ 0 };
    for (size_t i = 1; i < str.size(); i++)
    {
        std::string repetionCode{};
        if (str[i] != str[i - 1]) {
            if (repetionCount == 0)
                r_str += str[i - 1];
            else
            {
                r_str += std::to_string(repetionCount + 1) + str[i - 1];
                repetionCount = 0;
            }
        }
        else {
            ++repetionCount;
        }
    }
    r_str += std::to_string(repetionCount + 1) + str[str.size() - 1];
    return r_str;
}

std::string runLengthDecoding(std::string str) {
    std::string r_str{};
    std::string digit_str{};
    for (size_t i = 0; i < str.size(); i++)
    {
        if (std::isdigit(str[i])) {
            digit_str += str[i];
        }
        else {
            if (digit_str == "")
                r_str += str[i];
            else {
                for (size_t j = 0; j < std::stoi(digit_str); j++)
                    r_str += str[i];
                digit_str = "";
            }

        }
    }

    return r_str;
}

std::string runLengthEncodingContrChar(std::string str, char const contrChar) {
    std::string r_str{};
    size_t repetionCount{ 0 };
    for (size_t i = 1; i < str.size(); i++)
    {
        std::string repetionCode{};
        if (str[i] != str[i - 1]) {
            if (repetionCount == 0)
                r_str += str[i - 1];
            else
            {
                r_str += contrChar + std::to_string(repetionCount + 1) + str[i - 1];
                repetionCount = 0;
            }
        }
        else {
            ++repetionCount;
        }
    }
    r_str += contrChar + std::to_string(repetionCount + 1) + str[str.size() - 1];
    if (str.size() < r_str.size())
        return str;
    return r_str;
}

std::string runLengthDecodingContrChar(std::string str, char const contrChar) {
    std::string r_str{};
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == contrChar) {
            i++;
            std::string digit_str{};
            while (std::isdigit(str[i]))
            {
                digit_str += str[i];
                ++i;
            }
            for (size_t j = 0; j < std::stoi(digit_str); j++)
                r_str += str[i];
        }
        else {
            r_str += str[i];
        }
    }
    return r_str;
}

std::unordered_map<char, size_t> frequency(std::string str) {
    std::unordered_map<char, size_t> freq_map;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (freq_map.find(str[i]) != freq_map.end())
            freq_map[str[i]]++;
        else
            freq_map.insert({ str[i], 1 });
    }
    return freq_map;
}

inline bool Node::operator< (const Node& node) {
    return (this->frequency < node.frequency);
}

Node* createNode(const char c, const size_t frequency) {
    return new Node{ c, frequency };
}

Node* createSymbolNode(Node* node_1, Node* node_2) {
    return new Node{ '0', node_1->frequency + node_2->frequency, node_1, node_2 };
}

Node* build_huffman_tree(const std::unordered_map<char, size_t>& frequency_map) {
    return nullptr;
}