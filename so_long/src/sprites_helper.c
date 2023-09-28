/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:40:53 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/28 11:15:09 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	*get_player_sprite(t_sprite *sprites)
{
	while (sprites->c != 'P')
		sprites = sprites->next_sprite;
	return (sprites);
}

void	add_sprite_to_list(t_game *game, t_sprite *sprite)
{
	t_sprite	*current;

	current = game->sprites;
	if (!current)
		game->sprites = sprite;
	else
	{
		while (current->next_sprite)
			current = current->next_sprite;
		current->next_sprite = sprite;
	}
}

t_sprite	*get_sprite_at_pos(t_sprite *sprites, int i, int j)
{
	while (!(sprites->i == i && sprites->j == j))
		sprites = sprites->next_sprite;
	return (sprites);
}

int	destroy_sprites(t_game *game, t_sprite *sprites)
{
	t_sprite	*next;

	next = sprites->next_sprite;
	while (sprites)
	{
		mlx_destroy_image(game->mlx, sprites->image);
		free(sprites);
		sprites = next;
		next = sprites->next_sprite;
	}
	return (1);
}

char	*get_file_path(t_game *game, char c)
{
	char	*res;

	if (game->window.px_per_sq == 100)
		res = "_100px.xpm";
	else
		res = "_50px.xpm";
	if (c == 'P')
		return (ft_strjoin("resc/arcanine", res));
	else if (c == 'E')
		return (ft_strjoin("resc/pokeball", res));
	else if (c == 'C')
		return (ft_strjoin("resc/fire", res));
	else if (c == '1')
		return (ft_strjoin("resc/tree", res));
	else
		return (ft_strjoin("resc/grass", res));
}
