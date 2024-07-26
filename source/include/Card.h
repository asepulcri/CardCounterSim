#include <vector>
#include <memory>
#include <random>
#include <algorithm>

enum rank {
    ace = 1,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king
};

enum suit {
    clubs = 0,
    diamonds = 1,
    hearts = 2,
    spades = 3
};
 
class Card {
    public:
        rank m_rank;
        suit m_suit;

        Card(rank rank, suit suit) {
            m_rank = rank;
            m_suit = suit;
        }

        const rank getRank() {return m_rank;};
        const suit getSuit() {return m_suit;};
};

class Shoe {
    public:
        Shoe(int size) {
            for (int i = 0; i < size; i++){
                for (int j = 0; j < 52; j++) {
                    Cards.push_back(std::make_unique<Card>(rank((j % 13) + 1), suit(j / 13)));
                }
            }
        }

        void shuffleShoe() {
            std::random_device rd;
            std::mt19937 generator(rd());
            std::shuffle(Cards.begin(), Cards.end(), generator);
        };

        std::unique_ptr<Card> drawCard() {
            if(Cards.empty()) {
                return nullptr;
            }

            std::unique_ptr<Card> drawnCard = std::move(Cards.back());
            Cards.pop_back();

            return drawnCard;
        }
    private:
        std::vector<std::unique_ptr<Card>> Cards;
};