/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:16:42 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/13 18:22:50 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include "../libft.h"
# include <stdarg.h>

int	ft_dprint_char(int fd, unsigned char c);
int	ft_dprint_str(int fd, char *str);
int	ft_dprint_ptr(int fd, void *ptr);
int	ft_dprint_int(int fd, int i);
int	ft_dprint_uint(int fd, unsigned int i);
int	ft_dprint_hexa(int fd, unsigned long i, char c);
int	ft_dprint_percent(int fd);

#endif
