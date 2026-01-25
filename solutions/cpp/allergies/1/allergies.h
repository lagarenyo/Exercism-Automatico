#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

#if !defined(ALLERGIES_H)
#define ALLERGIES_H

namespace allergies
{
    const vector<string> nomb = {
        "eggs",
        "peanuts",
        "shellfish",
        "strawberries",
        "tomatoes",
        "chocolate",
        "pollen",
        "cats",
    };

    class allergy_test
    {
    private:
        string code;

    public:
        allergy_test(unsigned int ind);
        bool is_allergic_to(string cad);
        unordered_set<std::string> get_allergies();
    };
}
#endif