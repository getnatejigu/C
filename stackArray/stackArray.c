#include "stackArray.h"

/* Add to the top of the stack */
void push(int new_item)
{
	if (first < STACK_SIZE) {
		stack[first++] = new_item;
	} else {
		printf("Stack is full %d \n", first);
	}


}

/* retrieve the top of the stack */
int pop()
{
	int ret = -1;

	if ((first - 1) >= 0) {
		ret = stack[--first];
		stack[first] = 0;
	} else {
		printf("Stack is empty \n");
	}

	return ret;
}


/* check if the stack is empty */
bool is_empty()
{
	return (first == 0);	
}



