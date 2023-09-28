/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_to_memory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:17:24 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 11:11:01 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned char	*read_file_to_memory(char *filename)
{
	unsigned char	*buffer;
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
	//buffer[bytes_read + 1] = '\0';
	close(fd);
	return (buffer);
}