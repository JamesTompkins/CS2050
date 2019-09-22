#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int empID, ssn, position;
	float salary;
} Record;

int readRecordFile(char* filename, Record*** array);
void adjustSalaries(Record** employees, int n, int position, float x);
void freeRecordArray(Record*** array, int numElems);

int main(){
	char* fileName = "Records.csv";

	Record **records;
	int numRecords = readRecordFile(fileName, &records);

	//check for errors
	if (numRecords == 0) {
		printf("Insufficient memory\n");
		return 1;
	}

	if (numRecords == -1) {
		printf("File could not be opened.\n");
		return 2;
	}

	for (int i = 0; i < numRecords; i++) {
		printf("%i, %i, %i, %f\n", records[i]->empID, records[i]->ssn, records[i]->position, records[i]->salary);
	}

	adjustSalaries(records, numRecords, 10, 1.5f); 
	
	for (int i = 0; i < numRecords; i++) {
		printf("%i, %i, %i, %f\n", records[i]->empID, records[i]->ssn, records[i]->position, records[i]->salary);
	}

	freeRecordArray(&records, numRecords);

	return 0;
}

/*
	This function takes the name of a file and the adress of an array of records
	The function assigns the array to an allocated portion of memory. It returns
	the number of records read from the file, 0 if there was not enough memory or
	-1 if file could not be opened
*/
int readRecordFile(char* filename, Record*** array) {
	FILE* file = NULL;
	file = fopen( filename, "r");
	char junk;

	if (file == NULL) {
		return -1;
	}

	int empAmount;
	fscanf(file, "%i", &empAmount);
	*array = malloc(empAmount * sizeof(Record*));

	for (int i = 0; i < empAmount; i++) {
		Record* record = malloc(sizeof(Record));
		if (record != NULL) {
			fscanf(file, "%i", &record->empID);
			fscanf(file, "%c", &junk);
			fscanf(file, "%i", &record->ssn);
			fscanf(file, "%c", &junk);
			fscanf(file, "%i", &record->position);
			fscanf(file, "%c", &junk);
			fscanf(file, "%f", &record->salary);
			(*array)[i] = record;
		}
		else {
			freeRecordArray(array, empAmount);
		}
	}

	return empAmount;
}

/*
	This function takes in a pointer to an array of employees and adjusts all of
	the employees with the matching position by x (1.5 = 150% original value)
*/
void adjustSalaries(Record** employees, int n, int position, float x) {
	for (int i = 0; i < n; i++) {
		if (employees[i]->position == position) {
			employees[i]->salary *= x;
		}
	}
}

/*
	this function frees a pointer to an array of record pointers of length
	numElems
*/
void freeRecordArray(Record*** array, int numElems) {
	for (int i = 0; i < numElems; i++) {
		Record *record = (*array)[i];
		if (record != NULL) {
			free(record);
			record = NULL;
		}
	}
	free(*array);
	array = NULL;
}