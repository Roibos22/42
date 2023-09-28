/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_modifications.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:26:28 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/26 19:02:34 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

unsigned int	get_file_size(char *filename);

char	*prepare_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ':' || str[i] == ' ')
			str[i] = ' ';
		i++;
	}
	return (str);
}


char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (*to_find == '\0')
	{
		return (str);
	}	
	i = 0;
	while (str[i])
	{	
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0' && str[i + j + 1] == ' ')
			{
				return (&str[i + j + 1]);
			}
			j++;
		}
		i++;
	}
	return (str);
}

char	*ft_remove_after_whitespace(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
	while (str[i] != '\0')
	{	
		while (str[i] == ' ')
		{
			i++;
		}
		j = i;
		while (str[i] != '\n' && str [i] != '\0')
		{
			i++;
		}
		str[i] = '\0';
		return (&str[j]);
	}
	return (str);
}


