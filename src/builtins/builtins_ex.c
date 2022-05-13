/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_ex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:58:13 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/13 18:05:13 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtins(char *cmd)
{
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	else if (!ft_strcmp(cmd, "echo"))
		return (1);
	else if (!ft_strcmp(cmd, "env"))
		return (1);
	else if (!ft_strcmp(cmd, "exit"))
		return (1);
	else if (!ft_strcmp(cmd, "export"))
		return (1);
	else if (!ft_strcmp(cmd, "pwd"))
		return (1);
	else if (!ft_strcmp(cmd, "unset"))
		return (1);
	else
		return (0);
}

// void	builtins_ex(char **cmd, void (*f)(char **))
// {
// 	f(cmd);
// }


void	builtins_ex(char **cmd)
{
	if (!ft_strcmp(*cmd, "cd"))
		sh_cd(cmd);
	else if (!ft_strcmp(*cmd, "echo"))
		sh_echo(cmd);
	else if (!ft_strcmp(*cmd, "env"))
		sh_env();
	else if (!ft_strcmp(*cmd, "exit"))
		sh_exit(cmd);
	else if (!ft_strcmp(*cmd, "export"))
		sh_export(cmd);
	else if (!ft_strcmp(*cmd, "pwd"))
		sh_pwd();
	else if (!ft_strcmp(*cmd, "unset"))
		sh_unset(cmd);
}
