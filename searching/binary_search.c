#include <stdio.h>

void
dump_arr(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int
binary_search(int arr[], int size, int item)
{
	int lower, upper, mid;
	int ret = -1;

	lower = 0;
	upper = size - 1;

	while(lower <= upper) {

		mid = (upper + lower) / 2;
		
		if (arr[mid] == item) {
			ret = mid;
			break;
		}

		if (item > arr[mid]) {
			lower = mid + 1;
		}
		else {
			upper = mid - 1;
		}
	}

	return ret;
}



int
qs_partition(int arr[], int first, int last)
{
	int low, upper, pvt, temp;

	pvt = arr[first];
	low = first + 1; 
	upper = last;

	int done = 0;
	while(!done) {
		while((arr[low] <= pvt) && (low <= upper)) {
			low++;
		}

		while((arr[upper] >= pvt) && (upper >= low)) {
			upper--;
		}

		if (upper < low) {
			done = 1;
		}
		else {
			temp = arr[low];
			arr[low] = arr[upper];
			arr[upper] = temp;
		}
	}

	temp = arr[first];
	arr[first] = arr[upper];
	arr[upper] = temp;

	return upper;

}


void
quicksort(int arr[], int first, int last)
{
	int pvt;

	if (first < last) {
		pvt = qs_partition(arr, first, last);

		quicksort(arr, first, pvt - 1);
		quicksort(arr, pvt + 1, last);
	}
}


int main()
{
	int arr[10] = {2, 13, 32, 7, 6, 77, 32, 9, 212, 1};

	quicksort(arr, 0, 10 - 1);

	dump_arr(arr, 10);

	int find = 1;
	printf(" %d found at index: %d \n", find, binary_search(arr, 10, find));

	find = 33;
	printf(" %d found at index: %d \n", find, binary_search(arr, 10, find));

	find = 32;
	printf(" %d found at index: %d \n", find, binary_search(arr, 10, find));

	return 0;
}