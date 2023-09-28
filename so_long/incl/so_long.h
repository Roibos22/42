/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:13:16 by leon              #+#    #+#             */
/*   Updated: 2023/08/21 14:58:23 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define KEY_UP 119
# define KEY_LEFT 97
# define KEY_DOWN 115
# define KEY_RIGHT 100
# define KEY_ESC 65307
# define MOVE_UP 1
# define MOVE_LEFT 2
# define MOVE_DOWN 3
# define MOVE_RIGHT 4

typedef struct s_coord
{
	int				character;
	int				row;
	int				column;
	struct s_coord	*next;
}	t_coord;

typedef struct s_sprite
{
	int				i;
	int				j;
	char			c;
	void			*image;
	struct s_sprite	*next_sprite;
}	t_sprite;

typedef struct s_window
{
	void			*win_ptr;
	int				height;
	int				width;
	int				rows;
	int				columns;
	int				px_per_sq;
}	t_window;

typedef struct s_game
{
	void			*mlx;
	char			**map;
	t_window		window;
	t_sprite		*sprites;
	int				moves;
}	t_game;

// check_map & helper
int			check_map(char **argv);
int			check_file_format(char *filename);
int			map_is_rectangular(char *argv);
int			is_surrounded_by_walls(char *argv);
int			line_is_wall(char *line);
int			count(char **file, char c);
int			has_valid_characters(char *argv);
int			count_lines_filename(char *argv);
int			count_lines_file(char **file);
int			count_line_lenght_file(char *file);

// has valid paths & helper
int			check_all_paths_poss(char **file, char **copy, \
t_coord *from, t_coord *to);
int			check_path_possible(char **file, int row, \
int column, t_coord *to_coord);
int			check_coords(char **file, int row, int column, t_coord *to_coord);
void		free_coords(t_coord *s, t_coord *e, t_coord *c);
void		free_file(char **file);
int			has_valid_paths(char *argv);
t_coord		*get_all_coords(char **file, char c);
t_coord		*add_coord_to_list(t_coord *head_coord, int row, \
int column, char c);

// debug
void		print_map(char **file);
void		print_coords(t_coord *coord);

// game && init
int			load_game(char *filename);
int			key_hook(int keycode, void *param);
int			collectables_left(t_game *game);
int			move_possible(t_game *game, t_sprite *player, int move);
int			update_window(t_game *game, int move);
t_game		*init_game(char *filename);
char		**read_file(char *filename);
void		prepare_window(t_game *game);
int			close_window(void *param);
int			exit_game(t_game *game, int win);

// sprites & helper
void		add_sprite(t_game *game, char c, int i, int j);
int			load_sprites_from_map(t_game *game);
int			place_sprite(t_game *game, t_sprite *sprite);
int			place_sprites_all(t_game *game);
t_sprite	*update_sprites(t_game *game, t_sprite *sprites, int move);
t_sprite	*get_player_sprite(t_sprite *sprites);
void		add_sprite_to_list(t_game *game, t_sprite *sprite);
t_sprite	*get_sprite_at_pos(t_sprite *sprites, int i, int j);
int			destroy_sprites(t_game *game, t_sprite *sprites);
char		*get_file_path(t_game *game, char c);

#endif
