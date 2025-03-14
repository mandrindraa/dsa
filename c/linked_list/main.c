#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;
struct node {
    int value;
    struct node *next;
};

node_t *insert_front(node_t *node, node_t *node_to_insert) {
    node_to_insert->next = node;
    return node_to_insert;
}

node_t *new_node(int v) {
    node_t *node = malloc(sizeof(node_t));
    node->value = v;
    node->next = NULL;
    return node;
}

void *insert_back(node_t *node, node_t *node_to_insert) {
    node_t *tmp = node;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = node_to_insert;
    return node;
}

void *pop_front(node_t *node) {
    node_t *tmp = node;
    if(tmp->next != NULL) {
        tmp = tmp->next;
        return (void*)tmp;
    } else {
        return NULL;
    }
}

void print_list(node_t *node) {
    node_t *tmp = node;
    while(tmp != NULL) {
        printf("%d - ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(void) {

    node_t *head = malloc(sizeof(node_t));
    head->value = 9;
    head->next = NULL;
    for(int i = 0; i < 6; i++) {
        head = insert_front(head, new_node(12-i));
    }
    head = (node_t*)pop_front(head);
    print_list(head);
    return 0;
}