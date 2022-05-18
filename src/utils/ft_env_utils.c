/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:19:53 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/18 19:53:45 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_value(char *key)
{
	t_env	*curr;

	curr = g_data.env;
	while (curr)
	{
		if (ft_strcmp(curr->key, key) == 0)
			return (strdup(curr->value));
		curr = curr->next;
	}
	return (NULL);
}

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
		ft_dprintf(2, "%s : command not found\n", cmd_name);
	return (path);
}
