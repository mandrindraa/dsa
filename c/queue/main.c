#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define QUEUE_EMPTY INT_MIN


typedef struct node {
    int value;
    struct node* next;
} node_t;

typedef struct queue {
    node_t *head;
    node_t *tail;
} queue_t;

void init_queue(queue_t *q) {
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue_t *q, int value) {
    node_t *newnode = malloc(sizeof(node_t));
    if (newnode == NULL) return false;
    newnode->value = value;
    newnode->next = NULL;
    if (q->tail != NULL) {
        q->tail->next = newnode;
    }
    q->tail = newnode;
    if (q->head == NULL) {
        q->head = newnode;
    }
    return true;
}

int dequeue(queue_t *q) {
    if (q == NULL) return QUEUE_EMPTY;
    node_t *tmp = q->head;
    printf("%p\n", tmp);
    int result = tmp->value;
    q->head = q->head->next;
    if (q->head == NULL) q->tail = NULL;
    free(tmp);
    return result;
} 

int main(void) {
    queue_t q;
    init_queue(&q);
    enqueue(&q, 12);
    enqueue(&q, 234);
    enqueue(&q, 134);
    int t = INT_MAX;
    while( (t = dequeue(&q)) && t != QUEUE_EMPTY) {
        printf("t = %d\n", t);
    }
    return 0;
}