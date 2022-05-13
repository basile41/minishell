/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:54:54 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/13 15:05:40 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_path(char *cmd_name)
{
	char	**paths;
	char	*path;
	char	*tmp;
	int		i;

	path = ft_get_value("PATH");
	if (path == NULL)
		return (NULL);
	paths = ft_split(path, ':');
	free(path);
	tmp = ft_strjoin("/", cmd_name);
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], tmp);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
	}
	ft_free_strs(paths);
	if (path == NULL)
		printf("%s : command not found", cmd_name);
	return (path);
}

void	ft_fork(pid_t *child)
{
	*child = fork();
	if (*child == -1)
		ft_exit_perror("fork");
}

void	ft_pipe_fork(void)
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
		ft_pipe_fork();
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