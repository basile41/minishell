/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:02:41 by bregneau          #+#    #+#             */
/*   Updated: 2021/12/19 17:37:23 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*byte;

	byte = b;
	i = 0;
	while (i < len)
		byte[i++] = (unsigned char)c;
	return (b);
}
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*byte;
	uint64_t		*mem;
	uint64_t		set;

	mem = b;
	if (len >= 16)
	{
		set = 0;
		i = -1;
		while (++i < 8)
			set = (set << 8) + (unsigned char)c;
		while (len >= 8)
		{
			*mem++ = set;
			len -= 8;
		}
	}
	i = 0;
	byte = (unsigned char *)mem;
	while (i < len)
		byte[i++] = (unsigned char)c;
	return (b);
}
