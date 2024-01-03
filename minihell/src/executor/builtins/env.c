/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 02:03:59 by smargine          #+#    #+#             */
/*   Updated: 2023/12/07 22:26:00 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * handles the env command in minishell
*/
int	ft_env(t_statment *stm, t_data *data)
{
	int	i;

	i = 0;
	if (stm->cmd_args[1])
	{
		ft_perror(NO_FILE, NULL, 127, data);
		return (EXIT_FAILURE);
	}
	while (data->env[i])
	{
		if (ft_strchr(data->env[i], '='))
			ft_printf("%s\n", data->env[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
