#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef char Data;
typedef int Position;
typedef struct Node{
    Data val;
    Position position;
    struct Node *next;
}Node;
Data top(Node *top);
void push(Node**top, Data v, Position position);
Data pop(Node**top);
int isEmpty(Node*top);
void deleteStack(Node**top);
