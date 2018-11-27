/* 
 * Find the greatest common denominator of two numbers
 * using Euclid's algorithm.
 */

#include <stdio.h>

int
gcd_euclid(int a, int b)
{
	int tmp;

	while (b != 0) {
		tmp = a;
		a = b;
		b = tmp % b;
	}

	return a;
}

int main()
{
	printf("%d\n", gcd_euclid(20, 8));

	printf("%d\n", gcd_euclid(60, 96));

	return 0;
}