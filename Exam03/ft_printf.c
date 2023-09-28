/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:51:44 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/09/21 11:53:25 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdarg.h>

int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	put_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (put_str("(null)"));
	while (*str)
	{
		count += put_char(*str);
		str++;
	}
	return (count);
}

int	put_digit(long long int number, int base)
{
	char	*hexadecimal = "0123456789abcdef";
	int count = 0;

	if (number < 0)
	{
		number *= -1;
		count += put_char('-');
	}
	if (number >= base)
		count += put_digit((number / base), base);
	count += write(1, &hexadecimal[number % base], 1);
	return(count);
}

int	printf_cases(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 's')
		count += put_str(va_arg(args, char *));
	else if (*format == 'd')
		count += put_digit(va_arg(args, int), 10);
	else if (*format == 'x')
		count += put_digit(va_arg(args, unsigned int), 16);
	else if (*format == '%')
		count += put_char('%');
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
			count += put_char(*format);
		format++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int main(void)
{
	int r = 0;
	int s = 0;
	
	r += printf("%d\n", 0);
	s += ft_printf("%d\n", 0);
	r += printf("%d\n", 42);
	s += ft_printf("%d\n", 42);
	r += printf("%d\n", 1);
	s += ft_printf("%d\n", 1);
	r += printf("%d\n", 5454);
	s += ft_printf("%d\n", 5454);
	r += printf("%d\n", (int)2147483647);
	s += ft_printf("%d\n", (int)2147483647); 
	
	r += printf("%d\n", (int)2147483648);
	s += ft_printf("%d\n", (int)2147483648);
	r += printf("%d\n", (int)-2147483648);
	s += ft_printf("%d\n", (int)-2147483648);
	
 	r += printf("%d\n", (int)-2147483649);
	s += ft_printf("%d\n", (int)-2147483649); 
	r += printf("%x\n", 0);
	s += ft_printf("%x\n", 0);
	r += printf("%x\n", 42);
	s += ft_printf("%x\n", 42);
	r += printf("%x\n", 1);
	s += ft_printf("%x\n", 1);
	r += printf("%x\n", 5454);
	s += ft_printf("%x\n", 5454);
	
	r += printf("%x\n", (int)2147483647);
	s += ft_printf("%x\n", (int)2147483647);
	
	r += printf("%x\n", (int)2147483648);
	s += ft_printf("%x\n", (int)2147483648);
	r += printf("%x\n", (int)-2147483648);
	s += ft_printf("%x\n", (int)-2147483648);
	

	r += printf("%x\n", (int)0xFFFFFFFF);
	s += ft_printf("%x\n", (int)0xFFFFFFFF);

	r += printf("%x\n", (int)-2147483649);
	s += ft_printf("%x\n", (int)-2147483649);
	r += printf("%s\n", "");
	s += ft_printf("%s\n", "");
	r += printf("%s\n", "toto");
	s += ft_printf("%s\n", "toto");
	r += printf("%s\n", "wiurwuyrhwrywuier");
	s += ft_printf("%s\n", "wiurwuyrhwrywuier");
	r += printf("%s\n", NULL);
	s += ft_printf("%s\n", NULL);
	r += printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	s += ft_printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);

	r += printf("%d%x%d%x%d%x%d%x\n", 0, 0, 0, 0, 42, 42, 42, 42);
	s += ft_printf("%d%x%d%x%d%x%d%x\n", 0, 0, 0, 0, 42, 42, 42, 42);
	r += printf("%d%x%d%x%d%x%d%x\n", 0, 0, 0, 0, 42, 42, 42, 42);
	s += ft_printf("%d%x%d%x%d%x%d%x\n", 0, 0, 0, 0, 42, 42, 42, 42);
	r += printf("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 0, 0, 42, 42, 42, 42);
	s += ft_printf("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 0, 0, 42, 42, 42, 42);
 
	r += printf("%s%s%s%s\n", "", "", "toto", "toto");
	s += ft_printf("%s%s%s%s\n", "", "", "toto", "toto");
	r += printf("-%s-%s-%s-%s-\n", "", "", "toto", "toto");
	s += ft_printf("-%s-%s-%s-%s-\n", "", "", "toto", "toto");

	printf("written: %d\n", r);
	printf("written: %d\n", s);
}