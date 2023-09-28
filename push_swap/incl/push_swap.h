/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:37:42 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/03 17:46:23 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	int				index;
	int				*moves;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

// debugging
void	print_stack(t_stack **stack);
void	print_node(t_stack *node);
void	print_stack_detailed(t_stack **stack);
void	print_stacks(t_stack **a, t_stack **b);

// stack creation
t_stack	*create_stack(int n, char **strings);
int		count_args(char **args);
t_stack	*create_and_add_node(char *arg, t_stack *head);
t_stack	*add_to_stack(t_stack *head, t_stack *new_node);
t_stack	*create_node(int content);

// stack creation helper
void	free_args_after_split(char **args);
void	non_numeric_parameter_exit(char **args, t_stack *head);
char	**new_argv(int argc, char **argv);
char	**prepare_args(int argc, char **argv);

// error handling
int		check_for_duplicates(t_stack *head);
int		arg_is_int(char *arg);
int		check_sorted(t_stack *head);

// stack operations
void	index_stack(t_stack *stack);
void	destroy_stack(t_stack *head);
t_stack	*get_last_node(t_stack *node);
t_stack	*get_node_by_index(int index, t_stack *node);

// stack calculations
int		count_stack(t_stack *head_a);
int		is_max(t_stack *node);
int		index_of_max(t_stack *node);
int		value_of_max(t_stack *node);

// node operations
t_stack	*get_first_node(t_stack *stack);
t_stack	*get_min_node(t_stack **stack_a);
t_stack	**rotate_node_to_top(int index, int size, t_stack **a, t_stack **b);
void	find_lowest_and_push(t_stack **stack_a, t_stack **stack_b);

// operations
void	perform_swap(t_stack **head);
void	perform_push(t_stack **from_head, t_stack **to_head);
void	perform_rotation(t_stack *head);
void	perform_rotation_reverse(t_stack **head);

// perform_operation
void	perform_operation(t_stack **a, t_stack **b, int op);
void	perform_operation_a(t_stack **a, t_stack **b, int op);
void	perform_operation_b(t_stack **a, t_stack **b, int op);
void	perform_operation_c(t_stack **a, t_stack **b, int op);

// sort less than 5
void	sort_less_than_5(t_stack **a, t_stack **b);
void	sort_2(t_stack **stack);
void	sort_3(t_stack **stack);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);

// sort more than 5
void	sort_more_than_5(t_stack **a, t_stack **b);
t_stack	*get_cheapest_node(t_stack **a);
void	push_all_to_a(t_stack **a, t_stack **b);
void	perform_moves_of_node(t_stack *node, t_stack **a, t_stack **b);
void	calculate_and_perform_moves(t_stack **a, t_stack **b);

// moves array
void	add_operation_empty_moves(t_stack *node, int operation, int cost);
int		*copy_moves_array(t_stack *node);
void	create_new_moves_array(t_stack *node, int operation, int cost);
void	add_operation(t_stack *node, int operation, int cost);
void	destroy_moves_array(t_stack **stack);

// calculate moves
int		get_moves_array_size(int *moves);
void	calculate_moves(t_stack **a, t_stack **b);
void	add_moves_to_top_of_a(t_stack *node);
void	add_moves_to_rotate_b(t_stack *node, t_stack **b);
int		get_target_index(t_stack *node, t_stack *node_b);

#endif
