#include <stdio.h>

int main()
{
	int val = 1, i;
	char *p = (char*) &val;

	if(*p == 1) {
		printf("little-endian %d \n", *p);
	} else {
		printf("bigendian %d \n", *p);
	}

	for(i = 0; i < sizeof(val); i++) {
		printf("byte %d:  %d \n",i, *p);
		p++;
	}

	return 0;
}
