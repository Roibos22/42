/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:20:04 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 11:13:31 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"








int main(void)
{
	unsigned char *just_map;
	unsigned char **result;
	char delimiter; 
	


	
	just_map = read_file_to_memory("example_file");
	delimiter = '\n';
	if (just_map[0] == '\0')
	{
		return (0);
	}
	else
	{
		result = split_string(just_map + 5, delimiter);
	}

	free(result);
	free(just_map);
	return(0);
}


/*
int	main(void)
{	
	char *just_map = read_file_to_memory("example_file");
	int no_rows = just_map[0] - '0';
	// use putnbr herre!!!
	int no_columns = count_col(just_map + 5);
	char** result;
	char **map_array = (char **) malloc((no_columns * no_rows * sizeof(char)) + 1);
	char delimiter = '\n';

	if (just_map[0] == '\0')
	{
		return (0);
	}
	else
	{
		result = split_string(just_map + 5, delimiter);
	}
	
	for (int i = 0; result[i] != NULL; i++) {
		printf("%s\n", result[i]);
		free(result[i]);
	}
	

	
	char *test_map[] = {
		"..................o....o...\0",
		"....o......................\0",
		"............o..............\0",
		"........o..................\0",
		"....o......................\0",
		"...............o...........\0",
		"...........................\0",
		"......o............o.......\0",
		"..o.......o................\0",
		NULL,
	};

	char	*test_map2[] = {
		"o.oooo\0",
		".o....\0",
		"......\0",
		NULL,
	};
	//displayStrings(test_array, 9);
	//ft_find_biggest_square(test_array, 9);
	

	struct point_struct max_point = ft_find_biggest_square(result, no_rows);
	print_map(result, max_point);
	free(result);
	free(just_map);
	return (0);
}
*/
