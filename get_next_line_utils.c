#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		nl_index(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return(i);
		i++;
	}
	return (-1);
}

char	*get_string(char *str)
{
	char	*res;
	int		i;
	int		l;

	i = 0;
	l = nl_index(str);
	if (l < 0)
		res = (char *)malloc(ft_strlen(str) + 1);
	else
		res = (char *)malloc(l + 2);
	if (!res)
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = str[i];
	if (res[i] == '\n')
		res[i + 1] = 0;
	return (res);
}

char	*clean_string(char *str)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = nl_index(str);
	if (i < 0)
	{
		res = (char *)malloc(0);
		return(res);
	}
	res = (char *)malloc(ft_strlen(str) - i);
	i++;
	if (!res)
		return (NULL);
	while (str[i])
		res[j++] = str[i++];
	res[j] = 0;
	return (res);
}

char	*merge(char *ln1, char *ln2)
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc(ft_strlen(ln1) + ft_strlen(ln2) + 1);
	i = 0;
	j = 0;
	while (ln1[i] != 0)
	{
		res[i] = ln1[i];
		i++;
	}
	while (ln2[j] != 0)
	{
		res[i + j] = ln2[j];
		j++;
	}
	res[i + j] = 0;
	return(res);
}