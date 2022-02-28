/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:07:50 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/26 18:23:33 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	ft_putstr_fd("0x", 1);
	return (2 + ft_print_hexa((unsigned long)ptr, 'x'));
}
