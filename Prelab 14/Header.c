# include <stdio.h>
# include <stdlib.h>
# include "Header.h"

Tree* insertRandom(int value, Tree* tree) {
	if (tree == NULL) {
		return initNode(value);
	}

	if (rand() % 2) {
		tree->less = insertRandom(value, tree->less);
	} else {
		tree->greater = insertRandom(value, tree->greater);
	}

	return tree;
}

Tree* initNode(int value) {
	Tree* newTree = malloc(sizeof(Tree));
	if (newTree != NULL) {
		newTree->value = value;
		newTree->less = NULL;
		newTree->greater = NULL;
	}
	return newTree;
}

void freeTree(Tree* t) {
	if (t == NULL) {
		return;
	}

	freeTree(t->less);
	freeTree(t->greater);
	free(t);
}

int getHeight(Tree* tree) {
	if (tree == NULL) {
		return 0;
	}

	int left = getHeight(tree->less);
	int right = getHeight(tree->greater);
	int greater = left > right ? left : right;

	return greater + 1;
}

int countNodes(Tree* tree) {
	if (tree == NULL) {
		return 0;
	}

	int left = countNodes(tree->less);
	int right = countNodes(tree->greater);

	return (left + right + 1);
}