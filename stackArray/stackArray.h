#ifndef _STACKARRAY_H_
#define _STACKARRAY_H_

#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 10

int stack[STACK_SIZE];
int first;

void push(int new_item);
int  pop();
bool is_empty();

#endif /* _STACKARRAY_H_ */

