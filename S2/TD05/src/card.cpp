#include "card.hpp"

bool Card::operator==(const Card& card) {
    return kind == card.kind && value == card.value;
}

size_t Card::hash() const {
    return static_cast<size_t>(this->kind) * 13 + static_cast<size_t>(this->value);
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards;
    cards.reserve(size);
    for (size_t i{ 0 }; i < size; ++i) {
        cards.push_back({ static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13) });
    }
    return cards;
}

std::unordered_map<Card, size_t> card_count_map(const std::vector<Card>& cards) {
    std::unordered_map<Card, size_t> map;
    for (Card card : cards)
    {
        if (map.find(card) != map.end())
            ++map[card];
        else
            map.insert({ card, 1 });
    }
    return map;
}

std::string card_name(Card const& card) {
    std::string name{};

    unsigned int card_value{ (static_cast<unsigned int>(card.value) + 2) % 14 };

    if (card_value < 10) {
        name += '0' + card_value;
    }
    else if (card_value == 10) {
        name += "10";
    }
    else if (card_value == 11) {
        name += 'V';
    }
    else if (card_value == 12) {
        name += 'Q';
    }
    else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }
    else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }
    else if (card.kind == CardKind::Club) {
        name += "Club";
    }
    else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}