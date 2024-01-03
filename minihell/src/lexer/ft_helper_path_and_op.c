/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_path_and_op.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:13:43 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/11 17:30:55 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * checks if a path leads to an executable
*/
bool	ft_is_correct_path(char *str)
{
	if (access(str, X_OK) == 0)
		return (true);
	return (false);
}

/**
 * checks if a string is an operator
*/
bool	ft_is_op(char *str)
{
	if (ft_strncmp(str, "<", 2) == 0)
		return (true);
	else if (ft_strncmp(str, ">", 2) == 0)
		return (true);
	else if (ft_strncmp(str, "<<", 3) == 0)
		return (true);
	else if (ft_strncmp(str, ">>", 3) == 0)
		return (true);
	else if (ft_strncmp(str, "|", 2) == 0)
		return (true);
	return (false);
}

/**
 * checks which operator was found and returns its type
*/
t_type	ft_find_op_type(char *str)
{
	t_type	type;

	type = PIPE;
	if (ft_strncmp(str, "<", 2) == 0)
		type = IN_REDIR;
	else if (ft_strncmp(str, ">", 2) == 0)
		type = OUT_REDIR;
	else if (ft_strncmp(str, "<<", 3) == 0)
		type = HERE_DOC;
	else if (ft_strncmp(str, ">>", 3) == 0)
		type = APPEND;
	return (type);
}
