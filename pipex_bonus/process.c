/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:40:57 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/13 18:20:42 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int fds[3][2], t_pipex *pipe_struct, char **envp,
		int pipe_number)
{
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
	close(fds[pipe_number][READ_FD]);
	if (execve(pipe_struct->command, pipe_struct->flags, envp) == -1)
	{
		dup_error(envp, fds);
		error_handler(DUP_ERROR);
	}
}

void	parent_process(int fds[3][2], t_pipex *pipe_struct, char **envp,
		int pipe_number)
{
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
	close(fds[pipe_number][WRITE_FD]);
	if (execve(pipe_struct->command, pipe_struct->flags, envp) == -1)
	{
		dup_error(envp, fds);
		error_handler(DUP_ERROR);
	}
}

void	inter_process(int fds[3][2], int pipe_number, t_pipex *pipe_struct,
		char **envp)
{
	int	mirror_pipe;
	int	read_fd;
	int	write_fd;

	if (pipe_number == PIPE_FD_1)
		mirror_pipe = PIPE_FD_2;
	else
		mirror_pipe = PIPE_FD_1;
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
	close(fds[pipe_number][WRITE_FD]);
	close(fds[mirror_pipe][READ_FD]);
	if (execve(pipe_struct->command, pipe_struct->flags, envp) == -1)
	{
		dup_error(envp, fds);
		error_handler(DUP_ERROR);
	}
}
