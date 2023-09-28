/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_paths_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:34:50 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/21 14:52:58 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all_paths_poss(char **file, char **copy, t_coord *from, t_coord *to)
{
	t_coord	*to_head;

	to_head = to;
	while (from)
	{
		while (to)
		{
			if (!check_path_possible(copy, from->row, from->column, to))
				return (free_file(file), free_file(copy), 0);
			to = to->next;
		}
		to = to_head;
		from = from->next;
	}
	return (free_file(file), free_file(copy), 1);
}

int	check_path_possible(char **file, int row, int column, t_coord *to_coord)
{
	if (check_coords(file, row + 1, column, to_coord))
		return (1);
	if (check_coords(file, row - 1, column, to_coord))
		return (1);
	if (check_coords(file, row, column + 1, to_coord))
		return (1);
	if (check_coords(file, row, column - 1, to_coord))
		return (1);
	return (0);
}

int	check_coords(char **file, int row, int column, t_coord *to_coord)
{
	if (row == to_coord->row && column == to_coord->column)
		return (1);
	else if (file[row][column] == '0' || file[row][column] == 'C')
	{
		file[row][column] = 'X';
		return (check_path_possible(file, row, column, to_coord));
	}
	else
		file[row][column] = 'X';
	return (0);
}
