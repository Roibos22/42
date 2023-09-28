/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:35:33 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/26 16:10:10 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include<stdio.h>

unsigned int	get_file_size(char *filename)
{
	int				fd;
	char			*buff[1];
	unsigned int	file_size;

	file_size = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, buff, 1))
	{
		file_size ++;
	}
	close (fd);
	return (file_size);
}

char	*read_file_to_memory(char *filename)
{
	char			*buffer;
	int				fd;
	unsigned int	bytes_read;

	fd = open(filename, O_RDONLY);
	buffer = malloc((get_file_size(filename) + 1) * sizeof(char));
	if (!buffer)
	{
		close(fd);
		return (NULL);
	}
	bytes_read = read(fd, buffer, get_file_size(filename));
	if (bytes_read < 0)
	{
		free(buffer);
		close(fd);
		return (NULL);
	}
	buffer[bytes_read + 1] = '\0';
	close(fd);
	return (buffer);
}
