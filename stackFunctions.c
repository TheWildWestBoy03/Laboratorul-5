#include "stack.h"

Data top(Node *top){
	if (isEmpty(top)) return INT_MIN;
	return top->val;
}

void push(Node**top, Data v, Position position) {
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->val=v;
	newNode->next=*top;
	newNode -> position = position;
	*top=newNode;
}

Data pop(Node**top) {
	if (isEmpty(*top)) return INT_MIN;
	Node *temp=(*top);
	Data aux=temp->val;
	*top=(*top)->next;
	free(temp);
	return aux;
}

int isEmpty(Node*top){
	return top==NULL;
}

void deleteStack(Node**top){
	Node  *temp;
	while (!isEmpty(*top)){
		temp=*top;
		*top=(*top)->next;
		free(temp);
	}
}

