/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:20:17 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/01 11:32:10 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_data
{
	int		fd_in;
	int		fd_out;
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	char	**cmd_paths;
	char	**cmd1_args;
	char	**cmd2_args;
}	t_data;

// MAIN
int		main(int argc, char **argv, char **env);
void	exec_child_1(t_data *data);
void	exec_child_2(t_data *data);

// PARSE DATA
void	error_handling(char **argv, t_data *data);
char	*get_cmd_path(char *cmd, t_data *data);
t_data	*parse_data(int argc, char **argv, char **envp);

// UTILS
void	free_tab(char **tab);
void	clean_exit(t_data *data, int success);
void	close_pipe(t_data *data);
void	put_error(char *msg, t_data *data);

# define ERR_MSG_ARGS "Error: Wrong arguments.\n\
Usage: ./pipex inputFile cmd1 cmd2 outputFile\n"
# define ERR_MSG_INFILE "Error: Could not open in File\n"
# define ERR_MSG_OUTFILE "Error: Could not open out File\n"
# define ERR_MSG_CMD "Error: Command not found\n"
# define ERR_MSG_FILE "Error: File does not exist\n"

#endif