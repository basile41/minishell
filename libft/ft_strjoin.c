/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:52:39 by bregneau          #+#    #+#             */
/*   Updated: 2021/11/27 14:24:53 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc((size + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, size + 1);
	ft_strlcat(str, s2, size + 1);
	return (str);
}
