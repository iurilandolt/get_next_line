/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:06:15 by rlandolt          #+#    #+#             */
/*   Updated: 2023/05/03 11:06:15 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	buffer[BUFF_SIZE];
	char 		*stash;
	size_t 		rlen;
	char		*p;
	int			i;

	if (fd <= 0 || BUFF_SIZE < 1)
		return (NULL);
	stash = ft_strdup("");
	if (!stash)
		return (NULL);
	rlen = read(fd, buffer, BUFF_SIZE);
	if (rlen > 0)
	{
		if (ft_strchr(buffer, '\n') == NULL)
		{
			read(fd, buffer, BUFF_SIZE);
			stash = ft_strjoin(stash, buffer);
		}
		else //if (ft_strchr(buffer, '\n') != NULL)
		{
			p = ft_strchr(buffer, '\n');
			i = (int)(p - buffer);
			stash = ft_strnjoin(stash, buffer, i);
		}
	}
	else if (rlen <= 0)
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
		printf("%s\n", line);
		free(line);
	}

	if (close(fd) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
