/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_square_of_pos.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:15:07 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 09:20:29 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	find_biggest_square_of_pos(char *map[], point_struct p) 
{
	int length = 1;
	int rows = get_rows(map);
	int columns = get_columns(map);

	while (validate_square(map, p, length) == '1')
	{
		length++;
		if (rows + 1 == length + p.x || columns + 1 == length + p.y)
		{
			return (length - 2);
		}
		//printf("new length: %i\n", length);
	}
	//printf("x: %i\n", p.x);
	//printf("y: %i\n", p.y);
	//printf("length: %i\n", length);
	return(length - 2);
}