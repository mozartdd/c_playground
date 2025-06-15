#include <stdio.h>

void printPyramid(int rows);

int main(void) {
  printPyramid(10);
}

void printPyramid(int rows) {
  for (int i = rows; i >= 0; i--) {
    for (int j = rows - i + 1; j > 0; j--) {
      printf("#");
    }
    printf("\n");
  }
}