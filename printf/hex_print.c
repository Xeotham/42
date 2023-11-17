/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:50:53 by mhaouas           #+#    #+#             */
/*   Updated: 2023/11/13 14:37:56 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	urecurse(unsigned int nb, size_t *count, char type)
{
	if (nb > 15)
		urecurse(nb / 16, count, type);
	else if (nb == 0)
		return ;
	if (type == 'x')
		*count = *count + write(1, &"0123456789abcdef"[nb % 16], 1);
	else if (type == 'X')
		*count = *count + write(1, &"0123456789ABCDEF"[nb % 16], 1);
}

int	ft_convert_to_hex(unsigned int nb, char type)
{
	size_t	count;

	count = 0;
	if (nb == 0)
		count += write(1, "0", 1);
	else
		urecurse(nb, &count, type);
	return (count);
}

static void	precurse(unsigned long long nb, size_t *count)
{
	if (nb > 15)
		precurse(nb / 16, count);
	else if (nb == 0)
		return ;
	*count = *count + write(1, &"0123456789abcdef"[nb % 16], 1);
}

int	ft_point_to_hex(unsigned long long nb)
{
	size_t	count;

	count = 0;
	count += write(1, "0x", 2);
	if (nb == 0)
		count += write(1, "0", 1);
	else
		precurse(nb, &count);
	return (count);
}
