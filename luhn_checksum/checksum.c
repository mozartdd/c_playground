#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int getDigitSum(long long int number, bool isSecond);

int main(int argc, char *argv[]) {
  // Looks if current digit of number is 2nd from end
  bool isSecondDigit = false;
  long long int number = atoll(argv[1]);
  // Check's if there is exactly two command line arguments
  // and that user input number is greater than zero
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
  // If remainder is 0 digit is valid
  if (digitSum % 10 == 0) {
    printf("Number is divisible by 10. Valid.\n", number);
    return 0;
  } else {
    printf("Number is not divisible by 10. Invalid.\n", number);
    return 0;
  }
}

// Finds and return sum of every second digit
// of int, starting with 2nd digit from right
int getDigitSum(long long int number, bool isSecond) {
  int lastDigit;
  int sum = 0;

  while (number > 0) {
    // Get value of last digit by getting it's reminder of % 10
    lastDigit = number % 10;
    if (isSecond) {
      lastDigit *= 2;
      // If last digit multiplied by 2 is grater than 10, get it's
      // value by subtractin 9
      if (lastDigit > 9) {
        lastDigit -= 9;
      }
      // Sum of all digits summed together
      sum += lastDigit;
    }
    if (!isSecond) {
      sum += lastDigit;
    }
    number /= 10;
    isSecond = !isSecond;
  }
  return sum;
}