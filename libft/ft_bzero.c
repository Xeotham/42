#include "libft.h"

void    bzero(void *str, size_t size)
{
    void    *strtemp;
    
    strtemp = ft_memset(str, 0, size);
    return (strtemp);
}