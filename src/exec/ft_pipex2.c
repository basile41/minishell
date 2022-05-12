/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:54:54 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/11 14:07:31 by bregneau         ###   ########.fr       */
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
	return (path);
}

// void	ft_pipeline(t_pipeline *pl, int nb_cmds)
// {

// }

// int	main(int argc, char **argv, char **envp)
// {
// 	(void)argc;
// 	ft_bzero(&g_data, sizeof(g_data));
// 	ft_fill_env(envp);
// 	printf("%s\n", ft_get_path(argv[1]));
// }