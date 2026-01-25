#include "grade_school.h"

using namespace std;

namespace grade_school
{
    void school::add(string name, int gr)
    {
        this->alumDB[gr].push_back(name);
        sort(begin(this->alumDB[gr]), end(this->alumDB[gr]));
    }

    gs_map school::roster() const
    {
        return this->alumDB;
    }

    gs_vector school::grade(int gr) const
    {
       return alumDB.find(gr)->second;
    }
}
