/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:04:27 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/10 14:52:31 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(char **cmd)
{
	char	*path;
	char	*path_var;

	path = NULL;
	path_var = ft_get_value("PATH");
	if (path_var && ft_strchr(*cmd, '/') == NULL)
		path = ft_get_path(*cmd);
	else
		path = *cmd;
	free(path_var);
	if (path)
	{
		signal(SIGQUIT, SIG_DFL);
		execve(path, cmd, ft_get_env());
		perror(ft_strjoin("minishell: ", *cmd));
	}
	if (path != *cmd)
		free(path);
	ft_free_strs(cmd);
	ft_free_and_exit(127);
}
