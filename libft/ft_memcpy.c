/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:35:25 by bregneau          #+#    #+#             */
/*   Updated: 2021/12/19 19:18:54 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (!dst && !src)
		return (NULL);
	tmp1 = (unsigned char *)src;
	tmp2 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		tmp2[i] = tmp1[i];
		i++;
	}
	return (dst);
}
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	uint64_t		*lldst;
	uint64_t		*llsrc;

	lldst = (uint64_t *)dst;
	llsrc = (uint64_t *)src;
	while (n >= 8)
	{
		*lldst++ = *llsrc++;
		n -= 8;
	}
	cdst = (unsigned char *)lldst;
	csrc = (unsigned char *)llsrc;
	while (n--)
		*cdst++ = *csrc++;
	return (dst);
}
