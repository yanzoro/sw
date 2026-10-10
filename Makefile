CC ?= cc

sw: sw.c
	$(CC) -Wall -Wextra -Werror sw.c -o sw
	
