#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int* array, size_t n);

int main() {
  int test01[] = {1, 2, 3, 4, 5};
  if (maxSeq(test01, 5) != 5) {
    printf("Failed test01");
    return EXIT_FAILURE;
  }
  int* test02 = NULL;
  if (maxSeq(test02, 0) != 0) {
    printf("Failed test02");
    return EXIT_FAILURE;
  }
  int test03[] = {3, 4, -3};
  if (maxSeq(test03, 3) != 2) {
    printf("Failed test03");
    return EXIT_FAILURE;
  }
  int test04[] = {3, 2, 1};
  if (maxSeq(test04, 3) != 1) {
    printf("Failed test04");
    return EXIT_FAILURE; 
  }
  int test05[] = {5, 2, 3, 4};
  if (maxSeq(test05, 4) != 3) {
    printf("Failed test05");
    return EXIT_FAILURE; 
  }
  int test06[] = {3, -5, -4, -3, 2};
  if (maxSeq(test06, 5) != 4) {
    printf("Failed test06");
    return EXIT_FAILURE; 
  }
  int test07[] = {2, 2, 2, 2};
  if (maxSeq(test07, 4) != 1) {
    printf("Failed test07");
    return EXIT_FAILURE; 
  }
  int test08[] = {1, 1, 2, 2, 2, 1, 1};
  if (maxSeq(test08, 7) != 2) {
    printf("Failed test08");
    return EXIT_FAILURE; 
  }
  if (maxSeq(test08, 0) != 0) {
    printf("Failed 0 size test");
    return EXIT_FAILURE; 
  }
  int test09[] = {0};
  if (maxSeq(test09, 1) != 1) {
    printf("Failed test09");
    return EXIT_FAILURE; 
  }
  int test10[] = {23, -500, 0, 20, 123, 450, 1234, 20005, 40};
  if (maxSeq(test10, 9) != 7) {
    printf("Failed test10");
    return EXIT_FAILURE;
  }
  printf("Passed all tests");
  
  return EXIT_SUCCESS;
}
