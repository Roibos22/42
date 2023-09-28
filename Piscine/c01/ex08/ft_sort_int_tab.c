/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:02:02 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/15 10:58:13 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	c;
	int	tmp;

	c = 0;
	while (c <= size - 2)
	{	
		if (tab[c] > tab[c + 1])
		{
			tmp = tab[c];
			tab[c] = tab[c + 1];
			tab[c + 1] = tmp;
			c = 0;
		}
		else
		{
			c++;
		}
	}
}
