/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:45:53 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/23 18:59:52 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

#include <stdio.h>

int is_valid(const char s, int str_base)
{
	char *small = "0123456789abcdef";
	char *big 	= "0123456789ABCDEF";

	while(str_base)
	{
		if (str_base>= 0 || s == small[str_base] || s == big[str_base])
			return (1);
		str_base--;
	}
	return (0);
}

int value_of(const char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else
		return (0);
}

int ft_atoi_base(const char *str, int str_base)
{
	int i;
	int flag;
	int n;

	n = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			flag = 1;
		else
			flag = -1;
		i++;
	}		
	while (is_valid(str[i], str_base))
	{
		n = n * str_base + value_of(str[i]);
		i++;
		printf("%i\n", n);
	}
	return (n);
}

int main(void)
{
	//printf("%s\n", "-123");
	printf("%i", ft_atoi_base("F", 16));
}
