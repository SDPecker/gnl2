#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	
	int fd = open("example_empty", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// char *s = get_next_line(fd);
	// printf("%s", s);
	// free(s);
	// while(1);
	return (0);
}