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
 
class card {
    public:
        rank m_rank;
        suit m_suit;

        card(rank rank, suit suit) {
            m_rank = rank;
            m_suit = suit;
        }

        const rank getRank() {return m_rank;};
        const suit getSuit() {return m_suit;};
};

class shoe {
    public:
        shoe(int size) {
            for (int i = 0; i < size; i++){
                for (int j = 0; j < 52; j++) {
                    cards.push_back(std::make_unique<card>(rank((j % 13) + 1), suit(j / 13)));
                }
            }
        }

        void shuffleShoe() {
            std::random_device rd;
            std::mt19937 generator(rd());
            std::shuffle(cards.begin(), cards.end(), generator);
        };

        std::unique_ptr<card> drawCard() {
            if(cards.empty()) {
                return nullptr;
            }

            std::unique_ptr<card> drawnCard = std::move(cards.back());
            cards.pop_back();

            return drawnCard;
        }
    private:
        std::vector<std::unique_ptr<card>> cards;
};