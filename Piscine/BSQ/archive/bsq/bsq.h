/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 08:58:06 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/03/01 10:55:57 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H_
# define BSQ_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef	struct	point_struct
{
	int		x;
	int		y;
	int		value;
} point_struct;

int				count_col(char *str);
int				count_lines(char *str);
void 			displayStrings (char* map[], int numlines);
int				find_biggest_square_of_pos(char *map[], point_struct p);
point_struct	ft_find_biggest_square(char* map[], int numLines);
char			*ft_append_char(char *dest, char src);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				get_columns(char *map[]);
unsigned int	get_file_size(char *filename);
int				get_rows(char *map[]);
void			print_map(char *map[], point_struct p);
void			print_point(point_struct p);
unsigned char	*read_file_to_memory(char *filename);
unsigned char			**split_string(char* map, char delimiter);
char			validate_square(char *map[], point_struct p, int length);
char 			validate_string(char *str, char c);

#endif