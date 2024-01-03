/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:23:05 by smargine          #+#    #+#             */
/*   Updated: 2023/12/07 23:44:55 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * handles the exit command in minishell
*/
int	ft_exit(t_statment *stm, t_data *data)
{
	unsigned int	exit_status;

	exit_status = 0;
	if (stm->start_token->prev)
		return (0);
	write(data->orig_std_out, "exit\n", 5);
	if (stm->cmd_args[1] && \
	ft_check_digit(stm->cmd_args[1], stm, data) && stm->cmd_args[2] == NULL)
		exit_status = ft_atoi(stm->cmd_args[1]);
	else if (stm->cmd_args[1] && stm->cmd_args[2])
	{
		ft_perror(EXIT_ARG_ERR, NULL, 127, data);
		return (EXIT_FAILURE);
	}
	ft_free_stm(stm);
	ft_clean_data(data, 1);
	exit(exit_status);
}

/**
 * handles the exit_status(option) of exit command
*/
bool	ft_check_digit(char *str, t_statment *stm, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_printf("minishell: exit: %s: numeric argument required\n", str);
			ft_free_stm(stm);
			ft_clean_data(data, 1);
			exit(2);
		}
		i++;
	}
	return (true);
}
