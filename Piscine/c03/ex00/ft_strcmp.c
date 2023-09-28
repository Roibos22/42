/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:26:56 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/22 11:00:37 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

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
/*
int	main(void)
{
	printf("%i\n", ft_strcmp("Hallo", "Hal"));
	printf("%i\n", strcmp("Hallo", "Hal"));
	printf("%i\n", ft_strcmp("Hal", "Hallo"));
	printf("%i\n", strcmp("Hal", "Hallo"));
	printf("%i\n", ft_strcmp("", ""));
	printf("%i\n", strcmp("", ""));
}
*/
