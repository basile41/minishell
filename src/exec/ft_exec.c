/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:04:27 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/24 20:08:06 by bregneau         ###   ########.fr       */
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
	if (path)
	{
		signal(SIGQUIT, SIG_DFL);
		execve(path, cmd, ft_get_env());
		perror(ft_strjoin("minishell: ", *cmd));
	}
	ft_free_and_exit(127);
	// exit(127);
}
