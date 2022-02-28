/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:56:06 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/10 13:56:34 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int	nb;
	char		tmp[12];
	int			i;

	nb = n;
	i = 0;
	if (n == 0)
		ft_putchar('0');
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
	ft_putstr(tmp);
}
