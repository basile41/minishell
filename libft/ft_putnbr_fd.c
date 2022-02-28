/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:30:29 by bregneau          #+#    #+#             */
/*   Updated: 2021/11/29 17:46:44 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		tmp[12];
	int			i;

	nb = n;
	i = 0;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (nb < 0)
	{
		tmp[i++] = '-';
		nb = -nb;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	tmp[i] = '\0';
	while (nb)
	{
		tmp[--i] = nb % 10 + '0';
		nb /= 10;
	}
	ft_putstr_fd(tmp, fd);
}
