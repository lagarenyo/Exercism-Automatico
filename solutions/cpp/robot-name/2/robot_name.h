#include <set>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

namespace robot_name
{
    extern set<string> r_names;

    class robot
    {
    private:
        string my_name;
        string generate_name();
        bool valide_name(string name);
        void baptise();

    public:
        robot();
        void reset();
        string name() const;
    };

} 

#endif 