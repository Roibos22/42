/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:05:09 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/03 17:38:00 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args_after_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free (args[i]);
		i++;
	}
	free (args); 
}

void	non_numeric_parameter_exit(char **args, t_stack *head)
{
	write(2, "Error\n", 6);
	free_args_after_split(args);
	destroy_stack(head);
}

char	**new_argv(int argc, char **argv)
{
	char	**new_argv;
	int		i;
	int		str_len;

	i = 1;
	str_len = 0;
	new_argv = malloc(argc * sizeof(char *));
	if (!new_argv)
		return (NULL);
	while (i < argc)
	{
		str_len = ft_strlen(argv[i]);
		new_argv[i - 1] = malloc(str_len * sizeof(char) + 1);
		if (!new_argv[i - 1])
			return (NULL);
		ft_strlcpy(new_argv[i -1], argv[i], str_len + 1);
		i++;
	}
	new_argv[i - 1] = NULL;
	return (new_argv);
}

char	**prepare_args(int argc, char **argv)
{
	char	**args;

	args = NULL;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = new_argv(argc, argv);
	return (args);
}
