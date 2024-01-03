/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:43:10 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/03 16:41:30 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more_than_5(t_stack **a, t_stack **b)
{
	t_stack	*head_b;

	perform_operation(a, b, 5);
	perform_operation(a, b, 5);
	index_stack(get_first_node(*a));
	index_stack(get_first_node(*b));
	head_b = get_first_node(*b);
	if (head_b->content < head_b->next->content)
		perform_operation(a, b, 7);
	head_b = get_first_node(*b);
	b = &head_b;
	index_stack(get_first_node(*a));
	index_stack(get_first_node(*b));
	calculate_and_perform_moves(a, b);
}

t_stack	*get_cheapest_node(t_stack **a)
{
	t_stack	*node;
	t_stack	*cheapest_node;

	node = get_first_node(*a);
	cheapest_node = node;
	while (node->next)
	{
		if (get_moves_array_size(node->next->moves) < \
		get_moves_array_size(cheapest_node->moves))
			cheapest_node = node->next;
		node = node->next;
	}
	return (cheapest_node);
}

void	push_all_to_a(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*head_b;

	head_b = get_first_node(*b);
	index_stack(head_b);
	while (index_of_max(head_b) != 0)
	{
		//ft_printf("Index of max in b: %i, Numbers in b: %i", index_of_max(head_b));
		if (index_of_max(head_b) >= count_stack(head_b) / 2)
		{
			// rrb
			perform_operation(a, b, 10);
			head_b = get_first_node(*b);
			b = &head_b;
			index_stack(head_b);
		}
		else
		{
			// rb
			perform_operation(a, b, 7);
			head_b = get_first_node(*b);
			b = &head_b;
			index_stack(head_b);
		}

	}
	size = count_stack(*b);
	while (size >= 0)
	{
		perform_operation(a, b, 4);
		size--;
	}
}

void	perform_moves_of_node(t_stack *node, t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*head_a;
	t_stack	*head_b;

	i = 0;
	head_a = get_first_node(*a);
	head_b = get_first_node(*b);
	while (node->moves[i])
	{
		perform_operation(a, b, node->moves[i]);
		head_a = get_first_node(*a);
		head_b = get_first_node(*b);
		*a = head_a;
		*b = head_b;
		i++;
	}
}

void	calculate_and_perform_moves(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = get_first_node(*a);
	head_b = get_first_node(*b);
	while (count_stack(*a) > 1)
	{
		head_a = get_first_node(head_a);
		head_b = get_first_node(head_b);
		calculate_moves(a, b);
		cheapest_node = get_cheapest_node(a);
		perform_moves_of_node(cheapest_node, a, b);
		destroy_moves_array(a);
		destroy_moves_array(b);
	}
	calculate_moves(a, b);
	cheapest_node = get_cheapest_node(a);
	perform_moves_of_node(cheapest_node, a, b);
	push_all_to_a(a, b);
}
