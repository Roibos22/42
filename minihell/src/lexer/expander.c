/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:47:07 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/11 17:34:50 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * replaces environment variables with its values in case
 * a $ sign is found in the current string
*/
void	ft_expander(t_lexer_help *lh, t_data *data)
{
	if (ft_strncmp(lh->result[lh->curr_t], "\"$\"", 4) == 0)
		return ;
	if (lh->line[lh->start] == '"' || lh->line[lh->start] != '\'')
	{
		if (ft_has_env_value(lh->result[lh->curr_t]))
			lh->result[lh->curr_t] = \
			replace_env_variables(lh->result[lh->curr_t], *lh->envp, data);
	}
}

/**
 * actually replaces environment variables with its values
*/
char	*replace_env_variables(char *str, char **env, t_data *data)
{
	int		final_length;
	char	*result;
	char	*res_ptr;
	char	*ptr;

	final_length = calculate_final_length(str, env, data);
	result = malloc(final_length + 1);
	if (result == NULL)
		return (NULL);
	ptr = str;
	res_ptr = result;
	while (*ptr != '\0') 
	{
		if (*ptr == '$')
			update_result(&ptr, &res_ptr, env, data);
		else
			*res_ptr++ = *ptr++;
	}
	*res_ptr = '\0';
	free(str);
	return (result);
}

/**
 * Calculate the final length of a string with env variables.
 * Necessary as env values and variables mostly have different lenghts.
*/
int	calculate_final_length(char *str, char **env, t_data *data)
{
	int		final_length;
	char	*ptr;
	char	*end;

	ptr = str;
	final_length = 0;
	while (*ptr != '\0') 
	{
		if (*ptr == '$') 
		{
			end = ptr + 1;
			while (*end != '\0' && *end != '$' && *end != ' ' && \
			*end != '"' && *end != '\'' && *end != '=' && *end != ':')
				end++;
			final_length += calculate_length(ptr, end, env, data);
			ptr = end;
		}
		else 
		{
			final_length++;
			ptr++;
		}
	}
	return (final_length);
}

/**
 * get the length of one specific env value
*/
int	calculate_length(char *ptr, char *end, char **env, t_data *data)
{
	int		len;
	char	*var_name;
	char	*value;
	int		length;

	len = end - ptr - 1;
	var_name = get_var_name(ptr, end);
	value = get_env_value(var_name, env, data);
	length = 0;
	if (value == NULL)
	{
		free(var_name);
		return (0);
	}
	length = ft_strlen(value);
	if (ft_strncmp(value, "$", 1) == 0 || ft_strncmp(var_name, "?", 1) == 0)
		free(value);
	free(var_name);
	return (length);
}

/**
 * paste the environment value at the place where the 
 * variable was found.
*/
void	update_result(char **ptr, char **res_ptr, char **env, t_data *data)
{
	char	*end;
	char	*var_name;
	char	*value;
	int		len;

	end = *ptr + 1;
	while (*end != '\0' && *end != '$' && *end != ' ' && \
	*end != '"' && *end != '\'' && *end != '=' && *end != ':')
		end++;
	len = end - *ptr - 1;
	var_name = get_var_name(*ptr, end);
	value = get_env_value(var_name, env, data);
	if (value != NULL)
	{
		ft_strlcpy(*res_ptr, value, ft_strlen(value) + 1);
		*res_ptr += ft_strlen(value);
		if (ft_strncmp(value, "$", 1) == 0 || ft_strncmp(var_name, "?", 1) == 0)
			free(value);
	}
	free(var_name);
	*ptr = end;
}
