#include "say.h"

namespace say
{
  std::map<unsigned long long, string> say_numbers = {{0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"}, {30, "thirty"}, {40, "forty"}, {50, "fifty"}, {60, "sixty"}, {70, "seventy"}, {80, "eighty"}, {90, "ninety"}, {100, "hundred"}, {1000, "thousand"}, {1000000, "million"}, {1000000000, "billion"}};
  unsigned long long thousand = 1000;
  unsigned long long million = 1000000;
  unsigned long long billion = 1000000000;
  unsigned long long trillion = 1000000000000;

  string in_english_two_digits(unsigned long long num)
  {
    string res;
    unsigned long long aux;

    if ((num > 0) && (num < 100))
    {
      aux = num % 10;
      if ((num < 20) || (aux == 0))
        res = say_numbers[num];
      else
        res = say_numbers[(num / 10) * 10] + "-" + say_numbers[aux];
    }
    else
      throw domain_error("incorrect argument");
    return res;
  }

  string in_english_three_digits(unsigned long long num)
  {
    string res;
    unsigned long long auxdiv;
    unsigned long long auxrest;

    if ((num > 0) && (num < 1000))
    {
      if (num >= 100)
      {
        auxrest = num % 100;
        auxdiv = num / 100;
        res = in_english_two_digits(auxdiv) + " " + say_numbers[100];
        if (auxrest != 0)
          res = res + " " + in_english_two_digits(auxrest);
      }
      else
        res = in_english_two_digits(num);
    }
    else
      throw domain_error("incorrect argument");
    return res;
  }

  string in_english(unsigned long long num)
  {

    string res;
    unsigned long long aux;

    aux = 0;
    if ((num < trillion) && (num >= billion))
      aux = billion;
    else if ((num < billion) && (num >= million))
      aux = million;
    else if ((num < million) && (num >= thousand))
      aux = thousand;
    else if ((num < thousand) && (num > 0))
      res = in_english_three_digits(num);
    else if (num == 0)
      res = say_numbers[0];
    else
      throw domain_error("incorrect argument");

    if (aux != 0)
    {
      res = in_english(num / aux) + " " + say_numbers[aux];
      if ((num % aux) != 0)
        res += " " + in_english(num % aux);
    }

    return res;
  }
} // namespace say
