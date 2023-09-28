/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:22:18 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/03 14:48:16 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moves_array_size(int *moves)
{
	int	size;

	size = 0;
	while (moves[size])
		size++;
	return (size);
}

void	calculate_moves(t_stack **a, t_stack **b)
{
	int		size;
	int		i;
	t_stack	*node;

	i = 0;
	node = *a;
	size = count_stack(node);
	index_stack(get_first_node(*a));
	index_stack(get_first_node(*b));
	while (i < size)
	{
		add_moves_to_top_of_a(node);
		add_moves_to_rotate_b(node, b);
		add_operation(node, 5, 1);
		node = node->next;
		i++;
	}
}

void	add_moves_to_top_of_a(t_stack *node)
{
	int	size;
	int	cost_to_top;

	size = count_stack(node);
	if (node->index <= (size / 2))
	{
		cost_to_top = node->index;
		if (cost_to_top > 0)
			add_operation(node, 6, cost_to_top);
	}
	else
	{
		cost_to_top = size - node->index;
		if (cost_to_top > 0)
			add_operation(node, 9, cost_to_top);
	}
}

void	add_moves_to_rotate_b(t_stack *node, t_stack **b)
{
	t_stack	*node_b;
	int		target_index;
	int		size;
	int		middle_index;

	node_b = get_first_node(*b);
	index_stack(get_first_node(*b));
	target_index = get_target_index(node, node_b);
	size = count_stack(node_b);
	middle_index = size / 2;
	if (target_index <= middle_index)
	{
		if (target_index > 0)
			add_operation(node, 7, target_index);
	}
	else if (target_index > middle_index)
	{
		if (size - target_index > 0)
			add_operation(node, 10, size - target_index);
	}
}

int	get_target_index(t_stack *node, t_stack *node_b)
{
	int	target_index;

	target_index = 0;
	while (node_b->next)
	{
		if (node_b->content > node->content && \
		(node_b->next->content < node->content || is_max(node_b->next)))
		{
			target_index = node_b->index + 1;
			break ;
		}
		node_b = node_b->next;
	}
	node_b = get_first_node(node_b);
	if (node->content > value_of_max(node_b))
		target_index = index_of_max(node_b);
	return (target_index);
}
