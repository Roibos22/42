/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <leon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:07:09 by leon              #+#    #+#             */
/*   Updated: 2023/10/04 16:21:56 by leon             ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2);
int	    ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int	    ft_no_newline(const char *s);
int	    clean_res_get_start(char *res);
char	*clean_res(char *res, int bread);
char	*get_full_line(char *res, int bread);
char	*get_next_line(int fd);


#endif