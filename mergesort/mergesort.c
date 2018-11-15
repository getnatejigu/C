#include <stdio.h>

#define ARY_SIZE 10

void print_array(int *arr, int size)
{
	int i;

	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void merge(int *arr, int *aux, int lo, int mid, int hi)
{
	int i, j, k;

	/* copy */
	for (k = lo; k <= hi; k++) {
		aux[k] = arr[k];
	}

	i = lo;
	j = mid + 1;

	//printf("merge: lo: %d mid: %d  hi: %d \n", lo, mid, hi);

	for(k = lo; k <= hi; k++) {
		if (i > mid) {
			arr[k] = aux[j++];
		}
		else if (j > hi) {
			arr[k] = aux[i++];
		}
		else if (aux[i] < aux[j]) {
			arr[k] = aux[i++];
		}
		else {
			arr[k] = aux[j++];
		}
	}
}


void merge_sort(int *arr, int *aux, int lo, int hi)
{
	
	if (lo >= hi) {
		return;
	}

	int mid = lo + (hi - lo) / 2;

	//printf(" lo: %d  mid: %d  hi: %d \n", lo, mid, hi);

	merge_sort(arr, aux, lo, mid);
	merge_sort(arr, aux, mid + 1, hi);
	merge(arr, aux, lo, mid, hi);
}

void sort(int *arr, int size)
{
	int aux[ARY_SIZE];
	merge_sort(arr, aux, 0, ARY_SIZE - 1);
}

int main() 
{
	int arr[ARY_SIZE] = {4, 4, 5, 2, 9, 3, 2, 2, 8, 0};

	printf("Unsorted: \n");
	print_array(arr, ARY_SIZE);

	sort(arr, ARY_SIZE);

	printf("Sorted: \n");
	print_array(arr, ARY_SIZE);
}