/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:16:31 by cmarion           #+#    #+#             */
/*   Updated: 2022/06/20 15:50:24 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_verif(char *cmd)
{
	int	i;

	if (!ft_isalpha(cmd[0]) && cmd[0] != '_')
		return (0);
	i = 1;
	while (cmd[i])
	{
		if (!ft_isalnum(cmd[i]) && cmd[i] != '_')
			return (0);
		i ++;
	}
	if (i == (int)ft_strlen(cmd))
		return (1);
	return (0);
}

void	sh_unset(char **cmd)
{
	t_env	*env;
	int		i;
	int		exit_code;

	exit_code = 0;
	i = 0;
	while (cmd[++ i])
	{
		if (cmd_verif(cmd[i]))
		{
			env = g_data.env;
			while (env && ft_strcmp(cmd[i], env->key) != 0)
				env = env->next;
			if (env && ft_strcmp(cmd[i], env->key) == 0)
				ft_free_env(env);
		}
		else
		{
			ft_dprintf(2, "minishell: unset: `%s': not a valid identifier\n",
				cmd[i]);
			exit_code = 1;
		}
	}
	g_data.exit_code = exit_code;
}
