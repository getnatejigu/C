#ifndef _STACKARRAY_H_
#define _STACKARRAY_H_

#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 10

/* fixed stack array */
int stack[STACK_SIZE];
/* holds index to top of the stack */
int first;

/* functions to manipulate the stack */
void push(int new_item);
int  pop();
bool is_empty();

#endif /* _STACKARRAY_H_ */

