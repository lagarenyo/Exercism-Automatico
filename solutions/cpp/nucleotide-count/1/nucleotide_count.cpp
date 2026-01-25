#include "nucleotide_count.h"

namespace nucleotide_count
{
    void counter::nc_counts()
    {
        for (char c : strvalue)
        {
            auto it = content.find(c);
            it->second += 1;
        }
    }

    counter::counter(string str)
    {
        for (char c : str)
            if ((c != 'A') && (c != 'C') && (c != 'G') && (c != 'T'))
                throw std::invalid_argument("invalid argument");

        strvalue.assign(str);
        nc_counts();
    }

    std::map<char, int> counter::nucleotide_counts() const
    {
        return content;
    }
} // namespace nucleotide_count