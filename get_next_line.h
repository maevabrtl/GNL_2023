#ifndef GNL_H
# define GNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		clear_buf(char *buf);
char	*join_to_nl(char *previous_line, char buf[BUFFER_SIZE + 1]);
int		get_len_to_malloc(char buf[BUFFER_SIZE + 1], char *previous_line);
char	*ft_free(char **s);
size_t	ft_strlen(const char *s);
int		ft_strchr_index(const char *s, int tofind);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
