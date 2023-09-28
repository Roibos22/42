/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:51:03 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/28 19:22:10 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int	count_lines(char *str)
{
	int	i;
	int	k;
	
	i = 0;
	k = 0;
	while (str[i] )
	{
		if (str[i] == '\n')
			k++;
		i++;
	}
	return (k);
}

int	count_col(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((src[i] != '\0') && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char** split_string(char* map, char delimiter) {
    char** result = NULL;
    int count = 0;
    char* start = map;
    char* end = map;

    /* Count how many elements will be extracted */
    while (*end) {
        if (*end == delimiter) {
            count++;
        }
        end++;
    }
    count++;

    /* Allocate memory for array of pointers */
    result = malloc(sizeof(char*) * count);
    if (result == NULL) {
        return NULL;
    }

    /* Extract substrings */
    int i = 0;
    while (*start) {
        end = start;
        while (*end && *end != delimiter) {
            end++;
        }
        int len = end - start;
        result[i] = malloc(sizeof(char) * (len + 1));
        if (result[i] == NULL) {
            return NULL;
        }
        strncpy(result[i], start, len);
        result[i][len] = '\0';
        i++;
        start = end + 1;
    }
    result[i] = NULL;

    return result;
}

int main(void)
{
    char *complete_map = read_file_to_memory("example_file");
    char *just_map = read_file_to_memory("example_file");
    int no_rows = count_lines(just_map + 5);
    int no_columns = count_col(just_map + 5);
    //printf("%s", just_map + 5);
    printf("%i\n", no_columns);
    printf("%i\n", no_rows);

    char **map_array = (char **) malloc((no_columns * no_rows * sizeof(char)) + 1);

    char delimiter = '\n';
    char** result = split_string(just_map + 5, delimiter);

    printf("%s\n\n", result[2]);

    for (int i = 0; result[i] != NULL; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

}



