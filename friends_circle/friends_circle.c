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

/* Implementation using the same array to keep track of friends circle */
int inplace_friends_circle(int sz, char input[][sz])
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

/* Implementation with hash table to keep track of friends circle */
int hash_friend_circles(int sz, char input[][sz])
{
	int i, j, count = 0;

	int hash[sz];

	/* initialize the hash array */
	for (i = 0; i < sz; i++) {
		hash[i] = -1;
	}

	for (i = 0; i < sz; i++) {
		for (j = i + 1; j < sz; j++) {
			if (input[i][j] == 'Y') {
				if ((hash[i] == -1) && (hash[j] == -1)) {
					count++;
					hash[i] = count;
					hash[j] = count;
				}
				else if (hash[i] == -1) {
					hash[i] = hash[j];
				}
				else if (hash[j] == -1) {
					hash[j] = hash[i];
				}
			}
		}

		if (hash[i] == -1) {
			count++;
			hash[i] = count;
		}
	}

	return count;
}



int main()
{
	char input[A_SZ][A_SZ] = {{'Y','Y','N','N'},
				  {'Y','Y','Y','N'},
				  {'N','Y','Y','N'},
				  {'N','N','N','Y'}};

	print_table(A_SZ, input);

	/* uncomment either lines below to test either implementations */
	//int count = inplace_friends_circle(A_SZ, input);
	int count = hash_friend_circles(A_SZ, input);

	printf("Friends circle: %d \n", count);

	return 0;
}
