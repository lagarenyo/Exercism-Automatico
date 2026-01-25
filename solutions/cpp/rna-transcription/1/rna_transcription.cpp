#include "rna_transcription.h"

char rna_transcription::to_rna(char c)
{
    char res;
    res = 'E';
    res = (c == 'G') ? 'C' : res;
    res = (c == 'C') ? 'G' : res;
    res = (c == 'T') ? 'A' : res;
    res = (c == 'A') ? 'U' : res;
    return res;
}

std::string rna_transcription::to_rna(const std::string &str)
{
    std::string result;
    for (char c : str)
    {
        result += to_rna(c);
    }
    return result;
}

// namespace rna_transcription
