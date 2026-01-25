#include "robot_name.h"

set<string> robot_name::r_names = {};

string robot_name::robot::generate_name()
{
    string res;
    int it;

    srand(time(NULL));
    it = 0;
    while (it++ < 2)
        res += 65 + rand() % 25;
    for (int i = 0; i < 3; i++)
        res += to_string(rand() % 10);
    return res;
}

bool robot_name::robot::valide_name(string name)
{
    return r_names.find(name) == r_names.end();
}

string robot_name::robot::name() const
{
    return this->my_name;
}

void robot_name::robot::baptise()
{
    string candidate;
    bool valid;

    valid = false;
    while (!valid)
    {
        candidate = this->generate_name();
        valid = valide_name(candidate);
    }
    r_names.insert(candidate);
    this->my_name = candidate;
}

robot_name::robot::robot()
{
    baptise();
}

void robot_name::robot::reset()
{
    baptise();
}