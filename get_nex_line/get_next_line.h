/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:10:11 by mhaouas           #+#    #+#             */
/*   Updated: 2023/11/17 14:03:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*gnl_loop(char *storage, int fd);
int		is_new_line(char *buff);
char	*ft_strcat(char *s1, char *s2, char *array);
size_t	ft_strlen(const char *s);
char	*dup_to_new_line(char *storage);

#endif
