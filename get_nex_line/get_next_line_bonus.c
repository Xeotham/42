/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:10:14 by mhaouas           #+#    #+#             */
/*   Updated: 2023/11/20 13:26:27 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_storage(char *storage)
{
	int		i;
	int		nb_to_line;
	char	*tmp;

	i = 0;
	if (!storage)
		return (NULL);
	nb_to_line = is_new_line(storage);
	if (nb_to_line == -1)
	{
		free(storage);
		return (NULL);
	}
	while (storage[i + nb_to_line])
		i++;
	if (i == 0)
	{
		free(storage);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (i + 1));
	tmp = ft_strcat("", storage + nb_to_line, tmp);
	free(storage);
	return (tmp);
}

char	*dup_to_new_line(char *storage)
{
	int		i;
	int		nb_to_line;
	char	*buffer;

	if (!storage)
		return (NULL);
	i = 0;
	if (is_new_line(storage) == -1)
		nb_to_line = ft_strlen(storage);
	else
		nb_to_line = is_new_line(storage);
	buffer = malloc(sizeof(char) * (nb_to_line + 1));
	if (!buffer)
		return (NULL);
	while (i < nb_to_line)
	{
		buffer[i] = storage[i];
		i++;
	}
	buffer[nb_to_line] = 0;
	return (buffer);
}

char	*gnl_loop(char *storage, int fd)
{
	char	*buffer;
	int		nb_char;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1)
	{
		nb_char = read(fd, buffer, BUFFER_SIZE);
		if (nb_char == -1 || (nb_char == 0 && !storage))
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb_char] = 0;
		storage = ft_strjoin(storage, buffer);
		if (is_new_line(storage) != -1 || nb_char < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*buffer;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = gnl_loop(storage[fd], fd);
	buffer = dup_to_new_line(storage[fd]);
	storage[fd] = new_storage(storage[fd]);
	if (!storage[fd] && !buffer)
		free(storage[fd]);
	return (buffer);
}
