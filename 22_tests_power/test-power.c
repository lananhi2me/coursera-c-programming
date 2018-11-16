#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);
void run_check(unsigned x, unsigned y, unsigned expected_ans);

int main() {
  run_check(0, 0, 1);
  run_check(1, 0, 1);
  run_check(1, 1, 1);
  run_check(2, 2, 4);
  run_check(2, 31, 2147483648);
  run_check(60000, 2, 3600000000);
  run_check(4294967295, 1, 4294967295);
  run_check(4294967295, 0, 1);

  exit(EXIT_SUCCESS);
}

void run_check(unsigned x, unsigned y, unsigned expected_ans) {
  if (power(x, y) != expected_ans) {
    printf("power(%u, %u) did not equal %u", x, y, expected_ans);
    exit(EXIT_FAILURE);
  }
}
