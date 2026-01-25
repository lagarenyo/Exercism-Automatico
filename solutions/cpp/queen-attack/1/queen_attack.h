#include <stdexcept>
#include <utility>

using namespace std;

#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

namespace queen_attack
{
    class chess_board
    {
    private:
        pair<int, int> pos_white;
        pair<int, int> pos_black;

        bool check_rank(int num);

    public:
        chess_board(std::pair<int, int> white, std::pair<int, int> black);
        bool can_attack() const;
        pair<int, int> white() const;
        pair<int, int> black() const;
    };

} // namespace queen_attack

#endif // QUEEN_ATTACK_H