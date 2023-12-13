/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:20:51 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/13 16:02:44 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*creat_and_format_node(char **func_path, char *command, int cmd_number,
		int number_of_commands)
{
	t_pipex	*node;

	node = malloc(sizeof(t_pipex));
	if (!node)
		return (NULL);
	node->command = test_access(func_path, command);
	if (!node->command)
	{
		free(node);
		return (NULL);
	}
	node->flags = get_flags(command, node->command);
	if (!node->flags || !node->flags[0])
	{
		free(node->command);
		free(node);
		return (NULL);
	}
	node->cmd_number = cmd_number + 1;
	node->total_number_of_cmd = number_of_commands;
	node->next = NULL;
	return (node);
}

t_pipex	*create_link_list(char **func_path, char **commands,
		int number_of_commands)
{
	t_pipex	*first_node;
	t_pipex	*actual_node;
	int		i;

	i = 1;
	first_node = creat_and_format_node(func_path, commands[0], 0,
			number_of_commands);
	if (!first_node)
		error_handler(LLIST_FAIL);
	while (i < number_of_commands)
	{
		actual_node = creat_and_format_node(func_path, commands[i], i,
				number_of_commands);
		if (!actual_node)
		{
			ft_pipe_lstclear(&first_node);
			error_handler(LLIST_FAIL);
		}
		ft_pipe_lstadd_back(&first_node, actual_node);
		i++;
	}
	return (first_node);
}
