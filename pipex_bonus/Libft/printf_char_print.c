/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:15:58 by mhaouas           #+#    #+#             */
/*   Updated: 2023/11/30 16:39:26 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cputstr(char *str)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	if (!str)
		return ((count = write(1, "(null)", 6)));
	while (str[i])
	{
		count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}

int	ft_cputchar(char c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}
