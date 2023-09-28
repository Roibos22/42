/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:03:02 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/23 15:16:44 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

int ft_atoi(const char *str)
{
	int	n;
	int i;
	int flag;

	n = 0;
	i = 0;
	flag = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * flag);	
}

#include <stdio.h>

int main(void)
{
	printf("%i", ft_atoi("-120"));
}











