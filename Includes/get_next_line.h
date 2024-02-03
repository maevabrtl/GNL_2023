#ifndef GNL_H
# define GNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

char	*get_next_line(int fd);
void	strlcpy_gnl(char *dst, const char *src, size_t dstsize);
char	*join_to_nl(char *previous_line, char buf[BUFFER_SIZE + 1]);
char	*ft_free(char **s);
size_t	ft_strlen(const char *s);
int		ft_strchr_index(const char *s, int tofind);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
