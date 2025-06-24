#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void makeAlphabet(char array[]);

int main(void) {
  // String of num which will be used to convert to array on digits
  char stringOfNums[100] = "23,221,5225,1521,15225,1223,215,2";
  int arrayOfNums[100];
  char alphabet[26];
  makeAlphabet(alphabet);
  printf("%s\n", alphabet);
  // Token will hold information of current number/digit separated by come
  char *token;
  int i = 0;

  // Separates stringOfNums to separate digits at place of comma
  token = strtok(stringOfNums, ",");
  
  // While token is not NULL add token to arrayOfNums
  while(token) {
    if (i >= 100) return 1;
    arrayOfNums[i] = atoi(token);
    token = strtok(NULL, ",");
    i++;
  }
  
  return 0;
}

// Creates alphabet
void makeAlphabet(char array[]) {
  for (int i = 0; i < 26; i++) {
    array[i] = 'a' + i;
  }
}