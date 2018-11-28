#include <stdio.h>


int
power(int base, int pow)
{
	/* base case */
	if (pow == 0) {
		return 1;
	}
	else {
		/*  recursion calls */
		return base * power(base, pow - 1);
	}
}


int
factorial(int val)
{
	/* base case */
	if (val == 0) {
		return 1;
	}
	else {
		/* recursion call */
		return val * factorial(val - 1);
	}
}

void
countdown(int num)
{
	/* base case */
	if (num == 0) {
		printf("Done!\n");
		return;
	}
	else {
		/* recursive calls */
		printf("%d ...\n", num);
		countdown(num - 1);
	}
}


int main()
{
	printf("%d to the power of %d is %d \n", 5, 3, power(5, 3));

	printf("%d to the power of %d is %d \n", 1, 10, power(1, 10));

	printf("%d! is %d \n", 5, factorial(5));

	printf("%d! is %d \n", 0, factorial(0));

	countdown(5);

	return 0;
}