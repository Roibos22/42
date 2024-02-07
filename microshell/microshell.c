/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <leon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 04:52:40 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/08 00:10:59 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define CD_ARGS_ERR "error: cd: bad arguments"
#define CD_PATH_ERR "error: cd: cannot change directory to path_to_change"
#define EXEC_ERR "error: cannot execute executable_that_failed"

/*not needed in exam, but necessary if you want to use this tester:
https://github.com/Glagan/42-exam-rank-04/blob/master/microshell/test.sh*/
#ifdef TEST_SH
# define TEST		1
#else
# define TEST		0
#endif

void	print_error(char *msg)
{
	while (*msg)
	{
		write (2, msg, 1);
		msg++;
	}
	write (2, "\n", 1);
}

int	execute_cd(int argc, char *path)
{
	if (argc != 2)
		print_error(CD_ARGS_ERR);
	if (chdir(path) != 0)
		print_error(CD_PATH_ERR);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	// Error Handling
	int	i = 0;
	int	fd_in = dup(STDIN_FILENO);
	int	pipe_fds[2];
	
	if (argc == 0)
		return (0);
	while (argv[i] && argv[i + 1])
	{
		// prepare argv[0] for next statement
		argv = &argv[i + 1];
		i = 0;

		// count elements of statment
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;

		// execute
		if (strcmp(argv[0], "cd") == 0)
			execute_cd(i, argv[1]);
		else if (i != 0)
		{
			pipe(pipe_fds);

			if (argv[i] == NULL)
				pipe_fds[1] = STDOUT_FILENO;

			if (fork() == 0)
			{
			// Child
				argv[i] = NULL;
				// SET FD_OUT
				if (pipe_fds[1] != STDOUT_FILENO)
				{
					dup2(pipe_fds[1], STDOUT_FILENO);
					close(pipe_fds[1]);
				}
				// SET FD_IN
				if (fd_in != STDIN_FILENO)
				{
					dup2(fd_in, STDIN_FILENO);
					close(fd_in);
				}

				execve(argv[0], argv, env); // execute
				print_error(EXEC_ERR); // if execve fails print error & exit
				exit(1);
			}
			else
			{
				close(pipe_fds[0]);
				close(pipe_fds[1]);
				// reset fd's
				//dup2(pipe_fds[1], STDOUT_FILENO);
				//fd_in = pipe_fds[1];
			}
			
		}
	}
	close(fd_in);
	if (TEST)		// not needed in exam, but necessary if you want to use this tester:
		while (1);
}

/*
			pipe(pipe_fds);
			if (fork() == 0)
			{
				// Child
				dup2(fd[1], STDOUT_FILENO); // dup write end of pipe int stdout
				close(fd[0]); // close pipe
				close(fd[1]); // close pipe

				argv[i] = NULL; // set terminator to NULL
				dup2(fd_in, STDIN_FILENO); // dup fd_oin into stdin
				close(fd_in);	// clsoe fd_in
				execve(argv[0], argv, env); // execute
				print_error(EXEC_ERR); // if execve fails print error & exit
				exit(1);
			}
			else
			{
				// Parent
				dup2(fd[1], fd_in); // dup write end into fd_in of next statement
				close(fd[1]);
				
			}
*/