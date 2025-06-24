#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void makeAlphabet(char array[]);
void turnToIntegers(int arrayOfInts[], char *arrayOfString[], int length);

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Key must consist from at least 3 numbers\n");
    return 1;
  }
  // Array which holds alphabetical letters
  char alphabet[26];
  int *integerArray = malloc((argc - 1) * sizeof(int));
  if (integerArray == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  makeAlphabet(alphabet);
  turnToIntegers(integerArray, argv, argc);

  for (int i = 0; i < argc - 1; i++) {
    printf("%d\n", integerArray[i]);
  }  
}

// Creates alphabet
void makeAlphabet(char array[]) {
  for (int i = 0; i < 26; i++) {
    array[i] = 'a' + i;
  }
}

// Turns array of chars to array of integers
void turnToIntegers(int arrayOfInts[], char *arrayOfString[], int length) {
  for (int i = 0; i < length - 1; i++) {
    arrayOfInts[i] = atoi(arrayOfString[i + 1]);
  }
}