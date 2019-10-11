#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node* next;
} Node;

//head.next is first element, tail.next is last element
typedef struct List {
	int count;
  Node* head;
  Node* tail;
} List;

List* initIntegerList();
int insertAtHead(int, List*);
int insertAtTail(int, List*);
int removeHead(List*);
int getListSize(List*);
void printHead(List*);
void moveHeadToTail(List*);
void freeList(List** list);
void printList(List* list);

int main() {
  List* list = initIntegerList();
  if (list == NULL) {
    printf("list not initialized\n");
    return 1;
  }

	printf("Adding 20 random numbers:\n");
	for (int i=0; i<10; i++) {
		insertAtHead(rand() % 100, list);
		insertAtTail(rand() % 100, list);
		printList(list);
	}
	
	printf("Moving head to tail 5 times:\n");
	for (int i=0; i<5; i++) {
		moveHeadToTail(list);
		printList(list);
	}
	
	printf("Removing head:\n");
	removeHead(list);
	printList(list);

	freeList(&list);

  return 0;
}

List* initIntegerList() {
  List* newList = malloc(sizeof(List));
  if(newList == NULL) {return NULL;}

  Node* frontDummy =malloc(sizeof(Node));
  Node* endDummy =malloc(sizeof(Node));
  if(newList && frontDummy && endDummy) {
    newList->count = 0;
    frontDummy->next = endDummy;
    endDummy->next = frontDummy;

    newList->head = frontDummy;
    newList->tail = endDummy;

    return newList;
  } else {
    if (newList){free(newList);}
    if (frontDummy) {free(frontDummy);}
    if (endDummy) {free(endDummy);}
    return NULL;
  }
}

int insertAtHead(int k, List* list) {
  Node* newNode = malloc(sizeof(Node));
  
  if(newNode == NULL) {return 0;}
	
	if(getListSize(list) == 0) {list->tail->next = newNode;}
	newNode->key = k;
	newNode->next = list->head->next;
	list->head->next = newNode;
	list->count ++;

  return 0;
}

int insertAtTail(int k, List* list) {
  Node* newNode = malloc(sizeof(Node));
  
  if(newNode == NULL) {return 0;}
	
	newNode->key = k;
	newNode->next = NULL;
	list->tail->next->next = newNode;
	list->tail->next = newNode;
	list->count ++;
  return 0;
}

int removeHead(List* list) {
	if(getListSize(list) < 1) {return 0;}
	Node* node = list->head->next;
	list->head->next = node->next;
	list->count --;
	free(node);

  return 0;
}

int getListSize(List* list) {
  return list->count;
}

void printHead(List* list) {
	if(getListSize(list) == 0) {
		return;
	} else {
		printf("%i\n", list->head->next->key);
	}
}

void moveHeadToTail(List* list) {
	Node* head = list->head->next;
	list->head->next = head->next;
	list->tail->next->next = head;
	list->tail->next = head;
	head->next = NULL;
}

void freeList(List** l) {
	List* list = *l;
	while(list->count > 0) {removeHead(list);}

	free(list->tail);
	free(list->head);
	free(list);
	*l = NULL;
}

void printList(List* list){
	Node* current = list->head->next;
	while (current) {
		printf("%i, ", current->key);
		current = current->next;
	}
	printf("\n");
}