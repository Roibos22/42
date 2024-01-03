/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:11:08 by smargine          #+#    #+#             */
/*   Updated: 2023/12/06 11:31:04 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * handles the pwd command in minishell
*/
int	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_printf("Error <pwd>.\n");
		return (EXIT_FAILURE);
	}
	ft_printf("%s\n", pwd);
	free(pwd);
	return (EXIT_SUCCESS);
}
