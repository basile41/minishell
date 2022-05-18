/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:54:54 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/18 19:14:44 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fork(pid_t *child)
{
	*child = fork();
	if (*child == -1)
		ft_exit_perror("fork");
}

void	ft_pipe_fork(t_pipeline *pl)
{
	pid_t	child;
	int		pipefd[2];
	int		ret;

	ret = pipe(pipefd);
	if (ret < 0)
		ft_exit_perror("pipe");
	ft_fork(&child);
	if (child == 0)
	{
		ret = dup2(pipefd[1], STDOUT_FILENO);
		if (ret < 0)
			ft_exit_perror("dup2");
		ft_process(pl);
	}
	ret = dup2(pipefd[0], STDIN_FILENO);

	waitpid(child, 0, WNOHANG);
	if (ret < 0)
		ft_exit_perror("dup2");
}

void	ft_last_cmd(t_pipeline *pl)
{
	pid_t	child;

	ft_fork(&child);
	if (child == 0)
		ft_process(pl);
	waitpid(child, 0, 0);
}

void	ft_pipeline(t_pipeline *pl, int nb_cmds)
{
	while (nb_cmds)
	{
		if (nb_cmds > 1)
			ft_pipe_fork(pl);
		else
			ft_last_cmd(pl);
		while (pl->start != pl->end && pl->start->type != PIPE)
			pl->start = pl->start->next;
		nb_cmds--;
	}
}

// int	main(int argc, char **argv, char **envp)
// {
// 	(void)argc;
// 	ft_bzero(&g_data, sizeof(g_data));
// 	ft_fill_env(envp);
// 	printf("%s\n", ft_get_path(argv[1]));
// }