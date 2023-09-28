/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:52:02 by leon              #+#    #+#             */
/*   Updated: 2023/08/21 15:34:26 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\n");
		ft_printf("Incorrect arguments [./so_long xxx.ber]\n");
		return (0);
	}
	if (!check_map(argv))
		return (0);
	load_game(argv[1]);
	return (0);
}
