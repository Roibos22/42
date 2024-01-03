/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:44:48 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/03 16:05:27 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_operation_empty_moves(t_stack *node, int operation, int cost)
{
	int	i;

	i = 0;
	node->moves = malloc(sizeof(int) * (cost + 1));
	node->moves[cost] = 0;
	while (i < cost)
	{
		node->moves[i] = operation;
		i++;
	}
	node->moves[i] = 0;
}

int	*copy_moves_array(t_stack *node)
{
	int	i;
	int	size;
	int	*tmp;

	i = 0;
	size = get_moves_array_size(node->moves);
	tmp = malloc(sizeof(int) * (size + 1));
	while (i < size)
	{
		tmp[i] = node->moves[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

void	create_new_moves_array(t_stack *node, int operation, int cost)
{
	int	i;
	int	*tmp;
	int	size_old;

	tmp = copy_moves_array(node);
	free(node->moves);
	size_old = get_moves_array_size(tmp);
	node->moves = malloc(sizeof(int) * (cost + size_old + 1));
	i = 0;
	while (i < size_old)
	{
		node->moves[i] = tmp[i];
		i++;
	}
	while (i < cost + size_old)
	{
		node->moves[i] = operation;
		i++;
	}
	node->moves[i] = 0;
	free(tmp);
}

void	add_operation(t_stack *node, int operation, int cost)
{
	if (node->moves == NULL)
		add_operation_empty_moves(node, operation, cost);
	else
		create_new_moves_array(node, operation, cost);
}

void	destroy_moves_array(t_stack **stack)
{
	t_stack	*node;

	if (!stack || !(*stack))
		return ;
	node = get_first_node(*stack);
	free(node->moves);
	node->moves = NULL;
	while (node->next)
	{
		free(node->next->moves);
		node->next->moves = NULL;
		node = node->next;
	}
}
