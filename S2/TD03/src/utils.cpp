#include <stack>
#include <iostream>
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

float npi_evaluate(std::vector<std::string> const& tokens)
{
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


Token make_token(float value)
{
    return Token{ TokenType::OPERAND, value };
}

Token make_token(Operator op)
{
    return Token{ TokenType::OPERATOR, 0.0f, op };
}

std::vector<Token> tokenize(std::vector<std::string> const& words)
{
    std::vector<Token> token_vector;
    for (std::string word : words)
    {
        if (is_floating(word))
        {
            token_vector.push_back(make_token(std::stof(word)));
            continue;
        }

        Operator operator_current;
        if (word == "+") operator_current = Operator::ADD;
        else if (word == "-") operator_current = Operator::SUB;
        else if (word == "*") operator_current = Operator::MUL;
        else if (word == "/") operator_current = Operator::DIV;
        else if (word == "^") operator_current = Operator::POW;

        token_vector.push_back(make_token(operator_current));
    }

    return token_vector;
}

float npi_evaluate(std::vector<Token> const& tokens)
{
    std::stack<float> npi_stack;

    for (Token token : tokens)
    {
        if (token.type == TokenType::OPERAND)
            npi_stack.push(token.value);
        else
        {
            float top_value{ npi_stack.top() };
            npi_stack.pop();

            float second_value{ npi_stack.top() };
            npi_stack.pop();

            switch (token.op)
            {
            case Operator::ADD:
                npi_stack.push(second_value + top_value);
                break;
            case Operator::SUB:
                npi_stack.push(second_value - top_value);
                break;
            case Operator::MUL:
                npi_stack.push(second_value * top_value);
                break;
            case Operator::DIV:
                npi_stack.push(second_value / top_value);
                break;
            case Operator::POW:
                npi_stack.push(std::powf(second_value, top_value));
                break;
            default:
                break;
            }
        }

    }

    return npi_stack.top();
}