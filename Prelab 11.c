#include <stdio.h>
#include <stdlib.h>

typedef struct nodestruct{
	int item;
	float priority;
	struct nodestruct* next;
} Node;

typedef struct {
	int count;
	Node* front;
} PQ;

PQ* initPQ();
int insertPQ(int, float, PQ*);
int deleteMax(PQ*, int*);
int getSize(PQ*);
void reInitPQ(PQ*);
void freePQ(PQ*);
void printQueue(PQ*);

int main()
{
	PQ* pq = initPQ();

	//adding 1-5
	for (int i = 0; i < 5; i++) {
		printf("Adding \n");
		insertPQ(i * i, i, pq);
		printQueue(pq);
	}

	//adding -1 - -5
	for (int i = 0; i < 5; i++) {
		printf("Adding \n");
		insertPQ(i * i, -i, pq);
		printQueue(pq);
	}

	reInitPQ(pq);
	printQueue(pq);

	freePQ(pq);
}

PQ* initPQ() {
	PQ* newPQ = malloc(sizeof(PQ));

	if (newPQ) {
		newPQ->count = 0;
		newPQ->front = NULL;
	}
	return newPQ;
}

/*
	Returns 0 if succesful, 1 if not
*/
int insertPQ(int value, float priority, PQ* pq) {
	Node* newNode = malloc(sizeof(Node));

	if (newNode == NULL) {
		return 1;
	}

	newNode->item = value;
	newNode->priority = priority;

	Node* current = pq->front;

	if (current == NULL) {
		pq->front = newNode;
		newNode->next = NULL;
	}
	else if (current->priority < priority) {
		newNode->next = current;
		pq->front = newNode;
	}
	else {
		while (current->priority > priority && current->next) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}

	pq->count++;

	return 0;
}

/*
	returns 1 if already empty 0 otherwise
*/
int deleteMax(PQ* pq, int* value) {
	if (pq->front == NULL) {
		return 1;
	}

	Node* node = pq->front;

	if (pq->count > 1) {
		pq->front = node->next;
	}
	else {
		pq->front = NULL;
	}
	pq->count--;
	free(node);
}

int getSize(PQ* pq) {
	return pq->count;
}

void reInitPQ(PQ* pq) {
	while (pq->count > 0) {
		int j;
		deleteMax(pq, &j);
	}
}

void freePQ(PQ* pq) {
	while (pq->count > 0) {
		int j;
		deleteMax(pq, &j);
	}
	free(pq);
}

void printQueue(PQ* pq) {
	Node* node = pq->front;
	if (node == NULL) {
		printf("Queue empty.\n");
		return;
	}

	printf("Queue: ");

	for (int i = 0; i < pq->count; i++) {
		printf("%i:%f, ", node->item, node->priority);
		node = node->next;
	}

	printf("\n");
}