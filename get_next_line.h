#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 32

size_t	ft_strlen(const char *s);
char	*clean_string(char	*str);
char	*get_string(char *str);
char	*merge(char *ln1, char *ln2);
int		nl_index(char *s);
char	*read_file(int fd);
char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);