/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:55:35 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/04 18:22:23 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_null(void *ptr)
{
	(void)ptr;
}

void	ft_free_and_exit(int status)
{
	ft_lstfree_env();
	ft_free_toks(&g_data.tok);
	exit(status);
}
