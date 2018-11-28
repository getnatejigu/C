/*

Implement the function SecondGreatLow(arr) take the array of numbers stored in arr and return the 
second lowest and second greatest numbers, respectively, separated by a space. 
For example: if arr contains [7, 7, 12, 98, 106] the output should be 12 98. 
The array will not be empty and will contain at least 2 numbers. It can get tricky if there's just two numbers! 

Sample Test Cases

Input:1, 42, 42, 180
Output:"42 42"


Input:4, 90
Output:"90 4"


*/

#include <stdio.h>

void
print_array(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

/* merge sort */
void
merge(int arr[], int aux[], int lo, int mid, int hi)
{
    int i, j, k;
    for(i = lo; i <= hi; i++) {
        aux[i] = arr[i];
    }
    
    i = lo;
    j = mid + 1;
    for(k = lo; k <= hi; k++) {
        if(i > mid) {
            arr[k] = aux[j++]; 
        }
        else if(j > hi) {
            arr[k] = aux[i++];
        }
        else if(aux[i] < aux[j]) {
            arr[k] = aux[i++];
        }
        else {
            arr[k] = aux[j++];
        }
    }
}


void
recursive_merge_sort(int arr[], int aux[], int lo, int hi)
{
    if (lo >= hi) {
        return;
    }
    
    int mid = lo + ((hi - lo) / 2);
    
    recursive_merge_sort(arr, aux, lo, mid);
    recursive_merge_sort(arr, aux, mid+1, hi);
    merge(arr, aux, lo, mid, hi);
}

void
merge_sort(int arr[], int size)
{
    int aux[size];
    
    recursive_merge_sort(arr, aux, 0, size - 1);
}


/* Selection Sort */
void
selection_sort(int arr[], int size)
{
    int i, j, sel;
    
    for(i = 0; i < size; i++) {
        sel = arr[i];
        for(j = i; j < size; j++) {
            if (sel > arr[j]) {
                int tmp = arr[j];
                arr[j] = sel;
                sel = tmp;
            }
        }
        arr[i] = sel;
    }
}

/* Bubble sort */
void
bubble_sort(int arr[], int size)
{
    int i, j;
    
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

/* Generic Sorting API */
void
sort(int arr[], int size)
{
    merge_sort(arr, size);
    
    //selection_sort(arr, size);
    
    //bubble_sort(arr, size);
}

void SecondGreatLow(int arr[], int size) { 
  
  // code goes here 
  int lw2, gt2;
  int i;

  sort(arr, size);
  
  lw2 = arr[0];
  for(i = 0; i < size; i++) {
      if (lw2 < arr[i]) {
          lw2 = arr[i];
          break;
      }
  }
  
  gt2 = arr[size-1];
  for(i = size-1; i >= 0; i--) {
      if (gt2 > arr[i]) {
          gt2 = arr[i];
          break;
      }
  }
  
  printf("%d %d", lw2, gt2); 
            
}

int main(void) { 
   
  // keep this function call here
  /* Note: In C you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. */
     
  int A[] = gets(stdin);
  SecondGreatLow(A, sizeof(A)/sizeof(A[0]));
  return 0;
    
}

  
