/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:22:28 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/13 18:27:11 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include <stdarg.h>

int	ft_parse_arg(int fd, char c, va_list ap)
{
	if (c == 'c')
		return (ft_dprint_char(fd, va_arg(ap, int)));
	if (c == 's')
		return (ft_dprint_str(fd, va_arg(ap, char *)));
	if (c == 'p')
		return (ft_dprint_ptr(fd, va_arg(ap, void *)));
	if (c == 'i' || c == 'd')
		return (ft_dprint_int(fd, va_arg(ap, int)));
	if (c == 'u')
		return (ft_dprint_uint(fd, va_arg(ap, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_dprint_hexa(fd, va_arg(ap, unsigned int), c));
	if (c == '%')
		return (ft_dprint_percent(fd));
	return (0);
}

int	ft_dprintf(int fd, const char *format, ...)
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
			count += ft_parse_arg(fd, format[++i], ap);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i++], fd);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
