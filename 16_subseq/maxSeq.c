#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int* array, size_t n) {
  if (n < 1) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  size_t max = 1;
  size_t cur = 1;

  for (int i = 1; i < n; i++) {
    if (array[i] > array[i - 1]) {
      cur++;
    } else {
      cur = 1;
    }
    if (cur > max) {
      max = cur;
    }
  }
  
  return max;
}
