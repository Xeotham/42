#include "libft.h"

void    *ft_memset (void *str1, int value, size_t num)
{
    int i;
    char    *str2;
    
    str2 = (char *) str1;
    i = 0;
    while (i < num - 1)
    {
        str2[i] = value;
        i++;
    }
    return ((void *) str2);
}