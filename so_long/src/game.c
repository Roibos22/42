/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:54:39 by leon              #+#    #+#             */
/*   Updated: 2023/08/22 13:10:57 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_game(char *filename)
{
	t_game	*game;

	game = init_game(filename);
	mlx_key_hook(game->window.win_ptr, *key_hook, game);
	mlx_hook(game->window.win_ptr, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	return (1);
}

int	key_hook(int keycode, void *param)
{
	t_game		*game;
	t_sprite	*player;

	game = (t_game *)param;
	player = get_player_sprite(game->sprites);
	if (keycode == KEY_ESC)
		return (exit_game(game, 0));
	if (keycode == KEY_UP && move_possible(game, player, MOVE_UP))
		update_window(game, MOVE_UP);
	else if (keycode == KEY_LEFT && move_possible(game, player, MOVE_LEFT))
		update_window(game, MOVE_LEFT);
	else if (keycode == KEY_DOWN && move_possible(game, player, MOVE_DOWN))
		update_window(game, MOVE_DOWN);
	else if (keycode == KEY_RIGHT && move_possible(game, player, MOVE_RIGHT))
		update_window(game, MOVE_RIGHT);
	return (1);
}

int	collectables_left(t_game *game)
{
	t_sprite	*sprite;

	sprite = game->sprites;
	while (sprite->next_sprite)
	{
		if (sprite->c == 'C')
			return (1);
		sprite = sprite->next_sprite;
	}
	return (0);
}

int	move_possible(t_game *game, t_sprite *player, int move)
{
	int			new_i;
	int			new_j;
	t_sprite	*sprite;

	new_i = player->i;
	new_j = player->j;
	if (move == MOVE_UP)
		new_i--;
	else if (move == MOVE_LEFT)
		new_j--;
	else if (move == MOVE_DOWN)
		new_i++;
	else if (move == MOVE_RIGHT)
		new_j++;
	sprite = get_sprite_at_pos(game->sprites, new_i, new_j);
	if (sprite->c == '1')
		return (0);
	if (sprite->c == 'E')
	{
		if (collectables_left(game) == 0)
			return (exit_game(game, 1));
		return (0);
	}
	return (1);
}

int	update_window(t_game *game, int move)
{
	char	**map;

	map = game->map;
	game->sprites = update_sprites(game, game->sprites, move);
	place_sprites_all(game);
	game->moves++;
	ft_printf("Moves: %i\n", game->moves);
	return (1);
}
