/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:21:20 by mhaouas           #+#    #+#             */
/*   Updated: 2023/11/13 14:37:50 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

static void	recurse(int nb, size_t *count)
{
	char	nb2;

	nb2 = 0;
	if (nb > 9)
	{
		recurse(nb / 10, count);
	}
	nb2 = (nb % 10) + '0';
	*count = *count + write(1, &nb2, 1);
}

int	ft_cputnbr(int nb)
{
	size_t	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		count += write(1, "-", 1);
	}
	recurse(nb, &count);
	return (count);
}

static void	urecurse(unsigned int nb, size_t *count)
{
	char	nb2;

	nb2 = 0;
	if (nb > 9)
	{
		urecurse(nb / 10, count);
	}
	nb2 = (nb % 10) + '0';
	*count = *count + write(1, &nb2, 1);
}

int	ft_cuputnbr(unsigned int nb)
{
	size_t	count;

	count = 0;
	urecurse(nb, &count);
	return (count);
}
