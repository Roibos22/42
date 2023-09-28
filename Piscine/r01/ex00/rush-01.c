/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:01:54 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/19 17:11:53 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	has_valid_numbers(char *input)
{
	int	i;

	i = 0;
	while (i <= 31)
	{
		if (input[i] >= '1' && input[i] <= '4')
		{	
			i = i + 2;
		}
		else
		{	
			return (0);
		}
	}	
	return (1);
}

int	has_valid_spaces(char *input)
{
	int	i;

	i = 1;
	while (i <= 29)
	{
		if (input[i] != ' ')
		{
			return (0);
		}
		i = i + 2;
	}
	return (1);
}

int	has_valid_lenght(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		i++;
	}
	if (i != 31)
	{
		return (0);
	}
	return (1);
}

int	is_valid(char *input)
{
	if (has_valid_lenght(input) != 1)
	{
		write(1, "Error: The length of the input is not correct\n", 46);
		return (0);
	}
	else if (has_valid_spaces(input) != 1)
	{
		write(1, "Error: Not all spaces are placed correctly\n", 43);
		return (0);
	}
	else if (has_valid_numbers(input) != 1)
	{
		write(1, "Error: Not all numbers are between 1 and 4\n", 43);
		return (0);
	}
	else
	{
		return (1);
	}
}

int	main(int argc, char *argv[])
{	
	int	i;

	if (argc != 2)
	{
		write(1, "Error: Please enter exactly one argument\n", 41);
		return (0);
	}	
	i = is_valid(argv[1]);
	if (i == 0)
	{
		write(1, "Please try again!\n", 18);
	}
	else
	{
		write(1, "The correct solution should be here.\n\n", 38);
		write(1, "Our idea was to brute force ourselve through the\n", 49);
		write(1, "rows and columns while setting up a checking mechanism\n", 55);
		write(1, "to correct mistakes when we find one.\n", 38);
		write(1, "However we were not able to do it :(\n", 37);
	}
}
