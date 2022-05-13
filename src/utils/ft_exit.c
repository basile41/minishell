/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:55:35 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/13 12:04:17 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_and_exit(int status)
{
	ft_lstfree_env();
	ft_free_toks(&g_data.tok);
	exit(status);
}

void	ft_exit_perror(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}
