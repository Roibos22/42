/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:16:24 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 09:16:36 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map(char *map[], point_struct p)
{	
	int rows = get_rows(map);
	int columns = get_columns(map);
	printf("%i\n", columns);
	int r = 0;
	int c = 0;
	
	while (r <= rows)
	{
		while (c <= columns)
		{
			if ((c >= p.y && c <= (p.y + p.value)) && (r >= p.x && r <= (p.x + p.value)))
			{
				write(1, "x", 1);
				//write(1, &map[r][c], 1);
			}
			else
			{
				write(1, &map[r][c], 1);
			}
			c++;
		}
		r++;
		c = 0;
		write(1, "\n", 1);
	}	

}