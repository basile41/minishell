/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 06:12:01 by bregneau          #+#    #+#             */
/*   Updated: 2021/12/06 06:12:18 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
