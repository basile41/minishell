/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:35:19 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/24 13:32:22 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	last_flag(char **cmd)
{
	int	i;
	int	j;

	i = 1;
	while (cmd[i])
	{
		if (cmd[i] && cmd[i][0] == '-')
		{	
			j = 1;
			while (cmd[i][j] == 'n')
				j ++;
			if (!cmd[i][j])
				i ++;
			else
				return (i);
		}
		else
			return (i);
	}
	return (i);
}

void	sh_echo(char **cmd)
{
	int	i;
	int	n;

	i = last_flag(cmd);
	n = i;
	while (cmd[i])
	{
		printf("%s", cmd[i]);
		if (cmd[i + 1])
			printf(" ");
		i ++;
	}
	if (n == 1)
		printf("\n");
	g_data.exit_code = 0;
}
