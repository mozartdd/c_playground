#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printButterfly(int rows);

int main(int argc, char *argv[]) {
  // atoi turns inline argv[1] from char to integer
  int height = atoi(argv[1]);
  if (argc != 2) {
    printf("Usage: %s <height>\n", argv[0]);
    return 1;
  }
  if (height <= 0) {
    printf("Height inline argument must be positive integer\n");
    return 2;
  }

  printButterfly(height);
}

// Loops over each of 4 butterfly's sides and print's them
void printButterfly(int rows) {
  // Counts rows height of butterfly
  for (int i = rows; i >= 0; i--) {
    // Prints left side of butterfly
    for (int j = rows - i + 1; j > 0; j--) printf("#");
    // Prints space between butterfly's wings
    for (int k = i * 2; k > 0; k--) printf(" ");
    // Prints right side of butterfly
    for (int j = rows - i + 1; j > 0; j--) printf("#");
    printf("\n");
  }
  // Prints bottom of butterfly
  for (int i = 0; i < rows; i++) {
    for (int j = 1; j <= rows - i; j++)  printf("#" );
    for (int k = (i + 1) * 2; k > 0; k--) printf(" ");
    for (int j = 1; j <= rows - i; j++)  printf("#" );
    printf("\n");
  }
}