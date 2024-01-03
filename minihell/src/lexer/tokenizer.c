/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:53:01 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/12/08 14:35:47 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tokenize(t_data *data)
{
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	data->tokens = NULL;
	while (data->array[i])
	{
		flag = ft_tokenize_handle_string(data, i, flag);
		i++;
	}
	ft_add_token(&data->tokens, NULL);
}

int	ft_last_tok_is_red(t_token *tok)
{
	if (!tok)
		return (0);
	while (tok->next)
		tok = tok->next;
	if (ft_is_redirection(tok))
		return (1);
	return (0);
}

int	ft_tokenize_handle_string(t_data *data, int i, int flag)
{
	t_token	*new;
	t_type	type;

	new = NULL;
	if (ft_is_op(data->array[i]) && data->tok_is_red_str[i] == '0')
	{
		type = ft_find_op_type(data->array[i]);
		if (type == PIPE)
			flag = 0;
	}
	else if (ft_is_command(data->array[i], data) \
	&& flag == 0 && !ft_last_tok_is_red(data->tokens))
	{
		type = COMMAND;
		flag = 1;
	}
	else
		type = WORD;
	new = ft_new_token(data->array[i], type);
	ft_add_token(&data->tokens, new);
	return (flag);
}

t_token	*ft_new_token(char *content, t_type type)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	new->type = type;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_add_token(t_token **list, t_token *new)
{
	t_token	*temp;

	if (!new)
		return ;
	if (!*list)
	{
		new->prev = NULL;
		*list = new;
		return ;
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	if (new != NULL)
	{
		new->prev = temp;
		new->next = NULL;
	}
}
