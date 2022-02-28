/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:14:16 by bregneau          #+#    #+#             */
/*   Updated: 2021/11/26 17:53:26 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (*to_find == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == *to_find)
		{
			ptr = (char *) str + i;
			j = 0;
			while (str[i + j] == to_find[j] && i + j < len)
			{
				j++;
				if (to_find[j] == '\0')
					return (ptr);
			}
			ptr = 0;
		}
		i++;
	}
	return (NULL);
}
