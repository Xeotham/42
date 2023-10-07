#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>

void    *ft_memset (void *str1, int value, size_t num);
void    *ft_bzero(void *str, size_t num);
void    *ft_memcpy(void *dest, const void *src, size_t num);
char *  ft_strnew(size_t size);

#endif