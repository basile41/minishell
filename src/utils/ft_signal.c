/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:36:05 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/10 17:37:32 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handler1(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\n ", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_handler2(int signum)
{
	(void)signum;
}

void	ft_handler_hd(int signum)
{
	(void)signum;
	close(STDOUT_FILENO);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	// write(STDOUT_FILENO, "\n ", 1);
	// rl_replace_line("", 1);
}

void	ft_signal1(void)
{
	signal(SIGINT, ft_handler1);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_signal2(void)
{
	signal(SIGINT, ft_handler2);
}
