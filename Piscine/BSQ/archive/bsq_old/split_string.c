/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:19:16 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 09:54:01 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char** split_string(char* map, char delimiter) 
{
	char	**result = NULL;
	int		count = 0;
	char	*start = map;
	char	*end;
	int		i;

	i = 0;

	if (map == NULL)
		return (NULL);

	end = &map[0];

	/* Count how many elements will be extracted */
	while (end[i] != '\0') {
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
	i = 0;
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
		ft_strncpy(result[i], start, len);
		result[i][len] = '\0';
		i++;
		start = end + 1;
	}
	result[i] = NULL;

	return result;
}