#include "get_next_line.h"

char	*ft_free(char **s)
{
	if (*s != NULL)
		free(*s);
	*s = NULL;
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_strchr_index(const char *s, int tofind)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != (char)tofind && s[i])
		i++;
	if (s[i] == (char)tofind)
		return (i);
	return (-1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}
