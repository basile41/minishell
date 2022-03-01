/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:05:01 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/01 21:34:37 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_process(char *line, char **envp, int fdin)
{
	pid_t	child;
	char	*nextcmd;

	//ft_parse line
	if (/* Il y a un pipe */)
	{
		child = fork();
		if (child == -1)
			ft_put_error(0);//A coder
		if (child)
			ft_process(nextcmd, envp, STDOUT_FILENO);
			
	}
	else
	{
		//Je suis le dernier descendant
	}
	//ft_exec
	exit(0);
}
