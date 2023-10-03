#include "libft.h"

void    *ft_bzero(void *str, size_t num)
{
    void    *strtemp;
    
    strtemp = ft_memset(str, 0, num);
    return (strtemp);
}