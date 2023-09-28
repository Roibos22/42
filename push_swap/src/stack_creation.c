/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:42:46 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/03 17:43:13 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*head;
	char	**args;
	int		i;

	args = prepare_args(argc, argv);
	head = NULL;
	if (!args)
		return (NULL);
	argc --;
	i = 0;
	argc = count_args(args);
	while (i < argc)
	{
		if (!arg_is_int(args[i]))
			return (non_numeric_parameter_exit(args, head), NULL);
		else
		{
			head = create_and_add_node(args[i], head);
		}
		i++;
	}
	free_args_after_split(args);
	return (head);
}

int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

t_stack	*create_and_add_node(char *arg, t_stack *head)
{
	t_stack	*new_node;

	new_node = create_node(ft_atoi(arg));
	head = add_to_stack(head, new_node);
	return (head);
}

t_stack	*create_node(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->previous = NULL;
	new->moves = NULL;
	return (new);
}

t_stack	*add_to_stack(t_stack *head, t_stack *new_node)
{
	t_stack	*last_node;

	last_node = NULL;
	if (head == NULL)
		head = new_node;
	else
	{
		last_node = head;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->previous = last_node;
	}
	return (head);
}
