/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:07:05 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/08 01:49:05 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * write error to stderr and set exit_status
*/
void	ft_perror(const char *msg, char *cmd, unsigned int err, t_data *data)
{
	if (msg != NULL)
		write(2, msg, ft_strlen(msg));
	if (cmd != NULL)
	{
		write(2, ": ", 2);
		write(2, cmd, ft_strlen(cmd));
		write(2, "\n", 1);
	}
	data->exit_status = err;
	return ;
}

/**
 * helper function for export command errors
*/
int	ft_export_error(char *str, t_data *data)
{
	ft_putstr_fd("minishell: export: \'", 2);
	if (str)
		ft_putstr_fd(str, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
	data->exit_status = 1;
	return (1);
}
