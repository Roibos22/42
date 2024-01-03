/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:38:55 by smargine          #+#    #+#             */
/*   Updated: 2023/12/08 21:47:30 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * handles the echo command in minishell
*/
int	ft_echo(t_statment *stm)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (stm->cmd_args[1])
	{
		if (!stm->cmd_args[2])
			return (0);
		while (ft_strncmp(stm->cmd_args[++i], "-n", 2) == 0 && \
		ft_only_n(stm->cmd_args[i]))
			flag = 1;
		while (stm->cmd_args[i])
		{
			ft_printf("%s", stm->cmd_args[i]);
			if (stm->cmd_args[i + 1])
				ft_printf(" ");
			i++;
		}
		if (!flag)
			ft_printf("\n");
	}
	else
		ft_printf("\n");
	return (0);
}

/**
 * handles option "-n" for echo command
*/
bool	ft_only_n(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}
