#include "get_next_line_bonus.h"

int	get_len_to_malloc(char buf[BUFFER_SIZE + 1], char *previous_line)
{
	int	index_newline;

	index_newline = ft_strchr_index(buf, '\n');
	if (index_newline == -1)
		index_newline = ft_strlen(buf);
	else
		index_newline++;
	return(ft_strlen(previous_line) + index_newline + 1);
}

char	*join_to_nl(char *previous_line, char buf[BUFFER_SIZE + 1])
{
	char	*new;
	int		i;
	int		j;

	new = malloc(sizeof(char) * get_len_to_malloc(buf, previous_line));
	if (new == NULL)
		return (ft_free(&previous_line));
	i = 0;
	j = 0;
	while (previous_line && previous_line[i])
		new[j++] = previous_line[i++];
	i = 0;
	while (buf[i] && buf[i] != '\n')
		new[j++] = buf[i++];
	if (buf[i] == '\n')
		new[j++] = buf[i++];
	new[j] = '\0';
	ft_free(&previous_line);
	return (new);
}

int	clear_buf(char *buf)
{
	size_t	i;
	int		index_newline;
	char	*tocopy;

	i = 0;
	index_newline = ft_strchr_index(buf, '\n');
	tocopy = &buf[index_newline + 1];
	if (index_newline != -1)
	{
		while (tocopy[i] && i < BUFFER_SIZE)
		{
			buf[i] = tocopy[i];
			i++;
		}
		while (i <= BUFFER_SIZE)
			buf[i++] = '\0';
	}
	else
		ft_bzero(buf, BUFFER_SIZE + 1);

	return (index_newline);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			nb_read;

	if (fd == -1 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	line = NULL;
	nb_read = 1;
	while (nb_read > 0)
	{
		if (buf[fd][0] != '\0')
		{
			line = join_to_nl(line, buf[fd]);
			if (line == NULL)
				return (NULL);
			if (clear_buf(buf[fd]) != -1)
				break ;
		}
		nb_read = read(fd, buf[fd], BUFFER_SIZE);
		if (nb_read == -1)
			return (ft_free(&line));
	}
	return (line);
}
