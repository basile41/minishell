/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:52:21 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/26 18:23:57 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);

int	ft_print_char(unsigned char c);
int	ft_print_str(char *str);
int	ft_print_ptr(void *ptr);
int	ft_print_int(int i);
int	ft_print_uint(unsigned int i);
int	ft_print_hexa(unsigned long i, char c);
int	ft_print_percent(void);

#endif
