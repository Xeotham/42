/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:10:08 by mhaouas           #+#    #+#             */
/*   Updated: 2023/11/20 11:03:42 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	is_new_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i])
	{
		i++;
	}
	if (buff[i] == '\n')
		return (i + 1);
	return (-1);
}

char	*ft_strcat(char *s1, char *s2, char *array)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		array[i + j] = s2[j];
		j++;
	}
	array[j + i] = '\0';
	return (array);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*array;
	int		len;

	if (!s2)
		return (NULL);
	if (!s1)
		array = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1));
	else
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		array = (char *)malloc(sizeof(char) * (len + 1));
	}
	if (!array)
		return (NULL);
	array = ft_strcat(s1, s2, array);
	free(s1);
	return (array);
}
