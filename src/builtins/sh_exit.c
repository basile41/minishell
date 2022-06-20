/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:31:31 by cmarion           #+#    #+#             */
/*   Updated: 2022/06/20 15:12:23 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isnum(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (!ft_isdigit(cmd[i]))
			return (0);
		i ++;
	}
	return (1);
}

void	__exit(int exit_code, char **cmd)
{
	clear_history();
	ft_free_strs(cmd);
	ft_free_and_exit(exit_code);
	// exit(exit_code);
}

void	sh_exit(char **cmd)
{
	if (!cmd[1])
	{
		ft_putstr_fd("exit\n", 2);
		__exit(g_data.exit_code, cmd);
	}
	if (cmd[1] && !cmd[2])
	{
		if (!ft_isnum(cmd[1]))
		{
			ft_dprintf(2,
				"exit\nminishell: exit: %s: numeric argument required\n",
				cmd[1]);
			__exit(2, cmd);
		}
		else
		{
			ft_putstr_fd("exit\n", 2);
			__exit(ft_atoi(cmd[1]), cmd);
		}
	}
	if (cmd[1] && cmd[2])
	{
		ft_putstr_fd("exit\nminishell: exit: too many arguments\n", 2);
		__exit(1, cmd);
	}
}
