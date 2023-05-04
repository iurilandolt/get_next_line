/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:06:06 by rlandolt          #+#    #+#             */
/*   Updated: 2023/05/04 01:54:30 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*mblock;

	mblock = (void *)malloc(size * nitems);
	if (!mblock)
		return (NULL);
	ft_memset(mblock, 0, size * nitems);
	return (mblock);
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

char	*ft_strnjoin(char const *str1, char const *str2, int n)
{
	char	*dest;
	size_t	len;
	int		i;
	int		j;

	if (!str1 || !str2)
		return (NULL);
	len = ft_strlen(str1) + n;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
	{
		dest[i] = str1[i];
		i++;
	}
	while (str2[j] && n > 0)
	{
		dest[i] = str2[j];
		i++;
		j++;
		n--;
	}
	*(dest + i) = '\0';
	return (dest);
}
