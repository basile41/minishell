/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:19:14 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/16 20:29:48 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t size)
{
	char	*newptr;

	if (ptr == NULL)
		return (malloc(size));
	newptr = malloc(size);
	if (newptr == NULL)
		return (NULL);
	if (old_size < size)
		size = old_size;
	ft_memcpy(newptr, ptr, size);
	free(ptr);
	return (newptr);
}
