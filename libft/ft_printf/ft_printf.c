/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:02:32 by bregneau          #+#    #+#             */
/*   Updated: 2021/12/04 08:22:35 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_parse_arg(char c, va_list ap)
{
	if (c == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (c == 's')
		return (ft_print_str(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(ap, void *)));
	if (c == 'i' || c == 'd')
		return (ft_print_int(va_arg(ap, int)));
	if (c == 'u')
		return (ft_print_uint(va_arg(ap, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_print_hexa(va_arg(ap, unsigned int), c));
	if (c == '%')
		return (ft_print_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_parse_arg(format[++i], ap);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i++], 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
