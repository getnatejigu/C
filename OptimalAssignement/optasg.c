#include <stdio.h> 
#include <ctype.h>
#include <string.h>

void
dump_arr(int size, int arr[size][size])
{
    int i, j;
    
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


int
reOptimal(int size, int arr[size][size], int aux[size], int machine)
{
    int i, min = 0, task = 0, sum = 0, temp;
    
    //base case 
    if(machine >= size) {
        printf(" %d base\n", machine);
        return 0;
    }
    else {
        int sel_task[size];
        memset(sel_task, -1, size * sizeof(*sel_task));
        
        //find already selected tasks
        for(i = 0; i < machine; i++) {
            sel_task[aux[i]] = 1;
        }
        
        int task = aux[machine];
        //check for all possible uncheck paths
        for(i = 0; i < size; i++) {
            if (sel_task[i] == -1) {
                
                //choose
                sel_task[i] = aux[machine];
                aux[machine] = i;
                
                printf("[%d - %d]", machine, i);

                //recursive call
                sum = arr[machine][aux[machine]] + reOptimal(size, arr, aux, machine+1);
                
                printf("m: %d sum: %d task: %d\n", machine, sum, task);
            
                if ((min == 0) || (min > sum)) {
                    min = sum;
                    task = i;
                }
                
                //unchoose
                aux[machine] = sel_task[i];
            }
        }
    }
    
   
    aux[machine] = task;
    
    return min;
}

void OptimalAssignments(char * strArr[], int size) { 
  
  // code goes here  
  int arr[size][size];
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
  
  //dump_arr(size, arr);
  
  int aux[size], opt;
  
  memset(aux, -1, size * sizeof(*aux));
  
  opt = reOptimal(size, arr, aux, 0);
  
  for(i = 0; i < size; i++) {
      printf("(%d-%d)", i+1, aux[i]+1);
  }
  
  //printf("%s %d", strArr[0], size); 
            
}

int main(void) { 
   
  // keep this function call here
  /* Note: In C you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. */
     
  char * A[] = gets(stdin);
  OptimalAssignments(A, sizeof(A)/sizeof(A[0]));
  return 0;
    
} 


  
