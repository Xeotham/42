/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:32:36 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/11 21:28:50 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*ft_pipe_lstlast(t_pipex *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_pipe_lstadd_back(t_pipex **lst, t_pipex *new)
{
	t_pipex	*tmp;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = ft_pipe_lstlast(*lst);
		tmp->next = new;
	}
}

void	ft_pipe_lstclear(t_pipex **lst)
{
	t_pipex	*tmp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free_2d_array((*lst)->flags);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
