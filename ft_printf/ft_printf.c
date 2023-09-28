/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:46:58 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/07/12 14:41:29 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_cases(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_put_char(va_arg(args, int));
	else if (*format == 's')
		count += ft_put_str(va_arg(args, char *));
	else if (*format == 'p')
		count += ft_put_ptr(va_arg(args, unsigned long long));
	else if (*format == 'i' || *format == 'd')
		count += ft_put_nbr(va_arg(args, int));
	else if (*format == 'u')
		count += ft_put_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		count += ft_put_nbr_hex(va_arg(args, int), *format);
	else if (*format == '%')
		count += ft_put_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += printf_cases(format, args);
		}
		else
			count += ft_put_char(*format);
		format++;
	}
	va_end(args);
	return (count);
}

#include<stdio.h>

int main(void)
{
	ft_printf("NULL %s NULL", NULL);
	printf("NULL %s NULL", NULL);
}