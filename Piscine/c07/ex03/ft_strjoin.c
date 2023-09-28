/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:44:30 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/27 14:15:20 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{	
	int	i;

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
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_get_full_length(char **strs, int size, int sep_l)
{
	int length;
	int	i;

	length = 0;
	i = 0;
	while(i < size)
	{
		length = length + ft_strlen(strs[i]);
		if (i != size - 1)
			length = length + sep_l;
		i++;
	}
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*f_string;
	int		tab_pos;
	int		f_str_p;
	int		sep_pos;
	int		length;

	if (size == 0)
		return ((char *) malloc(sizeof(char)));
	// malloc auf jeden fall falsch

	length = ft_get_full_length(strs, size, ft_strlen(sep));
	f_string = (char *) malloc (sizeof(char) * length);
	tab_pos = 0;
	sep_pos = 0;
	f_str_p = 0;
	while (tab_pos < size)
	{	
		f_string[f_str_p] = *ft_strcpy(&f_string[f_str_p], strs[tab_pos]);
		f_str_p = f_str_p + ft_strlen(strs[tab_pos]);
		if (tab_pos != size - 1 && sep[sep_pos] != '\0')
		{
			f_string[f_str_p] = *ft_strcpy(&f_string[f_str_p], &sep[sep_pos]);
			f_str_p = f_str_p + ft_strlen(&sep[sep_pos]);
		}
		sep_pos = 0;
		tab_pos++;
	}
	f_string[f_str_p] = '\0';
	return (f_string);
}


#include <stdio.h>

int main(void)
{
	char *tab[4];
	tab[0] = "ABC";
	tab[1] = "DEF";
	tab[2] = "GHI";
	tab[3] = "JKL";
	printf("%s", ft_strjoin(4, tab, "&"));
	return (0);
}

