/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_fork_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:19:41 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/13 17:35:37 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_input_check(int fd_input[2], t_pipex *pipe_struct, int fd_type)
{
	if (fd_type == READ_FD && fd_input[READ_FD] == -1)
	{
		ft_pipe_lstclear(&pipe_struct);
		error_handler(FD_INPUT_ERROR);
	}
	else if (fd_type == WRITE_FD && fd_input[WRITE_FD] == -1)
	{
		close(fd_input[READ_FD]);
		ft_pipe_lstclear(&pipe_struct);
		error_handler(FD_OUTPUT_ERROR);
	}
	return ;
}

void	pipe_fd_check(int which_fd, int fd_input[3][2], t_pipex *pipe_struct,
	char **envp)
{
	if (which_fd == 0)
	{
		free_2d_array(envp);
		close_all_fd(fd_input[FD_INPUT]);
		close_all_fd(fd_input[PIPE_FD_1]);
		ft_pipe_lstclear(&pipe_struct);
		error_handler(PIPE_FAILED);
	}
	else if (which_fd == 1)
	{
		free_2d_array(envp);
		close_all_fd(fd_input[FD_INPUT]);
		close_all_fd(fd_input[PIPE_FD_1]);
		close_all_fd(fd_input[PIPE_FD_2]);
		ft_pipe_lstclear(&pipe_struct);
		error_handler(PIPE_FAILED);
	}
}

void	fork_check(int pipe_fd[3][2], t_pipex *pipe_struct, char **envp)
{
	free_2d_array(envp);
	close_all_fd(pipe_fd[FD_INPUT]);
	close_all_fd(pipe_fd[PIPE_FD_1]);
	close_all_fd(pipe_fd[PIPE_FD_2]);
	ft_pipe_lstclear(&pipe_struct);
	error_handler(FORK_ERROR);
}

void	dup_error(char **envp, int fds[3][2])
{
	free_2d_array(envp);
	close_all_fd(fds[FD_INPUT]);
	close_all_fd(fds[PIPE_FD_1]);
	close_all_fd(fds[PIPE_FD_2]);
}
