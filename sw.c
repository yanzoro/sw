#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

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

	char **names = argv + optind;
	int names_num;
	for(names_num = 0; names[names_num] != NULL; names_num++);
	
	 // show names
	printf("\nnames:\n");
	for(int i = 0; i < names_num; i++) {
		printf("%s\n", names[i]);
	}

	printf("\n"); // to seperate and make it look better

	// ask_flag
	if(ask_flag) {
		for(;;) {
			char c;
			printf("would you like to start? [y/n]: ");
			fflush(stdout); // to instantly print it
			c = getchar();
			if(tolower(c) == 'y')
				break;
			else
				exit(EXIT_SUCCESS);
		}
	}

	// choose
	srand(time(NULL));
	printf("the chosen one is: %s\n\n", names[rand() % (names_num - 1) + 1]);

	exit(EXIT_SUCCESS);
}

void usage(char **argv) {
		printf("usage: %s name1 name2 ...\n", argv[0]);
		exit(EXIT_FAILURE);
}
