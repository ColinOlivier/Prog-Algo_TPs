#include <stack>
#include "utils.hpp"

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

bool is_floating(std::string const& s)
{
    for (size_t i = 0; i < s.size(); i++)
        if (!(std::isdigit(s[i]) || (s[i] == '.'))) return false;
    return true;
}

float npi_evaluate(std::vector<std::string> const& tokens) {
    std::stack<float> npi_stack;

    for (size_t i = 0; i < tokens.size(); i++)
    {
        if (is_floating(tokens[i])) {
            npi_stack.push(std::stof(tokens[i]));
            continue;
        }

        float top_value{ npi_stack.top() };
        npi_stack.pop();

        float second_value{ npi_stack.top() };
        npi_stack.pop();

        if (tokens[i] == "+") npi_stack.push(second_value + top_value);
        else if (tokens[i] == "-") npi_stack.push(second_value - top_value);
        else if (tokens[i] == "*") npi_stack.push(second_value * top_value);
        else if (tokens[i] == "/") npi_stack.push(second_value / top_value);
        else if (tokens[i] == "^") npi_stack.push(std::powf(second_value, top_value));
    }

    return npi_stack.top();
}