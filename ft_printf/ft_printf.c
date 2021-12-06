/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:32:09 by joao              #+#    #+#             */
/*   Updated: 2021/11/30 16:46:54 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(int i, const char *format, va_list arg_ptr);

int	ft_printf(const char *format, ...)
{
	int		i;
	int		size;
	va_list	arg_ptr;

	size = 0;
	i = 0;
	va_start(arg_ptr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			size += ft_check(i, format, arg_ptr);
			i++;
		}
		else
		{
			size++;
			ft_putchar(format[i]);
		}
	i++;
	}
	va_end(arg_ptr);
	return (size);
}

int	ft_check(int i, const char *f, va_list arg_ptr)
{
	int	s;

	s = 0;
	if (f[i] == '%' && f[i + 1] == '%')
		s += ft_putchar('%');
	if (f[i] == '%' && f[i + 1] == 'c')
		s += ft_putchar(va_arg(arg_ptr, int));
	if (f[i] == '%' && f[i + 1] == 's')
		s += ft_putstr(va_arg(arg_ptr, char *));
	if ((f[i] == '%' && f[i + 1] == 'd')
		|| (f[i] == '%' && f[i + 1] == 'i'))
		s += ft_putnbr(va_arg(arg_ptr, int));
	if (f[i] == '%' && f[i + 1] == 'p')
	{
		s += ft_putstr("0x");
		s += ft_base(va_arg(arg_ptr, unsigned long), "0123456789abcdef", 16);
	}
	if (f[i] == '%' && f[i + 1] == 'x')
		s += ft_ubase(va_arg(arg_ptr, unsigned int), "0123456789abcdef", 16);
	if (f[i] == '%' && f[i + 1] == 'X')
		s += ft_ubase(va_arg(arg_ptr, unsigned int), "0123456789ABCDEF", 16);
	if (f[i] == '%' && f[i + 1] == 'u')
		s += ft_ubase(va_arg(arg_ptr, unsigned int), "0123456789", 10);
	return (s);
}
