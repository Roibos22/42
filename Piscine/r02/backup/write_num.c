/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:40:48 by jschott           #+#    #+#             */
/*   Updated: 2023/02/25 14:18:41 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char			*read_file_to_memory(char *filename);
unsigned int	get_file_size(char *filename);
char	*ft_remove_after_whitespace(char *str);
char	*ft_strstr(char *str, char *to_find);
char	*prepare_string(char *str);

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	char	c;

	i = 0;
	c = '0';
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s1[i] < s2[i])
		c = s1[i] - s2[i];
	else if (s1[i] > s2[i])
		c = s1[i] - s2[i];
	else if (s1[i] == s2[i])
		c = 0;
	return (c);
}

void	write_triplet(char *dict, char *trp)
{
	int	i;
	char	tmp[2];

	tmp[0] = '0';
	tmp[1] = '0';
	ft_strncpy(tmp, trp, 1);
	i = 0;
/* write N hundret */
	if (trp[0] > '0')
	{
		tmp[1] = trp[0];
		ft_print_str(ft_remove_after_whitespace(ft_strstr (dict, &tmp[1])));
		ft_print_str(ft_remove_after_whitespace(ft_strstr (dict, "100")));
	}
/*check if the latest two digits are in dict*/
	if (ft_strstr (dict, &trp[1]) != 0)
		ft_print_str(ft_remove_after_whitespace(ft_strstr (dict, &trp[1])));
/*write out last digits*/
	else
	{
		tmp[0] = trp[1];
		tmp[1] = '0';
		if ((trp[1] > '0'))
		{
			ft_print_str(ft_remove_after_whitespace(ft_strstr (dict, tmp)));
			write (1, " ", 1);
		}
		tmp[1] = trp[2];
		if (trp[2] > '0')
			ft_print_str(ft_remove_after_whitespace(ft_strstr (dict, &trp[2])));
	}
}

void	write_number(char *dict, char *str)
{
	char	tmp[3];
	char 	*helper;
	int	i;

	if (len(str) > 3)
		helper = &str[3 - len(str) % 3];
	i = 0;
	while (i < 3)
	{
		tmp[i] = '0';
		i++;
	}
	i = len(str);
/*if the char string is a key in dic, write value*/
	if (ft_strstr (dict, str) == 0)
		ft_print_str(ft_remove_after_whitespace(ft_strstr (dict, str)));
/*Create an char array of length 3 with leading zeros*/
	if (len (str) % 3 == 0)
		ft_strncpy(tmp, str, 3);
	else if (len (str) % 3 == 2)
		ft_strncpy(&tmp[1], str, 2);
	else if (len (str) % 3 == 1)
		ft_strncpy(&tmp[2], str, 1);
/*start spelling the words*/
	write_triplet (dict, tmp);
	if (i > 3 && ft_strcmp(tmp, "000") != 0)
	{
		write (1, " ", 1);
		if (3 < i && i <= 6)
			ft_print_str(ft_remove_after_whitespace(ft_strstr (dict, "1000")));
		if (6 < i && i <= 9)
			ft_print_str(ft_remove_after_whitespace(ft_strstr (dict, "1000000")));
		if (9 < i)
			ft_print_str(ft_remove_after_whitespace(ft_strstr (dict, "1000000000")));
		write (1, " ", 1);
/*RECURSION*/	
		write_number (dict, helper);
	}
}
