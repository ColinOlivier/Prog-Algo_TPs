#include <string>
#include <unordered_map>

std::string runLengthEncoding(std::string str);
std::string runLengthDecoding(std::string str);

std::string runLengthEncodingContrChar(std::string str, char const contrChar = '*');
std::string runLengthDecodingContrChar(std::string str, char const contrChar = '*');


std::unordered_map<char, size_t> frequency(std::string str);

struct Node {
    char character;
    size_t frequency;
    Node* left{ nullptr };
    Node* right{ nullptr };

    inline bool operator< (const Node& node);
};

Node* createNode(const char c, const size_t frequency);
Node* createSymbolNode(Node* node_1, Node* node_2);

Node* build_huffman_tree(const std::unordered_map<char, size_t>& frequency_map);