/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:59:50 by mhaouas           #+#    #+#             */
/*   Updated: 2023/10/31 09:42:22 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t num)
{
	unsigned char	*str2;
	size_t			i;

	str2 = (unsigned char *)str;
	i = 0;
	while (i < num)
	{
		str2[i] = value;
		i++;
	}
	return (str);
}
