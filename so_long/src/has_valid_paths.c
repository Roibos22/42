/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:51:24 by leon              #+#    #+#             */
/*   Updated: 2023/08/28 11:14:39 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_coords(t_coord *s, t_coord *e, t_coord *c)
{
	t_coord	*tmp;

	while (s)
	{
		tmp = s->next;
		free(s);
		s = tmp;
	}
	while (e)
	{
		tmp = e->next;
		free(e);
		e = tmp;
	}
	while (c)
	{
		tmp = c->next;
		free(c);
		c = tmp;
	}
}

void	free_file(char **file)
{
	int	i;
	int	lines;

	lines = count_lines_file(file);
	i = 0;
	while (i < lines)
	{
		free(file[i]);
		i++;
	}
	free(file);
}

int	has_valid_paths(char *argv)
{
	char	**file;
	char	**copy;
	t_coord	*s_coords;
	t_coord	*e_coords;
	t_coord	*c_coords;

	file = read_file(argv);
	copy = read_file(argv);
	if (!file)
		return (0);
	s_coords = get_all_coords(file, 'P');
	e_coords = get_all_coords(file, 'E');
	c_coords = get_all_coords(file, 'C');
	if (!check_all_paths_poss(file, copy, s_coords, e_coords))
	{
		free_coords(s_coords, e_coords, c_coords);
		return (0);
	}
	free_coords(s_coords, e_coords, c_coords);
	return (1);
}

t_coord	*get_all_coords(char **file, char c)
{
	t_coord	*head_coord;
	int		row;
	int		column;

	row = 0;
	column = 0;
	head_coord = NULL;
	while (file[row] != NULL)
	{
		while (file[row][column])
		{
			if (file[row][column] == c)
				head_coord = add_coord_to_list(head_coord, row, column, c);
			column++;
		}
		row++;
		column = 0;
	}
	return (head_coord);
}

t_coord	*add_coord_to_list(t_coord *head_coord, int row, int column, char c)
{
	t_coord	*new_coord;
	t_coord	*head_coord_copy;

	new_coord = malloc(sizeof(t_coord));
	new_coord->character = c;
	new_coord->column = column;
	new_coord->row = row;
	new_coord->next = NULL;
	if (!head_coord)
		return (new_coord);
	head_coord_copy = head_coord;
	while (head_coord->next)
		head_coord = head_coord->next;
	head_coord->next = new_coord;
	return (head_coord_copy);
}
