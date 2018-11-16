#include <stdio.h>

#define A_SZ 4


void print_table(int sz, char input[][sz])
{
	int i, j;
	for (i = 0; i < sz; i++) {
		for (j = 0; j < sz; j++) {
			printf("%c ", input[i][j]);
		}
		printf("\n");
	}
}

int count_friends_circle(int sz, char input[][sz])
{
	int i, j, has_friends, count = 0;

	for (i = 0; i < sz; i++) {
		has_friends = 0;
		for (j = 0; j < sz; j++) {
			if ((input[i][j] != 'N') && (input[i][j] != 'Y')) {
				has_friends = 1;
			}
			if ((input[i][j] == 'Y') && (i != j)) {
				input[j][i] = '-';
			}
		}
		if (!has_friends) {
			count++;
		}
	}

	return count;
}



int main()
{
	char input[A_SZ][A_SZ] = {{'Y','Y','N','N'},
                            {'Y','Y','N','N'},
                            {'N','N','Y','Y'},
                            {'N','N','Y','Y'}};

	print_table(A_SZ, input);

	int count = count_friends_circle(A_SZ, input);

	printf("Friends circle: %d \n", count);

	return 0;
}
