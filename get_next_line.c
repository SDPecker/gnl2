#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*res;
	char		*buf;
	static char	*memory = 0;
	static int	is_done = 0;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!memory)
	{
		memory = (char *)malloc(1);
		read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		memory = merge(memory, buf);
		ft_bzero(buf, BUFFER_SIZE);
	}
	if (is_done)
		return(NULL);

	if (nl_index(memory) >= 0)
	{
		res = get_string(memory);
		memory = clean_string(memory);
		return (res);
	}

	while (read(fd, buf, BUFFER_SIZE) != 0 && nl_index(buf) < 0 )
	{
		buf[BUFFER_SIZE] = '\0';
		memory = merge(memory, buf);
		ft_bzero(buf, BUFFER_SIZE + 1);
	}

	buf[BUFFER_SIZE] = '\0';
	memory = merge(memory, buf);
	
	if (nl_index(memory) >= 0)
	{
		res = get_string(memory);
		memory = clean_string(memory);
		return (res);
	}
	else
	{
		memory = merge(memory, buf);
		res = get_string(memory);
		is_done = 1;
		return (res);
	}
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;	
	size_t	i;

	p = (char *) s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
