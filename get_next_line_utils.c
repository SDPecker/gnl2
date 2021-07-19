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
	while (s[i++])
	{
		if (s[i] == '\n')
			return(i);
	}
	return (-1);
}

char	*get_string(char *str)
{
	char	*res;
	int		i;
	while (str[i] != '\n' && str[i])
		i++;
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = str[i];
	return (res);
}

char	*clean_string(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	i = nl_index(str);
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
	while (ln1[i] != 0 && ln1[i] != '\n')
	{
		res[i] = ln1[i];
		i++;
	}
	while (ln2[j] != 0 && ln2[j] != '\n')
	{
		res[i + j] = ln2[j];
		j++;
	}
	res[i + j] = 0;
	return(res);
}