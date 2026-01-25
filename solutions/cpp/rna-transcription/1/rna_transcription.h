#include <map>
#include <string>

using namespace std;

#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H

namespace rna_transcription
{
    char to_rna(char c);
    std::string to_rna(const std::string &str);
} // namespace rna_transcription

#endif // RNA_TRANSCRIPTION_H