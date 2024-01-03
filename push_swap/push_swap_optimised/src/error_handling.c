/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:39:30 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/01 17:15:12 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_duplicates(t_stack *head)
{
	t_stack	*node;
	t_stack	*node_to_compare;

	index_stack(head);
	if (!head)
		return (0);
	node = head;
	if (!node)
		return (0);
	while (node)
	{
		node_to_compare = node->next;
		while (node_to_compare)
		{
			if (node_to_compare->content == node->content)
				return (0);
			node_to_compare = node_to_compare->next;
		}
		node = node->next;
	}
	return (1);
}

int	arg_is_int(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	if (ft_atoi(arg) > INT_MAX || ft_atoi(arg) < INT_MIN)
		return (0);
	return (1);
}

int	check_sorted(t_stack *head)
{
	t_stack	*node;
	t_stack	*next_node;

	node = head;
	next_node = node->next;
	index_stack(head);
	while (node->next != NULL)
	{
		if (node->content < next_node->content)
		{
			node = next_node;
			next_node = next_node->next;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
