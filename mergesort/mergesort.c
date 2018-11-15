#include <stdio.h>

#define ARY_SIZE 10

/* 1 for recursive merge sort */
/* 0 for interative merge sort */
#define ENABLE_RECUSIVE 1      
	

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

	/* merge sorted halves */
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

/*
 * ENABLE_RECUSIVE set to 0 
 * uses iterative algorithm for merge sort
 */
void iterative_merge_sort(int *arr, int *aux, int size)
{
	int i, lo;

	for (i = 1; i < size; i = i + i) {
		for (lo = 0; lo < (size - i); lo += i + i) {
			int min = ((lo + i + i - 1) < (size - 1)) ? (lo + i + i - 1) : (size - 1);
			merge(arr, aux, lo, (lo + i - 1), min);
		}
	}
}

/*
 * ENABLE_RECUSIVE set to 1 
 * uses recursive algorithm for merge sort
 */
void recursive_merge_sort(int *arr, int *aux, int lo, int hi)
{
	
	if (lo >= hi) {
		return;
	}

	int mid = lo + (hi - lo) / 2;

	recursive_merge_sort(arr, aux, lo, mid);
	recursive_merge_sort(arr, aux, mid + 1, hi);
	merge(arr, aux, lo, mid, hi);
}

void sort(int *arr, int size)
{
	int aux[ARY_SIZE]; /* temporary array */

	/* begin sorting here */
	if (ENABLE_RECUSIVE) {
		recursive_merge_sort(arr, aux, 0, ARY_SIZE - 1);
	}
	else {
		iterative_merge_sort(arr, aux, ARY_SIZE);
	}
}

int main() 
{
	/* array to be sorted */
	int arr[ARY_SIZE] = {4, 4, 5, 2, 9, 3, 2, 2, 8, 0};

	printf("Unsorted: \n");
	print_array(arr, ARY_SIZE);

	/* generic sort method */
	sort(arr, ARY_SIZE);

	printf("Sorted: \n");
	print_array(arr, ARY_SIZE);
}