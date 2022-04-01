/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:19:49 by cmarion           #+#    #+#             */
/*   Updated: 2022/04/01 17:11:05 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_not_a_valid_identifier(void)
{
	exit(0);
	return (0);
}

int	env_name_verif(char *cmd)
{
	int	i;

	if (cmd[0] && (ft_isalpha(cmd[0]) || cmd[0] == '_'))
	{
		i = 1;
		while (cmd[i] && cmd[i] != '='
			&& (ft_isalnum(cmd[i]) || cmd[i] == '_'))
			i ++;
		if (cmd[i] == '=')
			return (i);
		if (!ft_isalnum(cmd[i - 1]) || cmd[i - 1] != '_')
			return (exit_not_a_valid_identifier());
		else
			return (-1);
	}
	else
		return (exit_not_a_valid_identifier());
}

void	add_var_to_env(t_data *data, char **cmd)
{
	int	i;

	i = 1;
	printf("%s\n", cmd[1]);
	while (cmd[i])
	{
		if (env_name_verif(cmd[i]) >= 0)
		{
			env_add_back(&data->env, env_new(cmd[i], 1));
		}
		if (env_name_verif(cmd[i]) == -1)
			env_add_back(&data->env, env_new(cmd[i], 0));
		i ++;
	}
}

void	sh_export(t_data *data, char **cmd)
{
	/*if (!cmd[1])
	{
		if (data->env)
			export_display(data);
	}
	else*/
	{
		add_var_to_env(data, cmd);
		export_display(data);
	}
}
