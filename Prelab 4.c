#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int employeeID, ssn, position;
	float salary;
} Record;


void* CreateArray(int numElements, int size);
int GetSize(void* arr);
void FreeArray(void* arr);
void ReadRecords(Record* arr);


int main()
{
	//read first line
	FILE* file = NULL;
	fopen_s(&file, "Records.txt", "r");

	if (file == NULL) {
		printf("could not open file");
		return 1;
	}
	else {
		printf("File open\n");
	}

	int numRecords;
	fscanf_s(file, "%i", &numRecords);
	printf("%i\n",numRecords);


	//initialize employee list
	Record* employees = CreateArray(numRecords, sizeof(Record));

	//read in employee records
	for (int i = 0; i < numRecords; i++) {
		fscanf_s(file, "%i", &employees[i].employeeID);
		fscanf_s(file, "%i", &employees[i].ssn);
		fscanf_s(file, "%i", &employees[i].position);
		fscanf_s(file, "%f", &employees[i].salary);
	}

	//print the information of each
	for (int i = 0; i < numRecords; i++) {
		printf("ID: %i SSN: %i PosID %i Salary: %f\n", employees[i].employeeID, employees[i].ssn, employees[i].position, employees[i].salary);
	}

	FreeArray(employees);

	return 0;
}

/*
	The createArray function takes the number of elements in the desired array and
	the size of each element and returns a pointer for the array
*/
void* CreateArray(int numElements, int size) {
	int* arr = malloc((numElements * size) + sizeof(int));

	if (arr != NULL) { arr[0] = numElements; }

	arr += 1;

	return (arr);
}

/*
	GetSize takes a pointer to an array created by createArray and returns the 
	number of elements in the array
*/
int GetSize(void* arr) {
	int* pointer = arr;
	return (pointer[-1]);
}

/*
	used to free an array created by CreateArray function
*/
void FreeArray(void* arr) {
	int* pointer = arr;
	pointer -= 1;
	free(pointer);
}