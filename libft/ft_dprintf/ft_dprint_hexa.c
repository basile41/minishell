/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:09:09 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/13 18:23:34 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa_hexa(unsigned long n)
{
	unsigned long	nb;
	char			base[17];
	char			tmp[17];
	int				i;

	ft_strlcpy(base, "0123456789abcdef", 17);
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	while (nb)
	{
		nb /= 16;
		i++;
	}
	tmp[i] = '\0';
	while (n)
	{
		tmp[--i] = base[n % 16];
		n /= 16;
	}
	return (ft_strdup(tmp));
}

void	ft_strtoupper(char *str)
{
	while (*str)
	{
		*str = ft_toupper((int)*str);
		str++;
	}
}

int	ft_dprint_hexa(int fd, unsigned long nbr, char c)
{
	char	*hexa;

	hexa = ft_itoa_hexa(nbr);
	nbr = ft_strlen(hexa);
	if (c == 'X')
		ft_strtoupper(hexa);
	ft_putstr_fd(hexa, fd);
	free(hexa);
	return (nbr);
}
