/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:16:14 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/16 13:04:48 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_received_signal = 0;

/**
 * Starts and initialises the program before entering a loop 
 * in ft_minishell where each line entered is handled seperately
*/
int	main(int ac, char **argv, char **env)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	init_data(data, env);
	if (ac == 1 && argv)
		ft_minihell(data);
	else
		printf("./minishell doesn't accept arguments!\n");
	return (0);
}

/**
 * The main loop of the program where the functions are called to
 * interpret, execute and clean the line
*/
void	ft_minihell(t_data *data)
{
	while (1)
	{
		copy_env_paths(data);
		ft_signals(1, data);
		data->line = readline("minishell~$> ");
		if (!data->line)
			ft_signals(3, data);
		if (ft_lexer(data))
		{
			ft_prepare_data(data);
			ft_executor(data->tokens, STDIN_FILENO, data);
			ft_reset_data(data);
		}
		ft_free_str_arr(data->cmd_paths);
		data->cmd_paths = NULL;
		ft_clean_data(data, 0);
	}
	rl_clear_history();
}

void	init_data(t_data *data, char **env)
{
	int	i;

	i = 0;
	data->orig_std_in = dup(STDIN_FILENO);
	data->orig_std_out = dup(STDOUT_FILENO);
	data->env = ft_copy_array(env);
	data->exit_status = 0;
	data->exit_status_final = 0;
	data->tokens = NULL;
	data->created_files = NULL;
	data->tok_is_red_str = NULL;
}

void	ft_prepare_data(t_data *data)
{
	data->exit_status = 0;
	data->stm_count = 0;
	data->created_files = malloc (sizeof(char *) * 1);
	data->created_files[0] = NULL;
}

/**
 * Next to resetting the data struct, the final exit
 * status and adding to readline history are handled
*/
void	ft_reset_data(t_data *data)
{
	if (g_received_signal)
	{
		data->exit_status = g_received_signal;
		g_received_signal = 0;
	}
	else
		data->exit_status = data->exit_status_final;
	ft_free_str_arr(data->created_files);
	ft_free_tokens(data->tokens);
	data->tokens = NULL;
	data->created_files = NULL;
	add_history(data->line);
}
