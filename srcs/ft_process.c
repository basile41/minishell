/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:05:01 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/03 18:26:35 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit_error(char *error_type)
{
	perror(error_type);
	exit(EXIT_FAILURE);
}

void	ft_fork(t_process *p)
{
	if (pipe(p->pipefd))
		ft_exit_error("pipe");
	p->child = fork();
	if (p->child == -1)
		ft_exit_error("fork");
	if (p->child)
		close(p->pipefd[1]);
	else
		close(p->pipefd[0]);
}

void	ft_last_child(t_process *p)
{
	
}

void	ft_process(char *line, char **envp, int fdin)
{
	t_process	p;

	//ft_parse_line
	ft_bzero(&p, sizeof(p));
	dup2(fdin, STDIN_FILENO);
	if (p.pipe)
	{
		ft_fork(&p);
		if (p.child)
			ft_process(p.nextcmd, envp, p.pipefd[0]);
		dup2(p.pipefd[1], STDOUT_FILENO);
	}
	else
		ft_last_child(&p);
	//ft_exec
	waitpid(getppid(), 0, 0);
	close(fdin);
	close(p.pipefd[1]);
	exit(0);
}
