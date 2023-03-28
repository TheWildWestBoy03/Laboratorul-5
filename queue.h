#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef int QData;
typedef struct QNode{
    QData val;
    struct QNode *next;
}QNode;
typedef struct Queue{
    struct QNode *front, *rear;
}Queue;
Queue* createQueue();
void enQueue(Queue*q, QData v);
QData deQueue(Queue*q);
int isQueueEmpty(Queue*q);
void deleteQueue(Queue*q);
