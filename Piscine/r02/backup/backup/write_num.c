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

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return i;
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
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
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

// PLACEHOLDER FUNCTION THAT RETURNS A VLAUE STRING FOR A KEY STRING
char *value (char *key)
{
	if (ft_strcmp(key, "0") == 0)
		return ("zero");
	if (ft_strcmp(key, "3") == 0)
		return ("three");
	if (ft_strcmp(key, "30") == 0)
		return ("thirty");
	if (ft_strcmp(key, "100") == 0)
		return ("hundred");
	if (ft_strcmp(key, "1000") == 0)
		return ("thousand");
	if (ft_strcmp(key, "1000000") == 0)
		return ("million");
	if (ft_strcmp(key, "1000000000") == 0)
		return ("billion");
	if (ft_strcmp(key, "123") == 0)
		return ("I know this one");
	if (ft_strcmp(key, "1") == 0)
		return ("one");
	else
		return ("error");
}

void	write_triplet(char *trp)
{
	int	i;
	char	tmp[2];

	tmp[0] = '0';
	tmp[1] = '0';
	ft_strncpy(tmp, trp, 1);
	i = 0;
/* write N hundret*/
	if (trp[0] > '0')
	{
		tmp[1] = trp[0];
		ft_print_str(value (&tmp[1]));
		write (1, " ", 1);		//SPACE
		ft_print_str(value ("100"));
		write (1, " ", 1);		//SPACE
	}
/*check if the latest two digits are in dict*/
	if (ft_strcmp("error", value(&trp[1])) != 0)
	{
		ft_print_str(value (&trp[1]));
	}
/*write out last digits*/
	else 
	{
		tmp[0] = trp[1];
		tmp[1] = '0';
		if ((trp[1] > '0'))
		{
			ft_print_str(value (tmp));
			write (1, " ", 1);		//SPACE
		}
		tmp[1] = trp[2];
		if (trp[2] > '0')
			ft_print_str(value (&tmp[2]));
	}
}

void	write_number(char *str)
{
	char	tmp[3];
	int	i;
	
	i = 0;
	while (i < 3)
	{
		tmp[i] = '0';
		i++;
	}
/*if the char string is a key in dic, write value*/
	if (ft_strcmp(str, value(str)) == 0)
		ft_print_str(value (str));
/*
check if string length is multiple of three
if not add preceeding 0 until it is

	else if (len(str) % 3 == 1)
		tmp[2] = str[0];
	else if (len(str) % 3 == 2)
	{
		tmp[1] = str[0];
		tmp[2] = str[1];
	}
	else if (len(str) % 3 == 0)
	{
		tmp[0] = str[0];
		tmp[1] = str[1];
		tmp[2] = str[2];
	}
*/	
	else
	{
		if (len(str) <= 3)
			write_triplet (str);
		else if (3 < len(str) && len(str) <= 6)
		{
			write_triplet (&str[0]);
			ft_print_str(value ("1000"));
			write (1, " ", 1);		//SPACE
			write_number (&str[3]);
		}
		else if (6 < len(str) && len(str) <= 9)
		{
			write_triplet (&str[0]);
			ft_print_str(value ("1000000"));
			write (1, " ", 1);		//SPACE
			write_number (&str[3]);
		}
		else if (len(str) > 9)
		{
			write_triplet (&str[0]);
			ft_print_str(value ("1000000000"));
			write (1, " ", 1);		//SPACE
			write_number (&str[3]);
		}
	}

}

#include <stdio.h>
int	main(void)
{
	char src[] = "933";
	char dest[] = "0";

//printf("%s\n", ft_strncpy(dest, src, 1));
	write_number("333");
	write (1, "\n", 1);
/*	write_triplet("330");
	write (1, "\n", 1);
	write_triplet("303");
	write (1, "\n", 1);
	write_triplet("300");
	write (1, "\n", 1);
	write_triplet("033");
	write (1, "\n", 1);
	write_triplet("030");
	write (1, "\n", 1);
	write_triplet("003");
	write (1, "\n", 1);
	write_triplet("000");
	write (1, "\n", 1);
	write_triplet("123");
	write (1, "\n", 1);
	write_triplet("001");
*/	return (1);
}
