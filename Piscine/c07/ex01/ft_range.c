/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:19:30 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/27 14:16:39 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	len;
	int	i;

	len = max - min;
	array = (int *) malloc(len * sizeof(int));
	if (min >= max)
	{
		return (0);
	}
	if (array == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}

/*
#include<stdio.h>
int	main(void)
{
	int min = 10;
	int max = 15;
	int *array = ft_range(min, max);
	int i = 0;

	while (i < (max - min))
	{
			printf("%i ,", array[i]);
			i++;
	}
	return (0);
}
*/