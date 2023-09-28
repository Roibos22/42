/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:14:14 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 10:20:54 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	validate_square(char *map[], point_struct p, int length)
{
	int		added_x = length;
	int		added_y = length;
	int		start_x = p.x; // 1
	int		start_y = p.y; // 1
	char	*square_str;
	char	c;

	square_str = (char *)malloc((added_x * added_y) + 1);
	while (added_x > 0)
	{
		while(added_y > 0)
		{
			ft_append_char(square_str, map[start_x + added_x - 1][start_y + added_y - 1]);

			added_y--;
		}
		added_x--;
		added_y = length;
	}
	ft_append_char(square_str, '\0');
	c = validate_string(square_str, '.');
	free(square_str);
	square_str[0] = '\0';
	return(c);
}