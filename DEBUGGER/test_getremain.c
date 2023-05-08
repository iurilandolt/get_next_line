
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	pos;

	pos = 0;
	while (*s++)
		pos++;
	return (pos);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		*((char *)str + i) = c;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*mblock;

	mblock = (void *)malloc(size * nitems);
	if (!mblock)
		return (NULL);
	ft_memset(mblock, 0, size * nitems);
	return (mblock);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*dest;
	size_t	len;
	int		i;
	int		j;

	if (!str1 || !str2)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = -1;
	j = 0;
	while (str1[++i])
		dest[i] = str1[i];
	while (str2[j])
		dest[i++] = str2[j++];
	*(dest + i) = '\0';
	return (dest);
}

/* ###################################################################### */

char	*ft_getremain(char *buffer)
{
	char *line;
	int i;
	int j;

	i = 0;
	while (*(buffer + i) && *(buffer + i) != '\n')
		i++;
	if (!*(buffer + i))
	{
		free (buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (*(buffer + i))
	{
		*(line + j) = *(buffer + i);
		i++;
		j++;
	}
	free (buffer);
	*(line + j + 1) = '\0';
	return (line);
}

int	main(void)
{
	char	*buffer = strdup("first line\nlast line\n");
	char	*remain = ft_getremain(buffer);

	printf("Remaining text: %s", remain);

	free(remain);
	return (0);
}
