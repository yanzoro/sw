#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char **argv)
{
	// arg check
	if(argc < 3) {
		printf("usage: %s name1 name2 ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	 // show names
	printf("\nnames:\n");
	for(int i = 1; i < argc; i++) {
		printf("%s\n", argv[i]);
	}

	// choose
	srand(time(NULL));
	printf("\nthe chosen one is: %s\n\n", argv[rand() % (argc - 1) + 1]);

	exit(EXIT_SUCCESS);
}
