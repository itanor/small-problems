#include <stdio.h>
#include <stdlib.h>

void printMatrix(int max) {
  int minimum = 1;
  int size = 0;
  while(minimum <= max) {
    size += 1;
    minimum *= 2;
  }
  minimum = 1;

  int array[size+1]; array[0] = 0;
  int matrix[size+1][size+1];

  int index = 1;
  while(minimum <= max) {
    array[index++] = minimum;
    minimum *= 2;
  }

  for (int m = 0; m < size+1; m++) {
    for (int n = 0; n < size+1; n++) {
      matrix[m][n] = array[m] >> n;
    }
  }
  for (int m = 0; m < size+1; m++) {
    for (int n = 0; n < size+1; n++) {
      printf("%i ", matrix[m][n]);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  printMatrix(atoi(argv[1]));
  return 0;
}

