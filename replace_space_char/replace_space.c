
/*
 * Problem statement: 
 * 		Write a progam to read and replace all spaces
 *		in a string with '%20'
 */

#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 100

void
replace_space(char *input, char *rep)
{
	int i,j, sp_cnt = 0, new_sz;

	/* count the number of spaces */
	for(i = 0; input[i] != '\0'; i++) {
		if (input[i] == ' ') {
			sp_cnt++;
		}
	}

	/* calculate the new array size */
	new_sz = (sp_cnt * strlen(rep)) + (strlen(input) - sp_cnt) + 1;

	char output[new_sz];

	/* replace the space with the given character string */
	for (i = 0, j = 0; input[i] != '\0'; i++) {
		if (input[i] == ' ') {
			char *p = rep;
			while (*p != '\0') {
				output[j++] = *p++;
			}
		}
		else {
			output[j++] = input[i];
		}
	}
	/* add terminating null */
	output[j] = '\0';

	/* print result */
	printf("output: %s \n", output);
}

int main()
{
	char input[INPUT_SIZE];
	char *rep = "%20";

	/* read input string */
	fgets(input, INPUT_SIZE, stdin);

	replace_space(input, rep);

	return 0;
}

