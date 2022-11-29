#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif
char    *get_next_line(int fd);
int main(void)
{
	int fd;
	int stop = 0;
	char *txt;

	fd = open("files/nl", O_RDONLY);
	while (stop < 1000)
	{
	txt = get_next_line(fd);
		printf("%s",txt);
		stop++;
	}
}