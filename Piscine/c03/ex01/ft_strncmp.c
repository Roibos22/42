/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:47:51 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/22 11:01:33 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%i\n", ft_strncmp("Hallo", "Halz", 5));
	printf("%i\n", strncmp("Hallo", "Halz", 5));
	printf("%i\n", ft_strncmp("Hal", "Hallo", 5));
	printf("%i\n", strncmp("Hal", "Hallo", 5));
	printf("%i\n", ft_strncmp("", "", 5));
	printf("%i\n", strncmp("", "", 5));
}
*/
