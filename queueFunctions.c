#include "queue.h"
Queue* createQueue(){
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	if (q==NULL) return NULL;
	q->front=q->rear=NULL;
	return q;
}

 void enQueue(Queue *q, QData v){
	QNode* newNode=(QNode*)malloc(sizeof(QNode));
	newNode->val=v;
	newNode->next=NULL;
	if (q ->rear==NULL) q->rear=newNode;
	else{
		(q->rear)->next=newNode;
		(q->rear)=newNode;
	}
	if (q->front==NULL) q->front=q->rear;
}

QData deQueue(Queue*q) {
	QNode* aux; QData d;
	if (isQueueEmpty(q)) return INT_MIN;

	aux=q->front;
	d=aux->val;
	q->front=(q->front)->next;
	free(aux);
	return d;
}

int isQueueEmpty(Queue*q){
	return (q->front==NULL);
}

void deleteQueue(Queue*q){
	QNode* aux;
	while (!isQueueEmpty(q)){
		aux=q->front;
		q->front=q->front->next;
		free(aux);
	}
	free(q);
}

