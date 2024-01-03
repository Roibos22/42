/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:41:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/03 16:04:34 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_first_node(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->previous)
		node = node->previous;
	return (node);
}

t_stack	*get_min_node(t_stack **stack_a)
{
	int		index_of_min;
	int		min_value;
	t_stack	*current_node;

	current_node = *stack_a;
	index_of_min = 0;
	min_value = current_node->content;
	while (current_node->next)
	{
		current_node = current_node->next;
		if (current_node->content < min_value)
		{
			min_value = current_node->content;
			index_of_min = current_node->index;
		}
	}
	return (get_node_by_index(index_of_min, *stack_a));
}

t_stack	**rotate_node_to_top(int index, int size, t_stack **a, t_stack **b)
{
	t_stack	*current_node;

	if (index > size / 2)
	{
		while (size - index > 0)
		{
			perform_operation(a, b, 9);
			current_node = get_first_node(*a);
			a = &current_node;
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			perform_operation(a, b, 6);
			current_node = get_first_node(*a);
			a = &current_node;
			index--;
		}
	}
	return (a);
}

void	find_lowest_and_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_node;
	t_stack	*min_node;
	int		index_of_min;
	int		stack_size;

	if (*stack_a == NULL)
		return ;
	stack_size = count_stack(*stack_a);
	min_node = get_min_node(stack_a);
	index_of_min = min_node->index;
	stack_a = rotate_node_to_top(index_of_min, stack_size, stack_a, stack_b);
	perform_operation(stack_a, stack_b, 5);
	current_node = get_first_node(*stack_a);
	stack_a = &current_node;
}
