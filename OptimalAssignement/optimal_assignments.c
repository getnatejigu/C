#include <stdio.h> 
#include <ctype.h>
#include <string.h>


/* convert char array of number to integer array */
void
parse_str_int(int size, int arr[][size], char *strArr[])
{
      int i, j;
  
      for(i = 0; i < size; i++) {
          
          char *strptr = strArr[i];
          
          for(j = 0; j < size; j++) {
              arr[i][j] = 0;
              int dec = 1;
              while((*strptr != ',') && (*strptr != ')')) {
                  if(isdigit(*strptr)) {
                      arr[i][j] = (*strptr - '0') + (dec * arr[i][j]);
                      dec *= 10;
                  }
                  strptr++;
              }
              strptr++;
          }
      }
}


/* recursive function of find the optimal path assignment */
void
reOptimal(int size, int arr[size][size], int aux[size], int machine, int final_opt[])
{
    int i, min = 0, task = 0, sum = 0, temp = 0;
    
    /* base case */
    if(machine >= size) {
        /* sum all the selection and most recent optimal selection */
        for (i = 0; i < size; i++) {
            temp += arr[i][aux[i]];
            if(final_opt[i] != -1) {
                sum += arr[i][final_opt[i]];    
            }
        }
        
        /* check for more optimal path and update the final optimal selection */
        if ((sum <= 0) || (temp < sum)) {
            for(i = 0; i < size; i++) {
                final_opt[i] = aux[i];
            }
        } 
        return;
    }
    else {
        int sel_task[size];
        memset(sel_task, -1, size * sizeof(*sel_task));
        
        /* find already selected tasks */
        for(i = 0; i < machine; i++) {
            sel_task[aux[i]] = 1;
        }
        
        /* check for all possible uncheck paths */
        for(i = 0; i < size; i++) {
            if (sel_task[i] == -1) {
                
                //choose
                aux[machine] = i;
                
                //recursive call
                reOptimal(size, arr, aux, machine+1, final_opt);
                
                //unchoose
                aux[machine] = -1;
            }
        }
    }
}

void OptimalAssignments(char * strArr[], int size) { 
  
  // code goes here  
  int arr[size][size];
  int i;
  
  /* convert char string for the input to integer array */
  parse_str_int(size, arr, strArr);
  
  int aux[size], final_opt[size];
  
  /* initialize array for temporary and final optimal assignments */
  memset(aux, -1, size * sizeof(*aux));
  memset(final_opt, -1, size * sizeof(*aux));
  
  /* call recursive function to find optimal assignment */
  reOptimal(size, arr, aux, 0, final_opt);
  
  /* Print final optimal assignment  */
  for(i = 0; i < size; i++) {
      printf("(%d-%d)", i+1, final_opt[i]+1);
  }
  
}

int main(void) { 
   
  // keep this function call here
  /* Note: In C you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. */
     
  char * A[] = gets(stdin);
  OptimalAssignments(A, sizeof(A)/sizeof(A[0]));
  return 0;
    
}
