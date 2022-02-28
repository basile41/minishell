/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:21:37 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/13 22:52:30 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	size;
	size_t	i;
	char	*dst;

	size = ft_strlen(s1);
	if (size > n)
		size = n;
	dst = malloc((size + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	str_count(char *str, char c)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (*str)
	{
		if (*str != c && b == 0)
		{
			b = 1;
			i++;
		}
		else if (*str == c)
			b = 0;
		str++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*ptr;
	size_t	i;
	size_t	size;

	size = str_count((char *)s, c);
	strs = malloc((size + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s == c)
		s++;
	while (i < size)
	{
		ptr = (char *)s;
		while (*s && *s != c)
			s++;
		strs[i] = ft_strndup(ptr, s - ptr);
		while (*s == c)
			s++;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
