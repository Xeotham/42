/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nextline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:10:14 by mhaouas           #+#    #+#             */
/*   Updated: 2023/11/16 19:50:13 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_storage(char *storage)
{
	int	i;
	int	nb_to_line;
	char	*tmp;

	i = 0;
	nb_to_line = is_new_line(storage) + 1;
	while (storage[i + nb_to_line])
		i++;
	if (i == 0)
		return(NULL) ;
	tmp = malloc(sizeof(char) * (i + 1));
	tmp[i] = 0;
	i = 0;
	while(storage[i + nb_to_line])
	{
		tmp[i] = storage[i + nb_to_line];
		i++;
	}
	free(storage);
	return (tmp);
}

char	*dup_to_new_line(char *storage, char *buffer)
{
	int	i;
	int	nb_to_line;

	i = 0;
	nb_to_line = is_new_line(storage) + 1;
	buffer = malloc(sizeof(char) * (nb_to_line + 1));
	while (i < nb_to_line)
	{
		buffer[i] = storage[i];
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}
char	*gnl_loop(char *storage, int fd)
{
	char	*buffer;
	int	nb_char;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while(1)
	{
		nb_char = read(fd, buffer, BUFFER_SIZE);
		buffer[nb_char] = 0;
		if (nb_char == -1)
		{
			free(buffer);
			return (NULL);
		}
		storage = ft_strjoin(storage, buffer);
		if (is_new_line(storage) != -1 || nb_char < BUFFER_SIZE)
		{
			free(buffer);
			break;
		}
	}
	return (storage);
}
char	*get_next_line(int fd)
{
	static char *storage;
	char *buffer;

	buffer = 0;

	storage = gnl_loop(storage, fd);
	buffer = dup_to_new_line(storage, buffer);
	storage = new_storage(storage);
	if (!storage && buffer[0] == 0)
	{
		free(storage);
		return (NULL);
	}
	return (buffer);
}