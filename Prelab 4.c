#include <stdio.h>
#include <stdlib.h>

void* CreateArray(int numElements, int size); 
int GetSize(void* arr);
void FreeArray(void* arr);

int main()
{
	int size = 10;
	float* arr;

	arr = CreateArray(size, sizeof(float));

	printf("Size: %i", GetSize(arr));

	FreeArray(arr);


	return 0;
}

void* CreateArray(int numElements, int size) {
	int* arr = malloc((numElements * size) + sizeof(int));

	if (arr != NULL) {arr[0] = numElements;}

	arr += 1;

	return (arr);
}

int GetSize(void* arr) {
	int* pointer = arr;
	return (pointer[-1]);
}

void FreeArray(void* arr) {
	int* pointer = arr;
	pointer -= 1;
	free(pointer);
}
