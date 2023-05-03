/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:06:27 by rlandolt          #+#    #+#             */
/*   Updated: 2023/05/03 11:06:27 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFF_SIZE 5

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		line_size(char *str, int c);
char	*ft_strchr(const char *str, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strnjoin(char const *str1, char const *str2, int n);

#endif
