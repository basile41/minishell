/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:51:02 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/26 18:23:40 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_utoa(unsigned int n)
{
	unsigned int	nb;
	char			tmp[12];
	int				i;

	nb = n;
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
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

int	ft_print_uint(unsigned int i)
{
	char	*a;

	a = ft_utoa(i);
	ft_putstr_fd(a, 1);
	i = ft_strlen(a);
	free(a);
	return (i);
}
