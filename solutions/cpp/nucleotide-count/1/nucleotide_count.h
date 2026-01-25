#include <string>
#include <stdexcept>
#include <map>

using namespace std;

#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

namespace nucleotide_count
{
    class counter
    {
    private:
        string strvalue;
        std::map<char, int> content{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
        void nc_counts();

    public:
        counter(string str);
        std::map<char, int> nucleotide_counts() const;
    };

} // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H