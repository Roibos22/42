/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:15:49 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 09:16:05 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

point_struct ft_find_biggest_square(char* map[], int numLines)
{
	int	x;
	int	y;
	struct point_struct p;
	struct point_struct p_max;

	p_max.value = 0;
	p_max.x = 0;
	p_max.y = 0;

	x = 0;
	y = 0;

	while (x < numLines) 
	{
		int len = ft_strlen(map[x]);
		while (y < len)
		{
			//write(1, &map[i][j], 1);
			//write(1, "\n", 1);
			p.x = x;
			p.y = y;
			//p.value = 0;
			p.value = find_biggest_square_of_pos(map, p);
			//print_point(p);
			if (p.value > p_max.value)
			{
				p_max.x = p.x;
				p_max.y = p.y;
				p_max.value = p.value;
			}
			//print_point(p);
			y++;
			p.value = 0;
		}
		x++;
		y = 0;
	}

	print_point(p_max);
	return (p_max);
}
