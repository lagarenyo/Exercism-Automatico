#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{

  uint32_t aux1, aux2;
  uint32_t arr[limit];

  aux2 = 0;
  if ((limit > 1) && (max_primes > 0))
  {
    limit--;
    for (aux1 = 0; aux1 < limit; aux1++)
      arr[aux1] = aux1 + 2;
    for (aux1 = 0; aux1 < limit; aux1++)
    {
      if (arr[aux1] != 0)
      {
        aux2 = aux1 + arr[aux1];
        while (aux2 < limit)
        {
          arr[aux2] = 0;
          aux2 = aux2 + arr[aux1];
        }
      }
    }
    aux2 = 0;
    aux1 = 0;
    while ((aux1 < limit) && (aux2 < (max_primes)))
    {
      if (arr[aux1] != 0)
      {
        *(primes + aux2) = arr[aux1];
        aux2++;
      }
      aux1++;
    }
  }
  return aux2;
}