/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:40:03 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/01 15:29:23 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	**a;
	t_stack	**b;

	head_a = NULL;
	head_b = NULL;
	head_a = create_stack(argc, argv);
	if (!head_a || argc < 2)
		return (0);
	a = &head_a;
	b = &head_b;
	if (!check_for_duplicates(head_a))
		return (destroy_stack(head_a), write(2, "Error\n", 6), 0);
	if (check_sorted(head_a) == 1 || argc < 2)
		return (destroy_stack(head_a), 0);
	if (count_stack(head_a) <= 5)
		sort_less_than_5(a, b);
	else
		sort_more_than_5(a, b);
	return (destroy_stack(head_a), 0);
}
