/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_size.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:16:56 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 09:17:07 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
