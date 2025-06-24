#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void makeAlphabet(char array[]);

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Key must consist from at least 3 numbers");
    return 1;
  }
  // Array which holds alphabetical letters
  char alphabet[26];
  makeAlphabet(alphabet);
}

// Creates alphabet
void makeAlphabet(char array[]) {
  for (int i = 0; i < 26; i++) {
    array[i] = 'a' + i;
  }
}