#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct nf {
    int number;
    int frequency;
    struct nf *next;
} number_frequency;

number_frequency *first;
number_frequency *last;

number_frequency * memory_for_nf() {
    return malloc(sizeof(number_frequency));
}

number_frequency * build(int number) {
    number_frequency *nf = memory_for_nf();
    nf->number    = number;
    nf->frequency = 1;
    nf->next      = NULL;
    return nf;
}

int increment_by_same_number(number_frequency *nf, int number) {
    if(nf->number == number) {
        nf->frequency++;
        return 1;
    }
    return 0;
}

void add_number(int number) {
    number_frequency *nf = build(number);

    if(first == NULL) {
        first = nf;
        last = nf;
        return;
    }
    number_frequency *actual = first;
    while(actual != NULL) {
        if(increment_by_same_number(actual, number)) {
            return;
        }
        last = actual;
        actual = actual->next;
    }
    last->next = nf;
    last = nf;
}

void print_grouped() {
    number_frequency *n = first;
    while(n != NULL) {
        printf("number   : %i\n", n->number);
        printf("frequency: %i\n", n->frequency);
        printf("------------\n");
        n = n->next;
    }
}

number_frequency * find_bigger_frequency() {
    number_frequency *actual = first;
    number_frequency *bigger = first;

    while(actual != NULL) {
        if(actual->frequency >= bigger->frequency) {
            bigger = actual;
        }
        actual = actual->next;
    }
    return bigger;
}

int most_frequent_integer_in_array() {
    int array[MAX];

    array[0] = 2;
    array[1] = 6;
    array[2] = 7;
    array[3] = 3;
    array[4] = 6;
    array[5] = 2;
    array[6] = 6;
    array[7] = 6;
    array[8] = 7;
    array[9] = 7;

    for(int i = 0; i < MAX; i++) {
        add_number(array[i]);
    }
    print_grouped();

    return find_bigger_frequency()->number;
}

int main(int argc, char *argv[]) {
    printf("most frequent: %i\n", most_frequent_integer_in_array());
    return 0;
}

