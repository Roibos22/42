/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:17:03 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/23 15:22:45 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Reproduce the behavior of the function strcmp (man strcmp).
Your function must be declared as follows:
int    ft_strcmp(char *s1, char *s2);
	0, if the s1 and s2 are equal;
	-1 value if s1 is less than s2;
	1 positive value if s1 is greater than s2.
*/

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
