#include "queue.h"
#include "stack.h"
void readTheData(char **paranthesisV1){
    char buffer[50], *paranthesis = *paranthesisV1;
    scanf("%s", buffer);
    getchar();
    paranthesis = (char*)malloc(strlen(buffer)+1);
    *paranthesisV1 = paranthesis;
    strcpy(paranthesis, buffer);
    return;
}
void readingData(int **numbers, int *numberOfElements){
    int buffer[50];
    scanf("%d", numberOfElements);
    for(int i=0; i<*numberOfElements; i++){
        scanf("%d", &buffer[i]);
    }
    *numbers = (int*)malloc(sizeof(int) * *numberOfElements);
    for(int i=0; i< *numberOfElements; i++){
        (*(*numbers + i)) = buffer[i];
    }
    return;
}
int main()
{

    char *paranthesis = NULL;
    int *visited, itHasUnpaired = 0;
    Node *top = NULL;
    printf("Introduceti sirul de paranteze: ");
    readTheData(&paranthesis);
    printf("%s \n", paranthesis);
    visited = (int*)calloc(sizeof(int), (strlen(paranthesis)+1));
    for(int i=0; i<strlen(paranthesis); i++){
        push(&top, paranthesis[i], i);
        if(top -> next != NULL){
            if(top -> val == ')' && top -> next -> val == '('){
                visited[top -> position] = 1;
                pop(&top);
                visited[top -> position] = 1;
                pop(&top);
            }
        }
    }
    for(int i=0; i<strlen(paranthesis); i++){
        if(!visited[i]){
            itHasUnpaired = 1;
            printf("%d ", i);
        }
    }
    if(itHasUnpaired == 0){
        printf("It doesn't have any unpaired paranthesis!");
    }

/*
    Queue *queue;
    int numberOfElements = 6;
    queue = createQueue();
    for(int i=0; i<numberOfElements; i++){
        int element;
        QData someData;
        scanf("%d", &element);
        someData = element;
        enQueue(queue, someData);
    }
    Node *top = NULL;
    while(isQueueEmpty(queue) != 1){
        Data value = deQueue(queue);
        printf("%d ", value);
        push(&top, value, 0);
    }
    printf("\n");
    deleteQueue(queue);
    queue = createQueue();
    while(isEmpty(top) == 0){
        Data topValue = pop(&top);
        QData someData = topValue;
        enQueue(queue, someData);
    }
    while(isQueueEmpty(queue) == 0){
        printf("%d ", deQueue(queue));
    }


    /*
    Node *stackTop = NULL;
    int *numberSir = NULL, numberOfElem, maximum = 0, numberOfHigh = 0;
    Data currentNumber;
    readingData(&numberSir, &numberOfElem);
    for(int i=0; i<numberOfElem; i++){
        push(&top, numberSir[i]);
        current = top -> val;
        if(current >= maximum){
            maximum = current;
            numberOfHigh ++;
        }
        else {

    }

    return 0;
}
