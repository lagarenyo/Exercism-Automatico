#include <iostream>

#include "protein_translation.h"

namespace protein_translation
{
    map<string, string> codon_protein = {
        {"AUG", "Methionine"},
        {"UUU", "Phenylalanine"},
        {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"},
        {"UUG", "Leucine"},
        {"UCU", "Serine"},
        {"UCC", "Serine"},
        {"UCA", "Serine"},
        {"UCG", "Serine"},
        {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"},
        {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},
        {"UAA", "STOP"},
        {"UAG", "STOP"},
        {"UGA", "STOP"}};

    vector<string> proteins(string pr)
    {
        vector<string> res;
        int max_pos;
        int it;
        string codon;
        bool stop;

        max_pos = pr.length() - 3;
        stop = false;
        it = 0;

        while (!stop && it <= max_pos)
        {
            codon = pr.substr(it, 3);
            if (codon_protein[codon] == "STOP")
                stop = true;
            else
                res.push_back(codon_protein[codon]);
            it += 3;
        }
        return res;
    }
} // namespace protein_translation
