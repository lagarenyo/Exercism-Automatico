#include "rotational_cipher.h"

char *rotate(const char *text, int shift_key) {
  char *res;
  const char *iter;
  unsigned char aux;
  int inicio;
  int longitud;

  longitud = 0;
  while (*(text + longitud) != '\0')
    longitud++;
  longitud++;
  res = (char *)malloc(longitud * sizeof(char));
  for (int i = 0; i < longitud; i++) {
    iter = text + i;
    if (((*iter) > 64) && ((*iter) < 91))
      inicio = 65;
    else if (((*iter) > 96) && ((*iter) < 123))
      inicio = 97;
    else
      inicio = 0;
    aux = *iter;
    if (inicio != 0) {
      aux += shift_key;
      if ((aux - inicio) >= 26)
        aux -= 26;
    }
    *(res + i) = aux;
  }
  *(res + longitud - 1) = '\0';
  return res;
}
