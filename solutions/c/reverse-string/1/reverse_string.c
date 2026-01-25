#include "reverse_string.h"

char *reverse(const char *value) {
  int leng;
   char *res;

   leng = 0;
  while (*(value+leng) != '\0')
    leng++;
   
  res = (char *)malloc((sizeof(char) * leng) + 1);
  res[leng] ='\0';
  leng--;
  while (leng >=0 ) {
    res[leng] = *value;
    value++;
    leng--;
  }
  return res;
}