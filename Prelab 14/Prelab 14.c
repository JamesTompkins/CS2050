#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

int main()
{
	srand(time(0));
	int num = 1000000;

	printf("init\n");
	Tree* tree = initTree();

	printf("Looping\n");
	for (int i = 0; i < num; i++) {
		if (i % (num/7) == 0) {
			printf("%f \% \n", 100 * (float)i/num);
		}
		insertRandom(tree);
	}

	printf("%i\n", getHeight(tree));

	freeTree(tree);

	return 0;
}