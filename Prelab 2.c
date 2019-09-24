#include "stdio.h"

void lessThanAndGreater(int arr[], int length, int testNumber, int* less, int* greater);
void test(int arr[], int length, int testnumber, int less, int more);

int main()
{
	int length;

	int arr1[] = { 2,4,1,7,5,2,9,7,4,2 };
	length = 10;
	test(arr1, length, 5, 6, 3);

	int arr2[] = { 1,2,3,4 };
	length = 4;
	test(arr2, length, 2, 1, 2);

	int arr3[] = { 1,1,1,1,1,1, };
	length = 6;
	test(arr3, length, 1, 0, 0); 
	
	int arr4[] = { 999999999,1111111111,111111111 };
	length = 3;
	test(arr4, length, 999999999, 1, 1);

	return 0;
}

void test(int arr[], int length, int testnumber, int lessTarget, int moreTarget) {
	int less, more;
	lessThanAndGreater(arr, length, testnumber, &less, &more);

	if (less != lessTarget) {
		printf("Less Wrong");
	}
	else if (more != moreTarget) {
		printf("More Wrong");
	}
	else {
		printf("Correct");
	}
	printf("\n");
}

void lessThanAndGreater(int arr[], int length, int testNumber, int* lessInput, int* greaterInput)
{
	int lessThan = 0;
	int greaterThan = 0;

	for (int i = 0; i < length; i++) {
		int currentNumber = arr[i];

		if (currentNumber < testNumber) ++lessThan;
		if (currentNumber > testNumber) ++greaterThan;
	}

	*greaterInput = greaterThan;
	*lessInput = lessThan;

}
