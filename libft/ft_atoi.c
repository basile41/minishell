/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:36:46 by bregneau          #+#    #+#             */
/*   Updated: 2021/11/26 15:18:34 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				s;
	char			*a;

	a = (char *)str;
	while (ft_isspace(*a))
		a++;
	s = 1;
	if (*a == '-')
	{
		a++;
		s = -1;
	}
	else if (*a == '+')
		a++;
	i = 0;
	while (ft_isdigit(*a))
	{
		i = i * 10 + *a - '0';
		a++;
	}
	return (i * s);
}
