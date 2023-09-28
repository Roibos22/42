/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 10:37:53 by jschott           #+#    #+#             */
/*   Updated: 2023/02/26 19:22:27 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
expects a string of numeral characters and returns it as int
If there's a non numeral character it writes "Error" and returns -1
*/
int	is_int(char *str)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
			nb = nb * 10 + str[i] - 48;
		else
		{
			write (1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (nb);
}

#include <stdio.h> // REMOVE BEFORE SUBMISSION

/*
int	main(int argc, char **argv)
{

	if (argc == 2 && is_int (argv[1] >= 0))
		write_out_num(is_int(argv[1]));	//RUN FUNCTION THAT WRITES NUMBER
	if (argc == 3 && is_int (argv[2] >= 0))
		update_dict (argv[2], argv[1])	//RUN FUNCTION
	else
		write (1, "Error\n", 6);
	return (1);
}
*/
#include <stdlib.h>

char	*get_value(char *key, char *filename);
char	*read_file_to_memory(char *filename);
char	*prepare_string(char *str);
char	*ft_remove_after_whitespace(char *str);
char	*ft_strstr(char *str, char *to_find);

int	main(int argc, char *argv[])
{
	char	*filename = "numbers.dict";
	char	*value;

	if (argc == 2)
	{
		filename = "numbers.dict";
		value = get_value(argv[1], filename);
		printf("%s\n", value);
		free(value);
	}
	return (0);
}
