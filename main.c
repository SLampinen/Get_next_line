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
	int i = 1;
	char *txt;

	fd = open("files/41_with_nl", O_RDONLY);
	while (i < 10)
	{
	txt = get_next_line(fd);
	printf("%s",txt);
	i++;
	}
}