#include <stdio.h>
#include <stdlib.h>

#define PERIOD 12

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void printBalance(retire_info info, double bal, int age) {
  int year = age / PERIOD;
  int month = age % PERIOD;
  
  printf("Age %3d month %2d you have $%.2lf\n", year, month, bal);
}

double newBalance(retire_info info, double bal) {
  double result = bal;
  
  result += result * info.rate_of_return;
  result += info.contribution;

  return result;
}

double updateBalance(retire_info info, double bal, int age) {
  printBalance(info, bal, age);
  return newBalance(info, bal);
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  double balance = initial;
  int retirementAge = startAge + working.months;

  for(int i = startAge; i < retirementAge; i++) {
    balance = updateBalance(working, balance, i);
    
  }

  for(int i = retirementAge; i < retirementAge + retired.months; i++) {
    balance = updateBalance(retired, balance, i);
  }
}

int main() {
  retire_info working = {489, 1000, 0.045 / PERIOD};
  retire_info retired = {384, -4000, 0.01 / PERIOD};
  
  retirement(327, 21345, working, retired);

  return 0;
}
