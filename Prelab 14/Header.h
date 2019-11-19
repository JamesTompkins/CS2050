# include <stdio.h>
# include <stdlib.h>

typedef struct tree {
	int value;
	struct tree *less, *greater;
} Tree;

Tree* insertRandom(int, Tree*);
Tree* initNode(int);
void freeTree(Tree*);
int getHeight(Tree*); 
int countNodes(Tree*);