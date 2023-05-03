#include "get_next_stash.h"
/*aux*/
size_t	ft_strlen(const char *s)
{
	size_t	pos;

	pos = 0;
	while (*s++)
		pos++;
	return (pos);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		*((char *)dest + i) = *((const char *)src + i);
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(str) + 1;
	dest = (char *)malloc(sizeof(char) * size);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, str, size);
	return (dest);
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
/*gnl*/
char	*get_next_stash(int fd)
{
	static char	buffer[BUFF_SIZE];
	char *stash;
	size_t rlen;

	if (fd <= 0 || BUFF_SIZE < 1)
		return (NULL);
	stash = ft_strdup(buffer);
	if (*stash = '\n') /*need function for this check?*/
		return (stash);
	rlen = read(fd, buffer, BUFF_SIZE);
	while (rlen > 0)
	{
		stash = ft_strjoin(stash, buffer);
		rlen = read(fd, buffer, BUFF_SIZE);
	}
	if (rd_len <= 0)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}
