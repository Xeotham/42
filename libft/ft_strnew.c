#include "libft.h"

char *  ft_strnew(size_t size)
{
    int i;
    char    *str;

    i = 0;
    str = malloc(sizeof(char) * size);
    while (i <= size - 1)
    {
        str[i] = 0;
    }
    if (str == NULL)
        return (NULL);
    return (str);
}