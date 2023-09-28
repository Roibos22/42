/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:41:26 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/02 11:34:25 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	t_stack	*node;
	int		index;

	if (!stack)
		return ;
	index = 0;
	node = stack;
	while (node->next)
	{
		node->index = index;
		node = node->next;
		index++;
	}
	node->index = index;
}

t_stack	*get_last_node(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_stack	*get_node_by_index(int index, t_stack *node)
{
	while (node->next)
	{
		if (node->index == index)
			return (node);
		node = node->next;
	}
	return (node);
}

void	destroy_stack(t_stack *head)
{
	t_stack	*tmp;

	head = get_first_node(head);
	if (!head)
		return ;
	while (head->next)
	{
		tmp = head->next;
		free(head->moves);
		free(head);
		head = tmp;
	}
	free(head->moves);
	free (head);
}
