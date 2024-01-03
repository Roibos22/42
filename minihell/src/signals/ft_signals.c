/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:31:27 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/08 16:43:01 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * main function that catches signals (SIGINT and SIGQUIT) and handles them
*/
void	ft_signals(int signum, t_data *data)
{
	if (signum == 1)
	{
		signal(SIGINT, ft_handle_sigint);
		signal(SIGQUIT, SIG_IGN);
	}
	if (signum == 2)
	{
		signal(SIGINT, ft_handle_ctrlc);
		signal(SIGQUIT, ft_handle_backslash);
	}
	if (signum == 3)
	{
		ft_printf("exit\n");
		ft_clean_data(data, 1);
		exit(0);
	}
	if (signum == 4)
	{
		signal(SIGINT, ft_handle_heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
}

/**
 * handles signal SIGINT inside main process
*/
void	ft_handle_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

/**
 * handles signal SIGINT during execution of a command
*/
void	ft_handle_ctrlc(int signum)
{
	if (signum != SIGINT)
		return ;
	g_received_signal = 130;
	write(1, "\n", 1);
}

/**
 * handles signal SIGQUIT during execution of a command
*/
void	ft_handle_backslash(int signum)
{
	if (signum != SIGQUIT)
		return ;
	g_received_signal = 131;
	printf("Quit (core dumped)\n");
}

/**
 * handles signal SIGINT inside heredoc "<<"
*/
void	ft_handle_heredoc(int signum)
{
	if (signum != SIGINT)
		return ;
	g_received_signal = true;
	rl_on_new_line();
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	return ;
}
