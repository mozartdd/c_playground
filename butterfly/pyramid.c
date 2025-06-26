#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int height = atoi(argv[1]);
  if (argc != 2) {
    printf("Usage: ./pyramid 'height'\n");
    return 1;
  } else if (height > 9 || height < 3) {
    printf("Pyramid's height must be between 3 and 9.\n");
    return 2;
  }
  for (int i = height; i > 0; i--) {
    for (int s = i - 1; s > 0; s--) printf(" ");
    for (int j = i - 1; j < height; j++) printf("##");
    for (int s = i - 1 ; s > 0; s--) printf(" ");
    printf("\n");
  }
  for (int i = height; i > 0; i--) {
    for (int s = i; s < height; s++) printf(" ");
    for (int j = i; j > 0; j--) printf("##");
    for (int s = i; s < height; s++) printf(" ");
    printf("\n");
  }
}