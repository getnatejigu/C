#include "stackArray.h"

void print_stack()
{
	int i = 0;

	while(i < first)
	{
		printf("%d ", stack[i]);
		i++;
	}
	printf("\n");
}

int main()
{
	
	push(10);

	push(13);

	print_stack();

	printf("Pop: %d \n", pop());

	int i;
	for(i = 0; i < 12; i++) {
		push(i);
	}

	print_stack();

	while(!is_empty()) {
		printf("Pop: %d \n", pop());
		print_stack();
	}

	printf("Stack is %s \n", ((is_empty()) ? "empty" : "not empty"));

	return 0;
}
