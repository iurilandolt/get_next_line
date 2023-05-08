/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:06:15 by rlandolt          #+#    #+#             */
/*   Updated: 2023/05/08 18:50:10 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buffer)
{
	char *temp;
	int rlen;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	temp = ft_calloc(BUFF_SIZE , 1);
	rlen = 1;
	while (rlen >= 1)
	{
		rlen = read(fd, temp, BUFF_SIZE);
		if (rlen == -1)
		{
			free(temp);
			return (NULL);
		}
		*(temp + rlen + 1) = '\0';
		buffer =  ft_strjoin(buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(temp);
	return (buffer);
}

char	*ft_getline(char *buffer)
{
	char	*line;
	int	i;

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
	char	*line;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	buffer = ft_getremain(buffer);
	//printf("/n%d\n", fd);
	return (line);
}

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

	while ((line = get_next_line(fd)))
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
	/*
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	*/
