/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:47:18 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/10 14:57:01 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dup_fd(int mod)
{
	static int	fdin;
	static int	fdout;

	if (mod == 1)
	{
		fdin = dup(STDIN_FILENO);
		fdout = dup(STDOUT_FILENO);
	}
	else if (mod == 2)
	{
		dup2(fdin, STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
	}
	else if (mod == 3)
	{
		close(fdin);
		close(fdout);
	}
}
