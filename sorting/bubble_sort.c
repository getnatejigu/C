#include <stdio.h>


void
dump_arr(int arr[], int size)
{
	int i;

	for(i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void
bubble_sort(int arr[], int size)
{
	int i, j;

	for(i = size -1; i > 0; i--) {
		dump_arr(arr, size);
		for(j = 0; j < i; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}


int main()
{
	int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	bubble_sort(arr, sizeof(arr)/sizeof(arr[0]));

	dump_arr(arr, 10);


	return 0;
}