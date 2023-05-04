#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	pos;

	pos = 0;
	while (*s++)
		pos++;
	return (pos);
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

int main(void) {
    char *str1 = "Hello, ";
    char *str2 = "world!";
    char *result = ft_strnjoin(str1, str2, 3);
    printf("%s\n", result);  // expected output: Hello, wor
    free(result);  // free the dynamically allocated memory
    return 0;
}
