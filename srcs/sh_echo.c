/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:35:19 by cmarion           #+#    #+#             */
/*   Updated: 2022/03/30 13:17:35 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sh_echo(char **cmd)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	if (cmd[1] && ft_strcmp(cmd[1], "-n") == 0)
	{	
		n = 1;
		i ++;
	}
	while(cmd[i])
	{
		printf("%s", cmd[i]);
		if (cmd[i + 1])
			printf(" ");
		i ++;
	}
	if (!n)
		printf("\n");
}
