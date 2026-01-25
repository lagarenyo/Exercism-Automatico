#include "queen_attack.h"

int evaluaposicion(position_t queen)
{
    return ((queen.column < 8) && (queen.row < 8));
}
int mismaposicion(position_t queen1, position_t queen2)
{
    return ((queen1.column == queen2.column) && (queen1.row == queen2.row));
}

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    attack_status_t res;

    res = CAN_NOT_ATTACK;
    if (!evaluaposicion(queen_1) || !evaluaposicion(queen_2) || mismaposicion(queen_1, queen_2))
        res = INVALID_POSITION;
    else if (((queen_1.column == queen_2.column) || (queen_1.row == queen_2.row)) || (abs(queen_1.column - queen_2.column) == abs(queen_1.row - queen_2.row)))
        res = CAN_ATTACK;
    return res;
}
