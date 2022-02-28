/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:04:21 by bregneau          #+#    #+#             */
/*   Updated: 2021/12/19 19:44:22 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (!dst && !src)
		return (NULL);
	tmp1 = (unsigned char *)src;
	tmp2 = (unsigned char *)dst;
	i = 0;
	if (tmp1 > tmp2)
	{
		while (i < len)
		{
			tmp2[i] = tmp1[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			tmp2[len] = tmp1[len];
	}
	return (dst);
}
*/

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	uint64_t		*lldst;
	uint64_t		*llsrc;

	if (src > dst)
		return (ft_memcpy(dst, src, n));
	lldst = (uint64_t *)(dst + n - 8);
	llsrc = (uint64_t *)(src + n - 8);
	while (n >= 8)
	{
		*lldst-- = *llsrc--;
		n -= 8;
	}
	cdst = (unsigned char *)lldst;
	csrc = (unsigned char *)llsrc;
	while (n--)
		*cdst-- = *csrc--;
	return (dst);
}
