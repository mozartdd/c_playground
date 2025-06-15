#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printPyramid(int rows, bool value);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Program accepts two inline arguments.\nSecond one being pyramid's height.\n");
    return 1;
  }
  printPyramid(atoi(argv[1]), true);
  printPyramid(atoi(argv[1]), false);
}

// Prints growing or shrinking pyramid of rows hight
void printPyramid(int rows, bool value) {
  // If true print growing pyramid half
  if (value) {
    for (int i = rows; i >= 0; i--) {
      for (int j = rows - i + 1; j > 0; j--) {
        printf("#");
      }
      printf("\n");
    }
    // If false print shrinking pyramid
  } else {
    for (int i = 0; i < rows; i++) {
      for (int j = 1; j <= rows - i; j++) {
        printf("#" );
      }
      printf("\n");
    }
  }
}