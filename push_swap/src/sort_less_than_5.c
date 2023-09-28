/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:49:18 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/01 17:57:41 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack)
{
	t_stack	*node_a;
	t_stack	*node_b;

	node_a = *stack;
	node_b = node_a->next;
	if (node_a->content > node_b->content)
		perform_operation(stack, NULL, 1);
}

void	sort_3(t_stack **stack)
{
	t_stack	*node_a;
	t_stack	*node_b;
	t_stack	*node_c;

	node_a = *stack;
	node_b = node_a->next;
	node_c = node_b->next;
	if (node_a->content > node_b->content)
	{
		if (node_b->content < node_c->content)
			perform_operation(stack, NULL, 6);
		else
			perform_operation(stack, NULL, 1);
	}
	node_a = get_first_node(*stack);
	node_b = node_a->next;
	node_c = node_b->next;
	if (node_c->content < node_a->content && node_c->content < node_b->content)
		perform_operation(stack, NULL, 9);
	else if (node_c->content < node_b->content)
	{
		perform_operation(stack, NULL, 9);
		perform_operation(stack, NULL, 1);
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*first_node;

	find_lowest_and_push(a, b);
	first_node = get_first_node(*a);
	a = &first_node;
	sort_3(a);
	first_node = get_first_node(*a);
	a = &first_node;
	perform_operation(a, b, 4);
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*first_node;

	find_lowest_and_push(a, b);
	first_node = get_first_node(*a);
	a = &first_node;
	index_stack(*a);
	find_lowest_and_push(a, b);
	first_node = get_first_node(*a);
	a = &first_node;
	sort_3(a);
	first_node = get_first_node(*a);
	a = &first_node;
	perform_operation(a, b, 4);
	perform_operation(a, b, 4);
}

void	sort_less_than_5(t_stack **a, t_stack **b)
{
	t_stack	*head_a;

	if (count_stack(*a) == 2)
		sort_2(a);
	else if (count_stack(*a) == 3)
		sort_3(a);
	else if (count_stack(*a) == 4)
		sort_4(a, b);
	else if (count_stack(*a) == 5)
		sort_5(a, b);
	b = NULL;
	head_a = get_first_node(*a);
	a = &head_a;
}
