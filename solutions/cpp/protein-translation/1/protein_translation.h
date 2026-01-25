#include <vector>
#include <map>
#include <string>

#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H

using namespace std;

namespace protein_translation
{
    extern map<string, string> codon_protein;

    vector<string> proteins(string pr);

} // namespace protein_translation

#endif // PROTEIN_TRANSLATION_H
