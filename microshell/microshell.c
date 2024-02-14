/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 04:52:40 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/08 19:27:15 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

#define CD_ARGS_ERR "error: cd: bad arguments"
#define CD_PATH_ERR "error: cd: cannot change directory to path_to_change"
#define EXEC_ERR "error: cannot execute executable_that_failed"

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

		//printf("%s, %i\n", argv[i], i);

		// execute
		if (strcmp(argv[0], "cd") == 0)
			execute_cd(i, argv[1]);
		else if (i != 0 && argv[i] != NULL && strcmp(argv[i], "|") == 0)
		{
			pipe(pipe_fds);

			if (fork() == 0)
			{
			// Child
				argv[i] = NULL;
				// SET FD_OUT
				dup2(pipe_fds[1], STDOUT_FILENO);
				close(pipe_fds[1]);
				close(pipe_fds[0]);
				dup2(fd_in, STDIN_FILENO);
				close(fd_in);
				execve(argv[0], argv, env); // execute
				print_error(EXEC_ERR); // if execve fails print error & exit
				exit(1);
			}
			else
			{
				//close(fd_in);
				close(pipe_fds[1]);
				fd_in = pipe_fds[0];
			}
		}
		else if (i != 0)
		{
			if (fork() == 0)
			{
				argv[i] = NULL;
				dup2(fd_in, STDIN_FILENO);
				close(fd_in);
				execve(argv[0], argv, env); // execute
				print_error(EXEC_ERR); // if execve fails print error & exit
				exit(1);
			}
			else
			{
				//close(fd_in);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
					;
				fd_in = dup(STDIN_FILENO);
			}
		}
	}

/* 	int fd1 = open("1", O_CREAT);
	int fd2 = open("2", O_CREAT);
	int fd3 = open("3", O_CREAT);

	//close(fd_in);
	if (1)		// not needed in exam, but necessary if you want to use this tester:
		while (1); */
}