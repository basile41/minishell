/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:20:52 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/13 18:26:59 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_dprint_char(int fd, unsigned char c)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_dprint_percent(int fd)
{
	ft_putchar_fd('%', fd);
	return (1);
}
