#include <stdio.h>

int main() {
  /*  int array[] = {1, 2, 3, 4, 5, 6};
  int* p = &array[0];
  printf("%d\n", *p);

  int* x = array;
  x++;

  int* y = &array[0];
  printf("%d\n", *y);*/

  int anArray[] = {0, 1, 2, 3, 4, 5, 6};
  int * p = anArray;
  p++;
  int * q = &anArray[3];
  int ** x = &q;
  *x = p;
  q[1] = 9;

  for (int i =0; i < 4; i++){
    printf("anArray[%d] = %d\n",i, anArray[i]);
  }

  return 0;
}
