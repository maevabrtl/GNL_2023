#ifndef GNL_H
# define GNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);


#endif
