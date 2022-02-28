/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:45:01 by bregneau          #+#    #+#             */
/*   Updated: 2021/11/28 19:09:32 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long int	nb;
	char		tmp[12];
	int			i;

	nb = n;
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
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
	return (ft_strdup(tmp));
}
