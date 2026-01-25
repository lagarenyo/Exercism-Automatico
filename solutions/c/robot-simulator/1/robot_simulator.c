#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t res;

    res.direction = direction;
    res.position.x = x;
    res.position.y = y;
    return res;
}

void robot_move(robot_status_t *robot, const char *commands)
{
    int iter;

    iter = 0;
    while (commands[iter] != '\0')
    {
        switch (commands[iter])
        {
        case 'L':
            if (robot->direction == DIRECTION_NORTH)
                robot->direction = DIRECTION_WEST;
            else
                robot->direction--;
            break;
        case 'R':
            if (robot->direction == DIRECTION_WEST)
                robot->direction = DIRECTION_NORTH;
            else
                robot->direction++;
            break;
        case 'A':
            switch (robot->direction)
            {
            case DIRECTION_NORTH:
                robot->position.y++;
                break;
            case DIRECTION_SOUTH:
                (robot->position.y)--;
                break;
            case DIRECTION_EAST:
                (robot->position.x)++;
                break;
            case DIRECTION_WEST:
                (robot->position.x)--;
                break;
            case DIRECTION_MAX:
                break;
            }
            break;
        }
        iter++;
    }
}