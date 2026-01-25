#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

#if !defined(SERIES_H)
#define SERIES_H

namespace series
{
    vector<string> slice(string str, int num);
}
#endif