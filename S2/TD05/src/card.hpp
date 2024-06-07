#include <vector>
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    bool operator==(const Card& card);

    size_t hash() const;
};

std::vector<Card> get_cards(size_t const size);

std::unordered_map<Card, size_t> card_count_map(const std::vector<Card>& cards);
std::string card_name(Card const& card);
