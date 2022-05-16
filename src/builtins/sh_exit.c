/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:31:31 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/13 17:55:21 by bregneau         ###   ########.fr       */
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

void	_exit(int exit_code)
{
	clear_history();
	exit(exit_code);
}

void	sh_exit(char **cmd)
{
	if (!cmd[1])
	{
		printf("exit\n");
		_exit(g_data.exit_code);
	}
	if (cmd[1] && !cmd[2])
	{
		if (!ft_isnum(cmd[1]))
		{
			printf("exit\nminishell: exit: %s: numeric argument required\n",
				cmd[1]);
			_exit(2);
		}
		else
		{
			printf("exit\n");
			_exit(ft_atoi(cmd[1]));
		}
	}
	if (cmd[1] && cmd[2])
	{
		printf("exit\nminishell: exit: too many arguments\n");
		_exit(1);
	}
}