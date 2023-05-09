#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int	main()
{
    char *ptr = (char *)ft_calloc(10, sizeof(char));
    if (!ptr)
    {
        printf("Memory allocation failed!\n");
        return (1);
    }

    printf("Allocated memory: %s\n", ptr);

    ft_memset(ptr, 'A', 10);

    printf("After memset: %s\n", ptr);

    free(ptr);

    return (0);
}
