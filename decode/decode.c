#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int returnReminder(int number, bool value);
void turnToIntegers(int arrayOfInts[], char *arrayOfString[], int length);
bool isNumber = true;
// 0 = uppercase, 1 = lowercase, 2 = symbol
int current = 0;

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Key must consist from at least 3 numbers\n");
    return 1;
  }
  // Array which holds alphabetical letters
  char alphabet[26];
  // Dynamical memory allocation to hold array of array on integers
  int *integerArray = malloc((argc - 1) * sizeof(int));
  if (integerArray == NULL) {
    printf("Memory allocation failed\n");
    return 2;
  }
  turnToIntegers(integerArray, argv, argc);
  int result;

  for (int i = 0; i < argc - 1; i++) {
    result = returnReminder(integerArray[i], isNumber);
    printf("%d\n", result);
  }

  free(integerArray);
  return 0;
}

// Turns array of chars to array of integers
void turnToIntegers(int arrayOfInts[], char *arrayOfString[], int length) {
  for (int i = 0; i < length - 1; i++) {
    arrayOfInts[i] = atoi(arrayOfString[i + 1]);
  }
}

// Return reminder of letter divided by 26 or 8 and modifies global flags
int returnReminder(int number, bool flag) {
  int result = flag ? (number % 26) : (number % 8);
  if (result == 0) {
    current++;
  }
  if (current == 2) {
    flag = false;
  }
  if (current == 3) {
    current = 0;
    flag = true;
  }
  return result;
}
