/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:19:37 by bregneau          #+#    #+#             */
/*   Updated: 2021/11/26 17:39:16 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	r;

	i = ft_strlen(dst);
	j = 0;
	if (i > dstsize)
		i = dstsize;
	r = i + ft_strlen(src);
	if (dstsize == 0)
		return (r);
	while (src[j] && i < dstsize - 1)
	{
		dst[i++] = src[j++];
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (r);
}
