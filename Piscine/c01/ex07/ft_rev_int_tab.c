/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:19:39 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/15 10:40:42 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	c;
	int	tmp;

	c = 0;
	while (c <= size / 2 - 1)
	{
		tmp = tab[c];
		tab[c] = tab[size - 1 - c];
		tab[size - 1 - c] = tmp;
		c++;
	}
}
