#include "robot_name.h"

using namespace std;

set<string> robot_name::r_names = {};

string robot_name::robot::generate_name()
{
    string res;
    int alelet;
    int alenum;

    alelet = rand() % 676;
    alenum = rand() % 1000;
    res += (alelet % 26) + 65;
    alelet /= 26;
    res += (alelet % 26) + 65;
    res += to_string(alenum % 10);
    alenum /= 10;
    res += to_string(alenum % 10);
    alenum /= 10;
    res += to_string(alenum % 10);
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