#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t num)
{
    int i;

    i = 0;
    while (i <= num - 1)
    {
        dest[i] = src[i];
        i++;
    }
    return(dest);
}