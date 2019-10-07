#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	int key;
	struct List* next;
} List;

//not using dummy nodes
List* initIntegerList();
int insertAtHead(List** head, int key);
int insertAtTail(List* head, int key);
void printList(List* head);
void freeList(List** head);

//using dummy nodes
List* dInitIntegerList();
int dInsertAtHead(List* head, int key);
int dInsertAtTail(List* head, int key);
void dPrintList(List* head);
void dFreeList(List** head);

int main()
{
	List* list = initIntegerList();

	//testing regular list
	if (list) {
		insertAtHead(&list, 5);
		insertAtHead(&list, 2);
		insertAtHead(&list, 8);
		insertAtTail(list, 10);
		insertAtTail(list, 15);
		insertAtTail(list, 22);

		printList(list);
	}
	freeList(&list);

	//testing dummy list
	List* dList = dInitIntegerList();
	if (dList) {
		dInsertAtHead(dList, 5);
		dInsertAtHead(dList, 2);
		dInsertAtHead(dList, 8);
		dInsertAtTail(dList, 10);
		dInsertAtTail(dList, 15);
		dInsertAtTail(dList, 22);

		dPrintList(dList);
	}
	dFreeList(&dList);

	return 0;
}

/*
	===========================
		NON DUMMY FUNCTIONS
	===========================
*/

/*
	This function initializes an integer list with memory and next assigned to null
*/
List* initIntegerList() {
	List* head = malloc(sizeof(List));
	if (head) {
		head->next = NULL;
		return head;
	}
}

/*
	This function inserts a new node at the head of the list and initializes the key
	returns 0 if usuccesful, 1 if succesfull
*/
int insertAtHead(List** head, int key) {
	List* newNode = malloc(sizeof(List));
	if (newNode) {
		newNode->key = key;
		newNode->next = (*head)->next;
		(*head)->next = newNode;
		return 1;
	} else {
		return 0;
	}
}

/*
	This function inserts a new node at the tail and initializes the key
	Returns 0 if unsuccesfull, 1 if succesful 
*/
int insertAtTail(List* head, int key) {
	List* current = head;
	while (current->next != NULL) {
		current = current->next;
	}

	List* newNode = malloc(sizeof(List));
	if (newNode) {
		newNode->key = key;
		newNode->next = NULL;
		current->next = newNode;
		return 1;
	} else {
		return 0;
	}
}

/*
	This function takes the head of a list and prints all of the elements seperated by commas
*/
void printList(List* head) {
	List* current = head->next;
	if (!current) {
		return;
	}

	for (; current; current = current->next) {
		printf("%i, ", current->key);
	}
	printf("\n");
}

/*
	This function frees all of the memory used by a list
*/
void freeList(List** head) {
	List* current = (*head);
	if (current->next) {
		freeList(&(current->next));
	}
	free(current);
	*head = NULL;
}

/*
	=======================
		DUMMY FUNCTIONS
	=======================
*/

/*
	This function initializes an integer list with memory and dummy nodes
*/
List* dInitIntegerList() {
	List* head = malloc(sizeof(List));
	List* StartDummy = malloc(sizeof(List));
	List* endDummy = malloc(sizeof(List));

	if (head && StartDummy && endDummy) {
		head->next = StartDummy;
		StartDummy->next = endDummy;
		endDummy->next = NULL;
	}
	else {
		if (head) {free(head);}
		if (StartDummy) {free(StartDummy);}
		if (endDummy) {free(endDummy);}
		return NULL;
	}

	return head;
}

/*
	This function inserts a new node at the head of the list and initializes the key
	returns 0 if usuccesful, 1 if succesfull
*/
int dInsertAtHead(List* head, int key) {
	List* newNode = malloc(sizeof(List));
	List* firstDummy = head->next;

	if (newNode) {
		newNode->next = firstDummy->next;
		newNode->key = key;
		firstDummy->next = newNode;
		return 1;
	} else {
		return 0;
	}
}

/*
	This function inserts a new node at the tail and initializes the key
	Returns 0 if unsuccesfull, 1 if succesful
*/
int dInsertAtTail(List* head, int key) {
	List* newNode = malloc(sizeof(List));
	List* current = head->next;

	while (current->next->next) {
		current = current->next;
	}
	if (newNode) {
		newNode->next = current->next;
		newNode->key = key;
		current->next = newNode;
		return 1;
	}
	else {
		return 0;
	}
}

/*
	This function takes the head of a list and prints all of the elements seperated by commas
*/
void dPrintList(List* head) {
	List* current = head->next;
	if (current->next == NULL) {return;}

	while (current->next->next) {
		current = current->next;
		printf("%i, ", current->key);
	}
	printf("\n");
}

/*
	This function frees all of the memory used by a dummy list
*/
void dFreeList(List** head) {
	List* current = (*head);
	if (current->next) {
		freeList(&(current->next));
	}
	free(current);
	*head = NULL;
}