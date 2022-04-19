/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_ex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:58:13 by cmarion           #+#    #+#             */
/*   Updated: 2022/04/14 14:01:48 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtins(char *cmd)
{
	if (ft_strcmp(cmd, "cd"))
		return (1);
	else if (ft_strcmp(cmd, "echo"))
		return (1);
	else if (ft_strcmp(cmd, "env"))
		return (1);
	else if (ft_strcmp(cmd, "exit"))
		return (1);
	else if (ft_strcmp(cmd, "export"))
		return (1);
	else if (ft_strcmp(cmd, "pwd"))
		return (1);
	else if (ft_strcmp(cmd, "unset"))
		return (1);
	else
		return (0);
}

void	builtins_ex(char **cmd, void (*f)(char **))
{
	f(cmd);
}
