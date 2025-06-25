#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 0 = uppercase, 1 = lowercase, 2 = symbol
int current = 0;
bool isNumber = true;

#define SYMBOL_COUNT 9
#define LETTER_COUNT 27

int returnReminder(int number);
void turnToIntegers(int arrayOfInts[], char *arrayOfString[], int length);
char returnPunctuation(int number);

int main(int argc, char *argv[]) {
  // Array of integers of dynamic length defined by argument count - 1
  int integerArray[argc-1];
  turnToIntegers(integerArray, argv, argc);

  if (argc < 4) {
    printf("Key must consist from at least 3 numbers\n");
    return 1;
  }

  for (int i = 0; i < argc - 1; i++) {
    int result = returnReminder(integerArray[i]);
    if (result == 0) {
        continue;
    } else if (current == 0) {
        printf("%c", result + 'A' - 1);
    } else if (current == 1) {
        printf("%c", result + 'a' - 1);
    } else if (current == 2) {
      printf("%c", returnPunctuation(result));
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
  int result = isNumber ? (number % LETTER_COUNT) : (number % SYMBOL_COUNT);
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

// Asign numeric value to symbol
char returnPunctuation(int number) {
  switch(number) {
    case 1:
    return '!';
    break;
  case 2:
    return '?';
    break;
  case 3:
    return ',';
    break;
  case 4:
    return '.';
    break;
  case 5:
    return ' ';
    break;
  case 6:
    return ';';
    break;
  case 7:
    return '"';
    break;
  case 8:
    return '\'';
    break;
  default:
    return '?';
  }
}
