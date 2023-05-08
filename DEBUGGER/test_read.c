
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

#define BUFF_SIZE 4

char	*read_file(int fd, char *buffer)
{
	char *temp;
	int rlen;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	temp = ft_calloc(BUFF_SIZE, 1);
	rlen = 1;
	while (rlen > 0)
	{
		rlen = read(fd, temp, BUFF_SIZE);
		if (rlen == -1)
		{
			free(temp);
			return (NULL);
		}
		*(temp + rlen) = '\0';
		buffer =  ft_strjoin(buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(temp);
	return (buffer);
}

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("testfile.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		exit(1);
	}

	buffer = read_file(fd, NULL);
	close(fd);

	if (buffer == NULL)
	{
		perror("Failed to read file");
		exit(1);
	}

	printf("%s", buffer);
	free(buffer);

	return (0);
}
