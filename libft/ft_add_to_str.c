/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:48:26 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/17 15:47:02 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_to_str(char *s1, char *s2, size_t s2_size)
{
	static size_t	size = 1;
	size_t			old_size;
	size_t			new_size;

	old_size = size;
	if (s1)
		new_size = ft_strlen(s1) + s2_size + 1;
	else
	{
		s1 = ft_calloc(1, 1);
		new_size = s2_size + 1;
		size = 1;
		old_size = 1;
	}
	if (size <= new_size)
	{
		while (size < new_size)
			size *= 2;
		s1 = ft_realloc(s1, old_size, size);
		if (s1 == NULL)
			return (NULL);
	}
	ft_strlcat(s1, s2, new_size);
	return (s1);
}
