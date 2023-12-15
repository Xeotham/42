/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:06:08 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/15 17:26:16 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	chain_process(int pipe_needed, int pipe_fd[3][2], t_pipex *pipe_struct,
		char **envp)
{
	int		mirror_pipe;

	if (pipe_needed == PIPE_FD_1)
		mirror_pipe = PIPE_FD_2;
	else
		mirror_pipe = PIPE_FD_1;
	pipe_struct->pid = fork() - pipe_struct->cmd_number;
	if (pipe_struct->pid == -1)
		fork_check(pipe_fd, pipe_struct, envp);
	if (pipe_struct->cmd_number < pipe_struct->total_number_of_cmd)
	{
		if (pipe_struct->pid == 0)
		{
			if (pipe_needed == PIPE_FD_1)
				inter_process(pipe_fd, PIPE_FD_1, pipe_struct, envp);
			else if (pipe_needed == PIPE_FD_2)
				inter_process(pipe_fd, PIPE_FD_2, pipe_struct, envp);
		}
		else
		{
			chain_process(mirror_pipe, pipe_fd, pipe_struct->next, envp);
			wait(NULL);
		}
	}
	else if (pipe_struct->cmd_number == pipe_struct->total_number_of_cmd)
	{
		if (pipe_struct->pid == 0)
			parent_process(pipe_fd, pipe_struct, envp, pipe_needed);
		else
		{
			wait(NULL);
		}
	}
}

void	next_process(int pipe_fd[3][2], t_pipex *pipe_struct, char **envp)
{
	if (pipe_struct->total_number_of_cmd == 2)
	{
		pipe_struct->pid = fork();
		if (pipe_struct->pid == -1)
			fork_check(pipe_fd, pipe_struct, envp);
		if (pipe_struct->pid == 0)
			parent_process(pipe_fd, pipe_struct, envp, PIPE_FD_1);
		else
			wait(NULL);
	}
	else if (pipe_struct->total_number_of_cmd != 2)
	{
		if (pipe(pipe_fd[PIPE_FD_2]) == -1)
			pipe_fd_check(1, pipe_fd, pipe_struct, envp);
		chain_process(PIPE_FD_1, pipe_fd, pipe_struct, envp);
		close_all_fd(pipe_fd[FD_INPUT]);
		close_all_fd(pipe_fd[PIPE_FD_1]);
		close_all_fd(pipe_fd[PIPE_FD_2]);
	}
}

void	pipex(int argc, char **argv, char **envp, t_pipex *pipe_struct)
{
	int		pipe_fd[3][2];

	pipe_fd[FD_INPUT][READ_FD] = open(argv[0], O_RDONLY);
	if (pipe_fd[FD_INPUT][READ_FD] == -1)
		fd_input_check(pipe_fd[FD_INPUT], pipe_struct, READ_FD);
	pipe_fd[FD_INPUT][WRITE_FD] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe_fd[FD_INPUT][WRITE_FD] == -1)
		fd_input_check(pipe_fd[FD_INPUT], pipe_struct, WRITE_FD);
	if (pipe(pipe_fd[PIPE_FD_1]) == -1)
		pipe_fd_check(0, pipe_fd, pipe_struct, envp);
	pipe_struct->pid = fork();
	if (pipe_struct->pid == -1)
		fork_check(pipe_fd, pipe_struct, envp);
	else if (pipe_struct->pid == 0)
		child_process(pipe_fd, pipe_struct, envp, PIPE_FD_1);
	else
	{
		pipe_struct->next->pid = pipe_struct->pid;
		next_process(pipe_fd, pipe_struct->next, envp);
		//printf("waiting process %d\n", pipe_struct->cmd_number);
		waitpid(pipe_struct->pid - - pipe_struct->cmd_number, NULL, 0);
	}

}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_pipex	*pipe_struct;
	char	**func_path;

	i = 0;
	if (argc < 5)
		error_handler(ARGS_ERROR);
	func_path = get_func_path(envp);
	pipe_struct = create_link_list(func_path, argv + 2, argc - 3);
	free_2d_array(func_path);
	pipex(argc - 1, argv + 1, envp, pipe_struct);
	ft_pipe_lstclear(&pipe_struct);
	return (0);
}
