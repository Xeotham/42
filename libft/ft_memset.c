#include "libft.h"

void    *ft_memset (void *str, int value, size_t num)
{
    int i;
    
    i = 0;
    while (i < num - 1)
    {
        str[i] = value;
        i++;
    }
    return ((void *) str2);
}