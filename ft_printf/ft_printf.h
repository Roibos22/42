/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:59:20 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/05/15 12:34:28 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
//# include <stdlib.h>
//# include <stdio.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_put_nbr_hex(int nbr, char flag);
int		ft_put_char(char c);
int		ft_put_str(char *str);
int		ft_put_ptr(unsigned long long n);
int		ft_put_nbr(int n);
int		ft_write_ptr(uintptr_t num);
int		ft_put_unsigned(unsigned int n);
void	ft_itoa(unsigned int n);

#endif