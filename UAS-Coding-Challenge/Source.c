
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(const int *unsorted, int *sorted, int length);

#define MAX_ELEMENTS 10
#define MAX_NUMBER 100
int main(void)
{
	srand(time(NULL));
	const int length = rand()%(MAX_ELEMENTS-5)+5;								// Determines the number of elements in the arrays
	int *test_arr = (int *)malloc(length * sizeof(int));						// Min number of elements in the array is 5 and the max is MAX_NUMBER
	int *sorted_arr = (int *)malloc(length * sizeof(int));
	if (!test_arr || !sorted_arr)												// Checks to see if the pointer arrays have been successfully declared
	{
		printf("Error: Not enough memory on the heap\n");
		system("pause");
		return -1;
	}
	printf("The test array is:\n");
	for (int i = 0; i < length; i++)											// Initialiazes the elements of the pointer array with 
	{																			// random numbers from 0 to MAX_NUMBER and prints them
		test_arr[i] = rand() % MAX_NUMBER;
		printf("%d ", test_arr[i]);
	}
	printf("\n\n");
	sort(test_arr, sorted_arr, length);											// Calls sort and prints the sorted array
	printf("The sorted array is:\n");
	for (int index = 0; index < length; index++)
		printf("%d ", sorted_arr[index]);
	printf("\n\n");
	system("pause");
	return 0;
}

void sort(const int *unsorted, int *sorted, int length)
{
	int smallest_num, previous_num = -1, num_duplicates=0;
	for (int i = 0; i < length; i++)
	{
		smallest_num = MAX_NUMBER + 1;											// Resets the value of smallest_num
		for (int j = 0; j < length; j++)
		{
			if (unsorted[j] == smallest_num)
				num_duplicates++;
			else if (unsorted[j] < smallest_num && unsorted[j] > previous_num)	// Checks to see if unsorted[j] is less than smallest_num and 
			{																	// checks if it has already been moved to the sorted array
				smallest_num = unsorted[j];
				num_duplicates = 0;												// If it is smaller it becomes the new smallest_num and num_duplicates is reset
			}
		}
		for (int k = 0; k < num_duplicates+1; k++)								// Copies the smallest num and the correct number of duplicates to the sorted array
			sorted[i+k] = smallest_num;
		i += num_duplicates;
		num_duplicates = 0;
		previous_num = smallest_num;											// Assigns smallest_num to previous_num to keep track of which numbers have been moved
	}
	return;
}

