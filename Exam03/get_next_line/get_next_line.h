/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <leon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:07:09 by leon              #+#    #+#             */
/*   Updated: 2023/10/03 15:15:28 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char  *get_next_line(int fd);

int     ft_no_newline(char *s);
char    *get_line(char *res, int bread);
char    *clean_res(char *res, int bread);

// UTILS

size_t ft_strlen_to(const char *s, char c);
char    *ft_strdup(const char *s);
char *ft_strjoin(char *s1, const char *s2);

#endif