#include <string>
#include <map>
#include <stdexcept>

using namespace std;

#if !defined(SAY_H)
#define SAY_H

namespace say
{
	string in_english_two_digits(unsigned long long num);
	string in_english_three_digits(unsigned long long num);
	string in_english(unsigned long long num);

} // namespace say

#endif // SAY_H
