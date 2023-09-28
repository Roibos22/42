/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:09:40 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/23 14:38:02 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allowed functions: write
--------------------------------------------------------------------------------
Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.
Your function must be declared as follows:
void	print_bits(unsigned char octet);
Example, if you pass 2 to print_bits, it will print "00000010"
*/

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if (octet & (1 << i))
			write (1, "1", 1);
		else 
			write (1, "0", 1);
		i--;
	}
}

int main(void)
{
	print_bits(2);
	return (0);
}
