/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:38:48 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/02 16:55:15 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node != NULL)
	{
		ft_printf("%d ", node->content);
		node = node->next;
	}
	ft_printf("\n");
}

void	print_moves(t_stack *node)
{
	ft_printf("Node %i moves: ", node->content);
	int i = 0;
	while (node->moves[i])
	{
		ft_printf("%i, ", node->moves[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_node(t_stack *node)
{
	ft_printf("Node %i, ", node->index);
	ft_printf("Content: %d, ", node->content);
	ft_printf("Address: %p ", node);
	ft_printf("Next: %p, ", node->next);
	ft_printf("Previous: %p", node->previous);
	ft_printf("\n");
}

void	print_stack_detailed(t_stack **stack)
{
	t_stack	*node;
	int		i;

	i = 1;
	node = *stack;
	while (node != NULL)
	{
		ft_printf("Node %i, ", node->index);
		ft_printf("Content: %d, ", node->content);
		ft_printf("Address: %p ", node);
		ft_printf("Next: %p, ", node->next);
		ft_printf("Previous: %p, ", node->previous);
		ft_printf("Moves:");
		node = node->next;
		i++;
	}
	ft_printf("\n\n");
}

void	print_stacks(t_stack **a, t_stack **b)
{
	ft_printf("STACK A:\n");
	if (a)
		print_stack_detailed(a);
	ft_printf("STACK B:\n");
	if (b)
		print_stack_detailed(b);
	ft_printf("\n");
}
