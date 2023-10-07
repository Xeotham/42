#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t num)
{
    int i;
    char *desttmp;
    char *srctmp;

    desttmp = (char *) dest;
    srctmp = (char *) src;

    i = 0;
    while (i < num)
    {
        desttmp[i] = srctmp[i];
        i++;
    }
}

#include <stdio.h>

int main(void)
{
    char *src = "test1";
    char *dest = "aaaaa";

    ft_memcpy(&dest, &src, 4);
    printf("%s", dest);
}