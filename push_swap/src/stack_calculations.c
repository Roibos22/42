/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_calculations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:17:31 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/02 11:10:21 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack(t_stack *head_a)
{
	int		count;
	t_stack	*node;

	if (!head_a)
		return (0);
	count = 0;
	node = get_first_node(head_a);
	if (!node)
		return (count);
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

int	is_max(t_stack *node)
{
	t_stack	*head;

	head = get_first_node(node);
	while (head->next)
	{
		if (node->content >= head->content)
			head = head->next;
		else
			return (0);
	}
	return (1);
}

// put together into one function get_max_node()

int	index_of_max(t_stack *node)
{
	t_stack	*current;
	int		index;
	int		max;

	index = 0;
	current = get_first_node(node);
	max = current->content;
	while (current->next)
	{
		if (current->content > max)
		{
			max = current->content;
			index = current->index;
		}
		current = current->next;
	}
	if (current->content > max)
	{
		max = current->content;
		index = current->index;
	}
	return (index);
}

int	value_of_max(t_stack *node)
{
	t_stack	*current;
	int		max;

	current = get_first_node(node);
	max = current->content;
	while (current->next)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	if (current->content > max)
		max = current->content;
	return (max);
}
