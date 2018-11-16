#include <stdio.h>

void rotate(char matrix[10][10]) {
  char temp[10][10];

  for (int i = 0; i < 10; i++) {
    for (int k = 0; k < 10; k++) {
      temp[i][k] = matrix[9 - k][i];
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int k = 0; k < 10; k++) {
      matrix[i][k] = temp[i][k];
    }
  }
}
