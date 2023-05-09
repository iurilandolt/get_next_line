#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	pos;

	pos = 0;
	while (*s++)
		pos++;
	return (pos);
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

int	main(void)
{
	char *str1 = "Hello, ";
	char *str2 = "world!";
	char *result;

	result = ft_strjoin(str1, str2);
	if (result)
	{
		printf("The concatenated string: %s\n", result);
		free(result);
	}
	else
		printf("Error: ft_strjoin returned NULL\n");

	return (0);
}
