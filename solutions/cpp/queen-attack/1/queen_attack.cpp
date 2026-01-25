#include "queen_attack.h"

namespace queen_attack
{
    bool chess_board::check_rank(int num)
    {
        return ((num >= 0) && (num < 8));
    }

    chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black)
    {
        if (check_rank(white.first) && check_rank(white.second) &&
            check_rank(black.first) && check_rank(black.second))
        {
            this->pos_white = white;
            this->pos_black = black;
        }
        else
            throw domain_error("invalid argument");
    }

    bool chess_board::can_attack() const
    {
        int auxfirst;
        int auxsecond;
        bool res;

        res = false;
        if (((this->pos_white.first) == (this->pos_black.first)) ||
            ((this->pos_white.second) == (this->pos_black.second)))
            res = true;
        if (!res)
        {
            auxfirst = this->pos_white.first - this->pos_black.first;
            auxsecond = this->pos_white.second - this->pos_black.second;
            if ((auxfirst == auxsecond) || ((auxfirst + auxsecond) == 0))
                res = true;
        }
        return res;
    }

    pair<int, int> chess_board::white() const
    {
        return this->pos_white;
    }

    pair<int, int> chess_board::black() const
    {
        return this->pos_black;
    }

} // namespace queen_attack
