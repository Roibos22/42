/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:19:30 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/27 14:16:16 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	*buffer;
	int	i;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	buffer = (int *) malloc(len * sizeof(int));
	if (!buffer)
	{
		*range = 0;
		return (-1);
	}
	*range = buffer;
	i = 0;
	while (min < max)
	{
		buffer[i] = min;
		min++;
		i++;
	}
	return (len);
}


#include<stdio.h>

int	main(void)
{
	int min = 10;
	int max = 11;
	int *array;
	int size = ft_ultimate_range(&array, min, max);
	int i = 0;
	
	printf("%i\n", size);
	while (i < size)
	{
			printf("%i,", array[i]);
			i++;
	}
	return (0);
}
