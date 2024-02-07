/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 04:52:40 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/07 05:44:53 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	execute_cd(void)
{
	printf("executing cd\n");
	return (0);
}

int	execute(void)
{
	printf("executing sys command\n");
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	// Error Handling
	int	i = 0;

	while (argv[i] && argv[i + 1])
	{
		// prepare argv[0] for next statement
		argv = &argv[i + 1];
		i = 0;

		// count elements of statment
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;

		// execute
		if (strcmp(argv[0], "cd") == 0)
			execute_cd();
		else if (i != 0)
			execute();

		printf("i: %i\n", i);
	}

}