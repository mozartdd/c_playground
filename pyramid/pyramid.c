#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printPyramid(int rows, bool value);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Program accepts two inline arguments.\nSecond one being pyramid's height.\n");
    return 1;
  }
  // atoi turns inline argv[1] from char to integer
  printPyramid(atoi(argv[1]), true);
  printPyramid(atoi(argv[1]), false);
}

// Prints growing or shrinking pyramid of rows hight
void printPyramid(int rows, bool value) {
  // If true print growing pyramid half
    // Counts rows height of pyramid
    for (int i = rows; i >= 0; i--) {
      // Prints left side of butterfly
      for (int j = rows - i + 1; j > 0; j--) {
        printf("#");
      }
      // Prints space between butterfly's wings
      for (int k = i * 2; k > 0; k--) {
        printf(" ");
      }
      // Prints right side of butterfly
      for (int d = rows - i + 1; d > 0; d--) {
        printf("#");
      }
      printf("\n");
    }
    // Prints bottom of butterfly
    for (int i = 0; i < rows; i++) {
      for (int j = 1; j <= rows - i; j++) {
        printf("#" );
      }
      for (int k = (i + 1) * 2; k > 0; k--) {
        printf(" ");
      }
      for (int d = rows - i; d > 0; d--) {
        printf("#");
      }
      printf("\n");
    }
}