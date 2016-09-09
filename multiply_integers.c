#include <stdio.h>
#include <stdlib.h>

int multiply_integers(int n1, int n2) {
    int times = abs(n1);
    int result = 0;
    for(int i = 0; i < times; i++) result += n2;
    if(n1 < 0 && n2 < 0) return -result;
    return result;
}

int main(int argc, char *argv[]) {
    printf("%i\n", multiply_integers(atoi(argv[1]), atoi(argv[2])));
    return 0;
}

