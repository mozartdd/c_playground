#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  char stringOfNums[100] = "23,221,5225,1521,15225,1223,215,2";
  int arrayOfNums[100];
  const char coma[2] = ",";
  char *token;
  int i = 0;

  token = strtok(stringOfNums, coma);
  
  while(token) {
    arrayOfNums[i] = atol(token);
    token = strtok(NULL, coma);
    i++;
  }
}