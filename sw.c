#include <stdio.h>

int main(int argc, char **argv)
{
	// arg check
	if(argc < 2) {
		printf("usage: %s name1 ...\n", argv[0]);
		return 1;
	}
	 // show names
	printf("names:\n");
	for(int i = 1; i < argc; i++) {
		printf("%s\n", argv[i]);
	}

	return 0;
}
