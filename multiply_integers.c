#include <stdio.h>
#include <stdlib.h>

int multiply_integers(int n1, int n2) {
  int times = abs(n1);
  int result = 0; 
  for(int i = 0; i < times; i++) {
    result += n2;
  }
  return result;
}

int main(int argc, char *argv[]) {
  printf("%i\n", multiply_integers(-2, 3));
  return 0;
}

