/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:07:50 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/13 18:31:53 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_dprintf.h"

int	ft_dprint_ptr(int fd, void *ptr)
{
	ft_putstr_fd("0x", fd);
	return (2 + ft_dprint_hexa(fd, (unsigned long)ptr, 'x'));
}
