#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int returnReminder(int number);
void turnToIntegers(int arrayOfInts[], char *arrayOfString[], int length);
bool isNumber = true;
// 0 = uppercase, 1 = lowercase, 2 = symbol
int current = 0;

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Key must consist from at least 3 numbers\n");
    return 1;
  }

  // Dynamical memory allocation to hold array of array on integers
  int integerArray[argc-1];
  if (integerArray == NULL) {
    printf("Memory allocation failed\n");
    return 2;
  }
  turnToIntegers(integerArray, argv, argc);
  int result;

  for (int i = 0; i < argc - 1; i++) {
    result = returnReminder(integerArray[i]);
    if (result == 0) {
        printf("");
    } else if (current == 0) {
        printf("%c", result + 'A' - 1);
    } else if (current == 1) {
        printf("%c", result + 'a' - 1);
    }
  }
  printf("\n");
  return 0;
}

// Turns array of chars to array of integers
void turnToIntegers(int arrayOfInts[], char *arrayOfString[], int length) {
  for (int i = 0; i < length - 1; i++) {
    arrayOfInts[i] = atoi(arrayOfString[i + 1]);
  }
}

// Return reminder of letter or symbol divided by 26 or 8 and modifies global flags
int returnReminder(int number) {
  int result = isNumber ? (number % 27) : (number % 9);
  if (result == 0) {
    current++;
  }
  if (current == 2) {
    isNumber = false;
  }
  else if (current == 3) {
    current = 0;
    isNumber = true;
  }
  return result;
}
