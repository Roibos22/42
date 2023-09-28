/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:03:42 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/23 16:28:33 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
size_t	ft_strcspn(const char *s, const char *reject);
The strcspn() function calculates the length of the initial  segment  of  s
 which consists entirely of bytes not in reject.
The strcspn() function returns the number of bytes in the  initial  segment
 of s which are not in the string reject
*/

#include <string.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (reject[j])
		{
			if (reject[j] == s[i])
				return (i);
			j++;
		}
		i++;
		j = 0;
	}
	return (i);
}

#include <stdio.h>

int main(void)
{
	printf("%zu", ft_strcspn("Hello, world", ","));
}
