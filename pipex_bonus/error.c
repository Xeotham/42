/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:15:44 by mhaouas           #+#    #+#             */
/*   Updated: 2023/12/13 14:25:02 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handler(int error_case)
{
	char	*error_message[12];

	error_message[ARGS_ERROR] = "ERROR : Too few or too much arguments.";
	error_message[FIND_PATH_ERROR] = "ERROR : No 'PATH' environement variable.";
	error_message[SPLIT_ERROR] = "ERROR : Error when spliting the 'PATH' \
environement variable.";
	error_message[LLIST_FAIL] = "ERROR : Failed to creat link list.";
	error_message[SPLIT_ERROR] = "ERROR : Failed to execute the ft_split() \
function.";
	error_message[JOIN_ERROR] = "ERROR : Failed to execute the ft_strjoin() \
function.";
	error_message[FD_INPUT_ERROR] = "ERROR : Failed to open input file.";
	error_message[FD_OUTPUT_ERROR] = "ERROR : Failed to open output file.";
	error_message[PIPE_FAILED] = "ERROR : Failed to make a pipe with the \
pipe() function.";
	error_message[FORK_ERROR] = "ERROR : Failed to fork the code with the \
fork() function.";
	error_message[DUP_ERROR] = "ERROR : Failed to execute the dup2() function.";
	error_message[EXECVE_ERROR] = "ERROR : Failed to execute one of the input \
function.";
	ft_printf("%s%s%s\n", RED, error_message[error_case], RESET_COLOR);
	exit(EXIT_FAILURE);
}
