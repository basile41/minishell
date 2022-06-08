/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:47:18 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/08 14:22:32 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_dup_fd(int b)
// {
// 	static int	fdin;
// 	static int	fdout;

// 	if (b)
// 	{
// 		fdin = dup(STDIN_FILENO);
// 		fdout = dup(STDOUT_FILENO);
// 	}
// 	else
// 	{
// 		dup2(fdin, STDIN_FILENO);
// 		dup2(fdout, STDOUT_FILENO);
// 		close(fdin);
// 		close(fdout);
// 	}
// }


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
