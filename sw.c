#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

void usage(char **argv);

int main(int argc, char **argv)
{
	// arg check
	if(argc < 3) {
		usage(argv);
	}

	// flags
	bool ask_flag = false;
	char c;
	
	while((c = getopt(argc, argv, "a")) != -1) {
		switch(c) {
			case 'a':
				ask_flag = true;
				break;
			default:
				usage(argv);
		}
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

void usage(char **argv) {
		printf("usage: %s name1 name2 ...\n", argv[0]);
		exit(EXIT_FAILURE);
}
