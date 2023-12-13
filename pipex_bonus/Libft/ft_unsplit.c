/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:57:32 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/04 15:03:39 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_join(char *str, char *str2)
{
	char	*tmp;

	tmp = ft_strjoin(str, str2);
	free(str);
	return (tmp);
}

char	*ft_unsplit(char **tab_to_unsplit, char *sep)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!tab_to_unsplit || !sep || !*tab_to_unsplit)
		return (NULL);
	tmp = ft_strdup(tab_to_unsplit[i]);
	while (tab_to_unsplit[++i])
	{
		tmp = free_join(tmp, sep);
		tmp = free_join(tmp, tab_to_unsplit[i]);
	}
	return (tmp);
}
