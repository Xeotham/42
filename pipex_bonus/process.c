/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:40:57 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/15 17:24:38 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	child_process(int fds[3][2], t_pipex *pipe_struct, char **envp,
		int pipe_number)
{
	printf("_Child ->    - Command : %s    - Command Number :%d    - Pipe Read :%d    - Pipe Write :%d\n",pipe_struct->command, pipe_struct->cmd_number, fds[FD_INPUT][READ_FD], fds[pipe_number][WRITE_FD]);
	if (dup2(fds[FD_INPUT][READ_FD], STDIN_FILENO) == -1)
	{
		dup_error(envp, fds);
		error_handler(DUP_ERROR);
	}
	if (dup2(fds[pipe_number][WRITE_FD], STDOUT_FILENO) == -1)
	{
		dup_error(envp, fds);
		error_handler(DUP_ERROR);
	}
	close_all_fd(fds[pipe_number]);
	close_all_fd(fds[FD_INPUT]);
	if (execve(pipe_struct->command, pipe_struct->flags, envp) == -1)
	{
		dup_error(envp, fds);
		error_handler(DUP_ERROR);
	}
}

void	parent_process(int fds[3][2], t_pipex *pipe_struct, char **envp,
		int pipe_number)
{
	int	mirror_pipe;

	if (pipe_number == PIPE_FD_1)
		mirror_pipe = PIPE_FD_2;
	else
		mirror_pipe = PIPE_FD_1;
	printf("_Parent ->    - Command : %s    - Command Number :%d    - Pipe Read :%d    - Pipe Write :%d\n",pipe_struct->command, pipe_struct->cmd_number, fds[pipe_number][READ_FD], fds[FD_INPUT][WRITE_FD]);
	if (dup2(fds[pipe_number][READ_FD], STDIN_FILENO) == -1)
	{
		dup_error(envp, fds);
		error_handler(DUP_ERROR);
	}
	if (dup2(fds[FD_INPUT][WRITE_FD], STDOUT_FILENO) == -1)
	{
		dup_error(envp, fds);
		error_handler(DUP_ERROR);
	}
	close_all_fd(fds[pipe_number]);
	close_all_fd(fds[FD_INPUT]);
	if (execve(pipe_struct->command, pipe_struct->flags, envp) == -1)
	{
		dup_error(envp, fds);
		error_handler(EXECVE_ERROR);
	}
}

void	inter_process(int fds[3][2], int pipe_number, t_pipex *pipe_struct,
		char **envp)
{
	int	mirror_pipe;

	if (pipe_number == PIPE_FD_1)
		mirror_pipe = PIPE_FD_2;
	else
		mirror_pipe = PIPE_FD_1;
	printf("_Inter ->    - Command : %s    - Command Number :%d    - Pipe Read :%d    - Pipe Write :%d\n",pipe_struct->command, pipe_struct->cmd_number, fds[pipe_number][READ_FD], fds[mirror_pipe][WRITE_FD]);
	if (dup2(fds[pipe_number][READ_FD], STDIN_FILENO) == -1)
	{
		dup_error(envp, fds);
		error_handler(DUP_ERROR);
	}
	if (dup2(fds[mirror_pipe][WRITE_FD], STDOUT_FILENO) == -1)
	{
		dup_error(envp, fds);
		error_handler(DUP_ERROR);
	}
	close_all_fd(fds[pipe_number]);
	close_all_fd(fds[mirror_pipe]);
	close_all_fd(fds[FD_INPUT]);
	if (execve(pipe_struct->command, pipe_struct->flags, envp) == -1)
	{
		dup_error(envp, fds);
		error_handler(EXECVE_ERROR);
	}
}
