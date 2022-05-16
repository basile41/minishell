/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:54:54 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/16 20:36:24 by bregneau         ###   ########.fr       */
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
		dup2(pipefd[1], STDOUT_FILENO);
		(void)pl;
	}
	ret = dup2(pipefd[0], STDIN_FILENO);
	if (ret < 0)
		ft_exit_perror("dup2");
}

void	ft_pipeline(t_pipeline *pl, int nb_cmds)
{
	int		i;

	(void)pl;
	i = 0;
	while (i < nb_cmds)
	{
		ft_pipe_fork(pl);
		i++;
	}
}

// int	main(int argc, char **argv, char **envp)
// {
// 	(void)argc;
// 	ft_bzero(&g_data, sizeof(g_data));
// 	ft_fill_env(envp);
// 	printf("%s\n", ft_get_path(argv[1]));
// }