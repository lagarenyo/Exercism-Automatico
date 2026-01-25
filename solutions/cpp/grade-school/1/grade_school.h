#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

namespace grade_school
{
    typedef vector<string> gs_vector;
    typedef map<int, gs_vector> gs_map;

    class school
    {
    private:
        gs_map alumDB;

    public:
        void add(string name, int gr);
        gs_map roster() const;
        gs_vector grade(int gr) const;
    };
}
#endif