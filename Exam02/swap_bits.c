/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:54:54 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/23 15:02:21 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    print_bits(unsigned char octet)
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
	write(1, "\n", 1);
}

/*
Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
*/

unsigned char swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

#include <stdio.h>

int main(void)
{
	unsigned char c = 2;
	print_bits(c);
	print_bits(swap_bits(c));
}
