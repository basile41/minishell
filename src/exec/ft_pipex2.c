/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:54:54 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/10 14:53:13 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fork(pid_t *child)
{
	*child = fork();
	if (*child == -1)
		ft_exit_perror("fork");
}

void	ft_pipe_fork(t_pipeline *pl, pid_t *child)
{
	int		pipefd[2];
	int		ret;

	ret = pipe(pipefd);
	if (ret < 0)
		ft_exit_perror("pipe");
	ft_fork(child);
	if (*child == 0)
	{
		close(pipefd[0]);
		ret = dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		if (ret < 0)
			ft_exit_perror("dup2");
		ft_process(pl);
	}
	close(pipefd[1]);
	ret = dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	if (ret < 0)
		ft_exit_perror("dup2");
}

void	ft_last_cmd(t_pipeline *pl, pid_t *child)
{
	ft_fork(child);
	if (*child == 0)
		ft_process(pl);
}

void	ft_pipeline(t_pipeline *pl, int nb_cmds, pid_t *childs)
{
	int		i;

	i = 0;
	while (i < nb_cmds)
	{
		if (i < nb_cmds - 1)
			ft_pipe_fork(pl, childs + i);
		else
			ft_last_cmd(pl, childs + i);
		i++;
		while (i < nb_cmds && pl->start->type != PIPE)
			pl->start = pl->start->next;
		pl->start = pl->start->next;
	}
}
