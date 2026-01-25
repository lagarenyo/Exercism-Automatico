#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length) {
  int init;
  int end;
  int center;

  init = 0;
  end = length - 1;
  center = length / 2;
  while ((*(arr + center) != value) && (init<=end)){
    (*(arr + center) < value) ? (init = center + 1) : (end = center - 1);
    center = (end + init) / 2;
  }
  const int *res =  (init<=end) ? arr + center : NULL;
  return res;
}
