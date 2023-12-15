/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:46:04 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/14 15:27:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*=========== LIBRARY ===========*/
# include "Libft/libft.h"
# include <sys/wait.h>

/*========== PIPE TYPE ==========*/
# define FD_INPUT 0
# define PIPE_FD_1 1
# define PIPE_FD_2 2

/*========= PIPE FD TYPE ========*/
# define READ_FD 0
# define WRITE_FD 1

/*============= COLOR ===========*/

# define RED "\033[31;1m"
# define RESET_COLOR "\033[0m"

/*========== ERROR CASE =========*/

enum e_error {
	ARGS_ERROR ,
	FIND_PATH_ERROR ,
	SPLIT_PATHE_ERROR ,
	LLIST_FAIL ,
	SPLIT_ERROR ,
	JOIN_ERROR ,
	FD_INPUT_ERROR ,
	FD_OUTPUT_ERROR ,
	PIPE_FAILED ,
	FORK_ERROR ,
	DUP_ERROR ,
	EXECVE_ERROR
} ;

/*============ STRUCT ===========*/
typedef struct s_pipex
{
	char			*command;
	char			**flags;
	int				cmd_number;
	int				total_number_of_cmd;
	pid_t			pid;
	struct s_pipex	*next;
}			t_pipex;

/*========== PROTOTYPE ==========*/

/******************************************************************************/
/* test_access() is a function that check which path is needed to execute     */
/* the linux command, and return the command precede by the correct path      */
/* to execute it.                                                             */
/******************************************************************************/
char		*test_access(char **ex_path, char *command);

/******************************************************************************/
/* get_func_path() is a function made to get the 'PATH' environnement         */
/* variable in order to test the function's access.                           */
/******************************************************************************/
char		**get_func_path(char **envp);

/******************************************************************************/
/* create_link_list() is made to create all the node for the link list.       */
/******************************************************************************/
t_pipex		*create_link_list(char **func_path, char **commands,
				int number_of_commands);

/******************************************************************************/
/* ft_pipe_lstclear() is a function that clear all the link list.             */
/******************************************************************************/
void		ft_pipe_lstclear(t_pipex **lst);

/******************************************************************************/
/* ft_pipe_lstadd_back is made to add a node at the end of a link list        */
/******************************************************************************/
void		ft_pipe_lstadd_back(t_pipex **lst, t_pipex *new);

/******************************************************************************/
/* ft_pipe_lstlast() is a fucntion that return the last node of a link list.  */
/******************************************************************************/
t_pipex		*ft_pipe_lstlast(t_pipex *lst);

/******************************************************************************/
/* get_flags() is a fucnction that take the flags of a command input.         */
/* ex: ./pipex infile "ls  -l -a"  "cat   -e"   oufile                        */
/*                    |cmd||flags| |cmd||flags|                               */
/******************************************************************************/
char		**get_flags(char *command, char *access);

/******************************************************************************/
/* free_2d_array() is made to free a malloc'd 2D array.                       */
/******************************************************************************/
void		free_2d_array(char **array);

/******************************************************************************/
/* parent_process() is the function that is executed when the fork is to      */
/* the parent process.                                                        */
/******************************************************************************/
void		parent_process(int fds[3][2], t_pipex *pipe_struct, char **envp,
			int pipe_number);

/******************************************************************************/
/* child_process() is the function that is executed when the fork is to       */
/* the child process.                                                         */
/******************************************************************************/
void		child_process(int fds[3][2], t_pipex *pipe_struct, char **envp,
			int pipe_number);

/******************************************************************************/
/* error_handler() is the function executed in case of error. It will print   */
/* an error message in the STDERR and exit with an error status.              */
/******************************************************************************/
void		error_handler(int error_case);

/******************************************************************************/
/* fd_input_check() check if the fd for infile and outfile are okay.          */
/* In case of error, the function free the link list and exit with an error.  */
/******************************************************************************/
void		fd_input_check(int fd_input[2], t_pipex *pipe_struct, int fd_type);

/******************************************************************************/
/* pipe_fd_check() check if the pipe's fd are okay.                           */
/* In case of error, the function free the link list, close the infile and    */
/*outfile fd and exit with an error.                                          */
/******************************************************************************/
void		pipe_fd_check(int which_fd, int fd_input[3][2],
				t_pipex *pipe_struct, char **envp);

void		fork_check(int pipe_fd[3][2], t_pipex *pipe_struct, char **envp);

void		close_all_fd(int fd[2]);

void		dup_error(char **envp, int fds[3][2]);

void	inter_process(int fds[3][2], int pipe_number, t_pipex *pipe_struct,
		char **envp);

#endif
