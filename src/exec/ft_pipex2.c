/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:54:54 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/12 17:53:01 by bregneau         ###   ########.fr       */
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
	if (paths == NULL)
		return (NULL);
	tmp = ft_strjoin("/", cmd_name);
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], tmp);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
		i++;
	}
	ft_free_strs(paths);
	if (path == NULL)
		printf("%s : command not found", cmd_name);
	return (path);
}

pid_t	ft_fork()
{
	pid_t	child;

	child = fork;
	if (fork == -1)
	{
		perror("fork: ");
		return (-1);
	}
	else
		return (child);
}

void	ft_pipeline(t_pipeline *pl, int nb_cmds)
{
	pid_t	child[2048];
	int		pipefd[2];
	int		i;

	i = 0;
	while (i < nb_cmds)
	{
		pipe(pipefd);
		child[i] = ft_fork();
		if (child[i] == -1)
			return (ft_error(1))
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