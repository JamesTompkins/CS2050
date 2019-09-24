#include <stdio.h>
#include <stdlib.h>

int* CreateIntArray(int length, int initValue);
void* CreateArray(int length, int size);

int main( void )
{
	int length = 10;

	//int array
	int* array = CreateIntArray(length, 0);

	for (int i = 0; i < length; i++) {
		printf("%i,", array[i]);
	}

	printf("\n");

	//different array
	double* array2 = CreateArray(length, sizeof(double)); 

	for (int i = 0; i < length; i++) {
		array2[i] = 5;
		printf("%f,", array2[i]);
	}
	
	printf("\n");


	return 0;
}


int* CreateIntArray(int length, int initValue) {
	int *array = malloc(length * sizeof(int));

	if (array != NULL) {
		for (int i = 0; i < length; i++) array[i] = initValue;
	}

	return array;
}

void* CreateArray(int length, int size) {
	return malloc(length * size);
}
