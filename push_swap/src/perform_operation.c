/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:58:02 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/02 16:01:05 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_operation_a(t_stack **a, t_stack **b, int op)
{
	if (op == 1)
	{
		perform_swap(a);
		ft_printf("sa\n");
	}
	else if (op == 2)
	{
		perform_swap(b);
		ft_printf("sb\n");
	}
	else if (op == 3)
	{
		perform_swap(a);
		perform_swap(b);
		ft_printf("ss\n");
	}
	else if (op == 4)
	{
		perform_push(b, a);
		ft_printf("pa\n");
	}
}

void	perform_operation_b(t_stack **a, t_stack **b, int op)
{
	if (op == 5)
	{
		perform_push(a, b);
		ft_printf("pb\n");
	}
	else if (op == 6)
	{
		perform_rotation(*a);
		ft_printf("ra\n");
	}
	else if (op == 7)
	{
		perform_rotation(*b);
		ft_printf("rb\n");
	}
	else if (op == 8)
	{
		perform_rotation(*a);
		perform_rotation(*b);
		ft_printf("rr\n");
	}
}

void	perform_operation_c(t_stack **a, t_stack **b, int op)
{
	if (op == 9)
	{
		perform_rotation_reverse(a);
		ft_printf("rra\n");
	}
	else if (op == 10)
	{
		perform_rotation_reverse(b);
		ft_printf("rrb\n");
	}
	else if (op == 11)
	{
		perform_rotation_reverse(a);
		perform_rotation_reverse(b);
		ft_printf("rrr\n");
	}
}

void	perform_operation(t_stack **a, t_stack **b, int op)
{
	if (op >= 1 && op <= 4)
		perform_operation_a(a, b, op);
	if (op >= 5 && op <= 8)
		perform_operation_b(a, b, op);
	if (op >= 9 && op <= 11)
		perform_operation_c(a, b, op);
}
