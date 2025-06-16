#include <stdio.h>
#include <stdlib.h>

void findLastDigit(long long int number);

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  // Check's that argc is exactly two and user input number i greater than zero
  if (argc != 2) {
    printf("Usage: %s <number>\n", argv[0]);
    return 1;
  }
  if (number <= 0)
    {
      printf("Number you want to check must be positive integer.\n");
      return 2;
    }
  findLastDigit(number);
}

// Finds last digit of int that need to be checked
void findLastDigit(long long int number) {
  number %= 10;
  printf("%lld\n", number);
}