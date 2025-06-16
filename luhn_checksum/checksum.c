#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int getDigitSum(long long int number, bool isSecond);

int main(int argc, char *argv[]) {
  // Looks if current digit of number is 2nd from end
  bool isSecondDigit = false;
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
  // If number greater than max of long long int
  if (number > 922337203685477580) {
    printf("Please enter a smaller number\n");
    return 3;
  }
  int digitSum = getDigitSum(number, isSecondDigit);
  int result = digitSum % 10;
  if (result == 0) {
    printf("Number: %lld is valid luhn number.\n", number);
    return 0;
  } else {
    printf("Number: %lld is invalid luhn number.\n", number);
    return 0;
  }
}

// Finds and return sum of every second digit
// of int, starting with 2nd digit from right
int getDigitSum(long long int number, bool isSecond) {
  int lastDigit;
  int sum = 0;

  // While number is greater than 0 divide it by 10
  while (number > 0) {
    // If it is second digit get it by getting reminder of 10 from number
    if (isSecond) {
      lastDigit = number % 10;
      lastDigit *= 2;
      // If last digit multiplied by 2 is grater than 10, get it's
      // last digit of dividing it by reminder of 10 and add it to 1 
      if (lastDigit >= 10) {
        lastDigit -= 9;
      }
      // Sum of all last digit summed together
      sum += lastDigit;
    }
    if (!isSecond) {
      lastDigit = number % 10;
      sum += lastDigit;
    }
    number /= 10;
    isSecond = !isSecond;
  }
  return sum;
}