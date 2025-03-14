#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

typedef struct node node_t;
typedef struct node* stack_t;

struct node {
    int value;
    struct node *next;
};

bool push(stack_t *stack, int value) {
    node_t *newnode = malloc(sizeof(node_t));
    if (newnode == NULL) return false;
    newnode->value = value;
    newnode->next = *stack;
    *stack = newnode;
    return true;
}
 
int pop(stack_t *stack) {
    if((*stack) == NULL) return STACK_EMPTY;
    int t = (*stack)->value;
    node_t *tmp = *stack;
    *stack = (*stack)->next;
    free(tmp);
    return t;
}

int main(void) {
    stack_t *s = malloc(sizeof(stack_t));
    push(s, 43);
    push(s, 23);
    push(s, 12);
    int t;
    while( (t = pop(s)) != STACK_EMPTY) {
        printf("t = %d\n", t);
    }
    return 0;
}