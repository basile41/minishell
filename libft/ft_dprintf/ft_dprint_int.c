/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:09:42 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/13 18:25:19 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_dprint_int(int fd, int i)
{
	char	*a;

	a = ft_itoa(i);
	ft_putstr_fd(a, fd);
	i = ft_strlen(a);
	free(a);
	return (i);
}
