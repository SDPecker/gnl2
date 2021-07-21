#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*clean_string(char	*str);
char	*get_string(char *str);
char	*merge(char *ln1, char *ln2);
int		nl_index(char *s);
char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
void	get_memory(char *memory, char *buf, int fd);
char	*create_memory(char *buf, int fd);
char	*process_eof(char *memory, char *buf);

#endif
