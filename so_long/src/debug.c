/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:48:19 by leon              #+#    #+#             */
/*   Updated: 2023/08/24 19:29:03 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **file)
{
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (file[row])
	{
		while (file[row][column])
		{
			ft_printf("%c", file[row][column]);
			column++;
		}
		row++;
		column = 0;
	}
	ft_printf("\n\n");
}

void	print_coords(t_coord *coord)
{
	if (!coord)
	{
		ft_printf("No coords in list\n");
		return ;
	}
	ft_printf("%i", coord->row);
	ft_printf("%i\n", coord->column);
	if (coord->next)
		print_coords(coord->next);
}
