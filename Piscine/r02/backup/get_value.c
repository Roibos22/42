/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:20:24 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/26 19:25:37 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*read_file_to_memory(char *filename);
char	*prepare_string(char *str);
char	*ft_strstr(char *str, char *to_find);
char	*ft_remove_after_whitespace(char *str);

char	*ft_strcpy(char *src, int size)
{	
	int	i;
	char *dest;

	dest = (char*)malloc(size + 1);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		pos++;
	}
	return (pos);
}

char	*get_value(char *key, char *filename)
{
	char	*str;
	char	*prepared_string;
	char	*value;
	char	*return_value;

	str = read_file_to_memory(filename);
	//printf("%s", str);

	prepared_string = prepare_string(str);
	//free(str);
	//printf("%s", str);
	char *newdict = ft_strstr(prepared_string, key);
	//printf("%s", newdict);
	//free(str);
	if (newdict == prepared_string)
	{
		return("Dict Error\n");
	}
	else
	{
		value = ft_remove_after_whitespace(newdict);
		return_value = ft_strcpy(value, ft_strlen(value));
		free(str);
		return(return_value);
	}
}