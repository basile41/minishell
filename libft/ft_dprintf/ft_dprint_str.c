/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:34:41 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/13 18:32:03 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_dprint_str(int fd, char *str)
{
	if (!str)
		return (ft_dprint_str(fd, "(null)"));
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
