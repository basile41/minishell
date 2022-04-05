/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:19:49 by cmarion           #+#    #+#             */
/*   Updated: 2022/04/04 17:00:35 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_not_a_valid_identifier(void)
{
	exit(0);
	return (0);
}

int	env_key_nexist(char *cmd)
{
	t_env	*env;
	char	*name;

	env = g_data.env;
	name = get_env_key(cmd);
	while (env)
	{
		if (ft_strcmp(env->key, name) == 0)
		{
			free(name);
			return (0);
		}
		env = env->next;
	}
	free(name);
	return (1);
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
		if (cmd[i] && !(ft_isalnum(cmd[i]) && cmd[i] != '_'))
			return (exit_not_a_valid_identifier());
		else
			return (-1);
	}
	else
		return (exit_not_a_valid_identifier());
}

void	add_var_to_env(char **cmd)
{
	int		i;
	int		key_valid;
	int		key_nexist;
	t_env	*env;

	i = 1;
	while (cmd[i])
	{
		key_valid = env_name_verif(cmd[i]);
		key_nexist = env_key_nexist(cmd[i]);
		if (key_valid >= 0 && key_nexist)
			env_add_back(&g_data.env, env_new(cmd[i], 1));
		else if (key_valid >= 0 && key_nexist == 0)
		{
			env = g_data.env;
			while (ft_strncmp(env->key, cmd[i], key_valid - 1) != 0)
				env = env->next;
			free(env->key);
			env->var = cmd[i];
			env->key = get_env_key(cmd[i]);
			env->value = get_env_value(cmd[i]);
		}
		else if (key_valid == -1 && key_nexist)
			env_add_back(&g_data.env, env_new(cmd[i], 0));
		i ++;
	}
}

void	sh_export(char **cmd)
{
	if (!cmd[1])
	{
		if (g_data.env)
			export_display();
	}
	else
	{
		add_var_to_env(cmd);
		export_display();
	}
}
