#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node_value {
    char name[256];
    struct node_value *prev;
} node;

node *top;

node *build_node() {
    return malloc(sizeof(node));
}

node *read_node() {
    node *new_node = build_node();
    new_node->prev = NULL;
    printf("Provide a name: ");
    scanf("%[^\n]%*c", new_node->name);
    return new_node;
}

void push(node *new_node) {
    if(top == NULL) {
        top = new_node;
        return;
    }
    new_node->prev = top;
    top = new_node;
}

node *pop() {
    if(top == NULL) {
        return NULL;
    }
    node *pop = build_node();
    strcpy(pop->name, top->name);

    node *to_free = top;
    top = top->prev;
    free(to_free);
    return pop;
}

void print_node(node *n) {
    printf("Name: %s\n", n->name);
}

void print_stack() {
    printf("\nbegin of stack...\n");
    node *actual = top;
    while(actual != NULL) {
        print_node(actual);
        actual = actual->prev;
    }
    printf("...end of stack\n\n");
}

int main(int argc, char *argv[]) {
    push(read_node());
    push(read_node());
    push(read_node());

    print_stack();
    print_node(pop());
    print_stack();
    print_node(pop());
    print_stack();
    print_node(pop());
    print_stack();
 
    push(read_node());
    print_stack();
}

