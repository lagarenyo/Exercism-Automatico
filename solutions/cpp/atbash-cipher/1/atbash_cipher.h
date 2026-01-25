#include <string>

using namespace std;

#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H

namespace atbash_cipher
{
    string encode(string str);
    string decode(string str);

} 

#endif 