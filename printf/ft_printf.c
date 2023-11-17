/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:35:02 by mhaouas           #+#    #+#             */
/*   Updated: 2023/11/15 11:29:09 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	type_check(char var, va_list var_print)
{
	size_t	count;
	void	*test;

	count = 0;
	if (var == 'c')
		count += ft_cputchar(va_arg(var_print, int));
	else if (var == 's')
		count += ft_cputstr(va_arg(var_print, char *));
	else if (var == 'd' || var == 'i')
		count += ft_cputnbr(va_arg(var_print, int));
	else if (var == 'u')
		count += ft_cuputnbr(va_arg(var_print, unsigned int));
	else if (var == 'x' || var == 'X')
		count += ft_convert_to_hex(va_arg(var_print, unsigned int), var);
	else if (var == 'p')
	{
		test = va_arg(var_print, void *);
		if (!test)
			count += write(1, "(nil)", 5);
		else
			count += ft_point_to_hex((unsigned long long)test);
	}
	else if (var == '%')
		count += write(1, "%", 1);
	return (count);
}

int	is_ok(char c)
{
	if (c == 'c' || c == 's'
		|| c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X'
		|| c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	var_print;
	int		i;
	size_t	count;

	va_start(var_print, str);
	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && is_ok(str[i + 1]) == 1)
		{
			count += type_check(str[i + 1], var_print);
			i += 2;
		}
		else
		{
			count += write(1, &str[i], 1);
			i++;
		}
	}
	va_end(var_print);
	return (count);
}
