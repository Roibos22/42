/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:37:50 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/02 16:01:21 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_swap(t_stack **head)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*third_node;

	if (count_stack(*head) == 1)
		return ;
	first_node = get_first_node(*head);
	second_node = first_node->next;
	third_node = NULL;
	if (second_node->next != NULL)
	{
		third_node = second_node->next;
		third_node->previous = first_node;
	}
	head = &second_node;
	first_node->next = second_node->next;
	first_node->previous = second_node;
	second_node->next = first_node;
	second_node->previous = NULL;
}

void	perform_push(t_stack **from_head, t_stack **to_head)
{
	t_stack	*node_to_push;

	if (!from_head || !(*from_head))
		return ;
	node_to_push = *from_head;
	if (node_to_push->next)
		*from_head = node_to_push->next;
	else
		*from_head = NULL;
	if (*from_head)
		(*from_head)->previous = NULL;
	if (*to_head)
	{
		node_to_push->next = *to_head;
		(*to_head)->previous = node_to_push;
		*to_head = node_to_push;
	}
	else
	{
		*to_head = node_to_push;
		node_to_push->next = NULL;
	}
}

void	perform_rotation(t_stack *head)
{
	t_stack	*node;
	t_stack	*new_first_node;
	t_stack	*last_node;

	node = head;
	new_first_node = node->next;
	last_node = get_last_node(head);
	if (!node || !node->next)
		return ;
	head = new_first_node;
	new_first_node->previous = NULL;
	last_node->next = node;
	node->previous = last_node;
	node->next = NULL;
}

void	perform_rotation_reverse(t_stack **head)
{
	t_stack	*node;
	t_stack	*new_last_node;
	t_stack	*old_first_node;

	if (!head || count_stack(*head) == 1)
		return ;
	node = get_last_node(*head);
	new_last_node = node->previous;
	old_first_node = get_first_node(*head);
	head = &node;
	node->previous = NULL;
	node->next = old_first_node;
	new_last_node->next = NULL;
	old_first_node->previous = node;
}
