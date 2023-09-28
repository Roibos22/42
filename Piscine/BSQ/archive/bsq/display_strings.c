/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:07:52 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 09:25:08 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void displayStrings (char* map[], int numlines) 
{
	int	i;

	i = 0;
	while (i < numlines)
	{
		write(1, map[i], ft_strlen(map[i]));
		write(1, "\n", 1); // add a newline after each string
		i++;
	}
}