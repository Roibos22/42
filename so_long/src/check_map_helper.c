/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:49:11 by leon              #+#    #+#             */
/*   Updated: 2023/08/28 11:13:40 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count(char **file, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (file[i])
	{
		while (file[i][j])
		{
			if (file[i][j] == c)
				count++;
			j++;
		}
		i++;
		j = 0;
	}
	return (count);
}

int	has_valid_characters(char *argv)
{
	int		fd;
	int		i;
	char	*line;
	char	**file;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			if (!ft_strchr("01PCE", line[i]))
				return (free(line), 0);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	file = read_file(argv);
	if (count(file, 'E') != 1 || count(file, 'P') != 1 || count(file, 'C') < 1)
		return (close(fd), free_file(file), 0);
	return (close(fd), free_file(file), 1);
}

int	count_lines_filename(char *argv)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (close(fd), lines);
}

int	count_lines_file(char **file)
{
	int	i;

	if (!file)
		return (0);
	i = 0;
	while (file[i])
		i++;
	return (i);
}

int	count_line_lenght_file(char *file)
{
	int	i;

	if (!file)
		return (0);
	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	return (i);
}
