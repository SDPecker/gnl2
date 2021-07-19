#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*res;
	char		*buf;
	static char	*memory = 0;
	static int	is_done = 0;

	buf = (char *)malloc(BUFFER_SIZE);
	//Чтение файла
	if (!memory)
		memory = read_file(fd);
	if (is_done)
		return(NULL);
	if (nl_index(memory) >= 0)
	{
		res = get_string(memory);
		memory = clean_string(memory);
		return (res);
	}
	else
	{
		res = get_string(memory);
		is_done = 1;
		return (res);
	}
}

char	*read_file(int fd)
{
	char	*mem;
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE);
	mem = (char *)malloc(1);
	while (read(fd, buf, BUFFER_SIZE) > 0)
		mem = merge(mem, buf);
	return (mem);
}