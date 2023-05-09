#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 10

/*########## UTILS ##########*/

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

/*########## GNL ##########*/

char	*ft_join(char *buff1, char *buff2)
{
	char	*temp;

	temp = ft_strjoin(buff1, buff2);
	free(buff1);
	return (temp);
}

char	*ft_read(int fd, char *buffer)
{
	char	*temp;
	int		rlen;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	temp = ft_calloc(BUFF_SIZE + 1, 1);
	rlen = 1;
	while (rlen >= 1)
	{
		rlen = read(fd, temp, BUFF_SIZE);
		if (rlen == -1)
		{
			free(temp);
			return (NULL);
		}
		*(temp + rlen) = '\0';
		buffer = ft_join(buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (temp);
	return (buffer);
}

char	*ft_getline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!*(buffer + i))
		return (NULL);
	while (*(buffer + i) && *(buffer + i) != '\n')
		i++;
	line = ft_calloc(i + 2, 1);
	i = 0;
	while (*(buffer + i) && *(buffer + i) != '\n')
	{
		*(line + i) = *(buffer + i);
		i++;
	}
	if (*(buffer + i) && *(buffer + i) == '\n')
		*(line + i) = '\n';
	*(line + i + 1) = '\0';
	return (line);
}

char	*ft_getremain(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (*(buffer + i) && *(buffer + i) != '\n')
		i++;
	if (!*(buffer + i))
	{
		free (buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), 1);
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

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	buffer = ft_getremain(buffer);
	return (line);
}

/*########## MAIN ##########*/
/*cc debug.c -fsanitize=leak  cc debug.c -fsanitize=adress */

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("testfile.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	if (close(fd) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
