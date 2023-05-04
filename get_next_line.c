/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:06:15 by rlandolt          #+#    #+#             */
/*   Updated: 2023/05/04 19:03:42 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	end_line(char *str, int c)
{
	int	i;

	i = 0;
	while(*str)
	{
		if (*str == c)
			return (i);
		i++;
		str++;
	}
	return (-1);

}

char	*get_next_line(int fd)
{
	static char	buffer[BUFF_SIZE];
	char 		*stash;
	size_t 		rlen;
	//char		*p;
	int n;

	if (fd <= 0 || BUFF_SIZE < 1)
		return (NULL);
	stash = ft_calloc(1, 1);
	if (!stash)
		return (NULL);
	rlen = read(fd, buffer, BUFF_SIZE);
	//p = ft_strchr(buffer, '\n');
	while (rlen > 0)
	{
		if (ft_strchr(buffer, '\n') == NULL)
			stash = ft_strjoin(stash, buffer);
		else //if (ft_strchr(buffer, '\n') != NULL)
		{
			//stash = ft_strnjoin(stash, buffer, (int)(p - buffer));
			n = end_line(buffer, '\n');
			//printf("%d", n);
			stash = ft_strnjoin(stash, buffer, n);
			//stash = ft_strjoin(stash, buffer);
			break;
		}
		rlen = read(fd, buffer, BUFF_SIZE);
	}
	if (rlen <= 0)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
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
