/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:43:21 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/02/27 18:17:16 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H_
# define FT_STOCK_STR_H_

#include <unistd.h>

typedef	struct	s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
} t_stock_str;

#endif
