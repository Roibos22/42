/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:27:58 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/27 18:32:58 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include <stdlib.h>

struct 	s_stock_str	*ft_strs_to_tab(int argc, char *argv[]);
void				ft_show_tab(struct s_stock_str *par);

int	main(void)
{
	char	*strs[4];
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = "Hello";
	str2 = "my name is";
	str3 = "LEON";
	str4 = "!!!";
	strs[0] = str1;
    strs[1] = str2;
    strs[2] = str3;
    strs[3] = str4;

	struct s_stock_str *tab = ft_strs_to_tab(4, strs);
	ft_show_tab(tab);
	free(tab);
	return (0);
}
