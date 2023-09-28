/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:03:17 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/23 17:45:45 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char str[])
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return ((1));
		i++;
	}
	return (0);
}

char	*sort(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	j = 2;
	while (i < argc - 1)
	{
		j = i + 1;
		if (ft_strcmp(argv[j], argv[i]) < 0)
		{
			tmp = argv[j];
			argv[j] = argv[i];
			argv[i] = tmp;
			i = 1;
		}
		else
		{
			i++;
		}
	}
	return (*argv);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*args;

	args = sort(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
