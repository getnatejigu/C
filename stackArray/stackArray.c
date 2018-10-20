#include "stackArray.h"


void push(int new_item)
{
	if (first < STACK_SIZE) {
		stack[first++] = new_item;
	} else {
		printf("Stack is full %d \n", first);
	}


}


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



bool is_empty()
{
	return (first == 0);	
}



