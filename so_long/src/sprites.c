/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:40:14 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/28 11:18:01 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_sprite(t_game *game, char c, int i, int j)
{
	t_sprite	*new_sprite;
	t_sprite	*current;
	char		*path;

	new_sprite = malloc(sizeof(t_sprite));
	new_sprite->i = i;
	new_sprite->j = j;
	new_sprite->c = c;
	new_sprite->next_sprite = NULL;
	path = get_file_path(game, c);
	new_sprite->image = mlx_xpm_file_to_image(game->mlx, path, \
	&game->window.px_per_sq, &game->window.px_per_sq);
	free(path);
	if (!new_sprite->image) 
		return (perror("mlx_xpm_file_to_image"));
	current = game->sprites;
	if (!current)
		game->sprites = new_sprite;
	else 
	{
		while (current->next_sprite)
			current = current->next_sprite;
		current->next_sprite = new_sprite;
	}
}

int	load_sprites_from_map(t_game *game)
{
	t_sprite	*sprites;
	char		**map;
	int			i;
	int			j;

	sprites = game->sprites;
	map = game->map;
	if (sprites)
		destroy_sprites(game, sprites);
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != 0 && map[i][j] != '\n')
		{
			add_sprite(game, map[i][j], i, j);
			j++;
		}
		j = 0;
		i++;
	}
	while (sprites)
		sprites = sprites->next_sprite;
	return (1);
}

int	place_sprite(t_game *game, t_sprite *sprite)
{
	int	height;
	int	width;

	height = sprite->j * game->window.px_per_sq;
	width = sprite->i * game->window.px_per_sq;
	if (collectables_left(game) == 0 && sprite->c == 'E')
	{
		mlx_destroy_image(game->mlx, sprite->image);
		if (game->window.px_per_sq == 100)
			sprite->image = mlx_xpm_file_to_image(game->mlx, \
			"resc/pokeball_open_100px.xpm", \
			&game->window.px_per_sq, &game->window.px_per_sq);
		else
			sprite->image = mlx_xpm_file_to_image(game->mlx, \
			"resc/pokeball_open_50px.xpm", \
			&game->window.px_per_sq, &game->window.px_per_sq);
	}
	mlx_put_image_to_window(game->mlx, game->window.win_ptr, \
	sprite->image, height, width);
	return (1);
}

int	place_sprites_all(t_game *game)
{
	t_sprite	*sprite;

	sprite = game->sprites;
	while (sprite)
	{
		place_sprite(game, sprite);
		sprite = sprite->next_sprite;
	}
	return (1);
}

t_sprite	*update_sprites(t_game *game, t_sprite *sprites, int move)
{
	t_sprite	*player;
	t_sprite	*head;
	t_sprite	*old;

	head = sprites;
	player = get_player_sprite(sprites);
	add_sprite(game, '0', player->i, player->j);
	if (move == 1)
		player->i--;
	else if (move == 2)
		player->j--;
	else if (move == 3)
		player->i++;
	else
		player->j++;
	while (!(sprites->next_sprite->i == player->i && sprites->next_sprite->j \
	== player->j && sprites->next_sprite->c != 'P')) 
		sprites = sprites->next_sprite;
	old = sprites->next_sprite;
	sprites->next_sprite = sprites->next_sprite->next_sprite;
	mlx_destroy_image(game->mlx, old->image);
	free(old);
	if (move != 1)
		return (head);
	return (head);
}
