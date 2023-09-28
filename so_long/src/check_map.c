/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:46:19 by leon              #+#    #+#             */
/*   Updated: 2023/08/22 11:27:40 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **argv)
{
	int	fd;

	if (!check_file_format(argv[1]))
		return (ft_printf("Error\nWrong file format, use .ber\n"), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nCannot open file\n"), 0);
	close(fd);
	if (!map_is_rectangular(argv[1]))
		return (ft_printf("Error\nMap not rectangular\n"), 0);
	if (!is_surrounded_by_walls(argv[1]))
		return (ft_printf("Error\nMap not surrounded by walls\n"), 0);
	if (!has_valid_characters(argv[1]))
		return (ft_printf("Error\nMap characters not valid\n"), 0);
	if (!has_valid_paths(argv[1]))
		return (ft_printf("Error\nNo valid path available\n"), 0);
	return (1);
}

int	check_file_format(char *filename)
{
	if (ft_strlen(filename) <= 4)
		return (0);
	if (ft_strncmp(".ber", filename + (ft_strlen(filename) - 4), 4) == 0)
		return (1);
	return (0);
}

int	map_is_rectangular(char *argv)
{
	char	*line;
	int		line_lenght;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	line_lenght = count_line_lenght_file(line);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		if (line_lenght != count_line_lenght_file(line))
			return (close(fd), free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), free(line), 1);
}

int	is_surrounded_by_walls(char *argv)
{
	int		fd;
	char	*line;
	char	*last_line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	last_line = NULL;
	line = get_next_line(fd);
	if (!line_is_wall(line))
		return (free(line), close(fd), 0);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		if (!(line[0] == '1' && line[count_line_lenght_file(line) - 1] == '1'))
			return (free(line), free(last_line), close(fd), 0);
		if (last_line)
			free(last_line);
		last_line = line;
		line = get_next_line(fd);
	}
	if (!line_is_wall(last_line))
		return (free(last_line), close(fd), 0);
	return (free(last_line), close(fd), 1);
}

int	line_is_wall(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && (line[i] == '1' || line[i] == '\n'))
		i++;
	if (line[i] == 0)
		return (1);
	return (0);
}
