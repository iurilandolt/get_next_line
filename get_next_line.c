/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:06:15 by rlandolt          #+#    #+#             */
/*   Updated: 2023/05/16 12:03:45 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	temp = ft_calloc(BUFFER_SIZE + 1, 1);
	rlen = read(fd, temp, BUFFER_SIZE);
	while (rlen > 0)
	{
		if (!buffer)
			buffer = ft_calloc(1, 1);
		*(temp + rlen) = '\0';
		buffer = ft_join(buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break ;
		rlen = read(fd, temp, BUFFER_SIZE);
	}
	free (temp);
	if (rlen < 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*ft_getline(char *buffer)
{
	char	*line;
	int		i;
	int		term;

	i = 0;
	term = 1;
	if (!*(buffer + i))
		return (NULL);
	while (*(buffer + i) && *(buffer + i) != '\n')
		i++;
	if (*(buffer + i) == '\n')
		term = 2;
	line = ft_calloc(i + term, 1);
	i = 0;
	while (*(buffer + i) && *(buffer + i) != '\n')
	{
		*(line + i) = *(buffer + i);
		i++;
	}
	if (*(buffer + i) && *(buffer + i) == '\n')
		*(line + i) = '\n';
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
		*(line + j++) = *(buffer + i++);
	free (buffer);
	*(line + j) = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	buffer = ft_getremain(buffer);
	return (line);
}
