#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

int main()
{
	srand(time(0));
	int num = 1000000;

	printf("init\n");
	Tree* tree = NULL;

	printf("Looping\n");
	for (int i = 0; i < num; i++) {
		tree = insertRandom(rand(), tree);
	}

	printf("Height %i\n", getHeight(tree)); 
	printf("Nodes %i\n", countNodes(tree));

	freeTree(tree);

	return 0;
}