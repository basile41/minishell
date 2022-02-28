/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:20:52 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/26 18:23:13 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_char(unsigned char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
