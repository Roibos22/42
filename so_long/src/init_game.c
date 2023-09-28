/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:40:19 by leon              #+#    #+#             */
/*   Updated: 2023/08/21 16:35:24 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(char *filename)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (0);
	game->map = read_file(filename);
	game->moves = 0;
	game->sprites = NULL;
	prepare_window(game);
	load_sprites_from_map(game);
	place_sprites_all(game);
	return (game);
}

char	**read_file(char *filename)
{
	int		fd;
	int		i;
	char	**array;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	array = malloc((count_lines_filename(filename) + 1) * sizeof(char *));
	line = get_next_line(fd);
	while (line)
	{
		array[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	array[i] = NULL;
	close(fd);
	return (array);
}

void	prepare_window(t_game *game)
{
	t_window	window;

	window.rows = count_lines_file(game->map);
	window.columns = count_line_lenght_file(game->map[0]);
	if (window.rows <= 9 && window.columns <= 15)
		window.px_per_sq = 100;
	else
		window.px_per_sq = 50;
	window.width = window.columns * window.px_per_sq;
	window.height = window.rows * window.px_per_sq;
	window.win_ptr = mlx_new_window(game->mlx, window.width, \
	window.height, "POKEMON");
	if (window.win_ptr == NULL)
		return (free(window.win_ptr));
	game->window = window;
}

int	close_window(void *param)
{
	t_game	*game;

	game = param;
	exit_game(game, 0);
	return (0);
}

int	exit_game(t_game *game, int win)
{
	if (win)
	{
		game->moves++;
		ft_printf("Moves: %i\n", game->moves);
	}
	free_file(game->map);
	destroy_sprites(game, game->sprites);
	mlx_clear_window(game->mlx, game->window.win_ptr);
	mlx_destroy_window(game->mlx, game->window.win_ptr);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(0);
	return (0);
}
