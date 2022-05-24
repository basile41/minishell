/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:23:02 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/24 13:32:00 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pwds_actu_in(t_env *env, char *pwd_name, char *pwd)
{
	char	*temp;

	ft_free_env(env);
	temp = ft_strjoin(pwd_name, pwd);
	env_add_back(&g_data.env, env_new(temp, 1));
	free (temp);
}

void	pwds_actu(char *old)
{
	t_env	*env;
	char	*add;

	env = g_data.env;
	while (env && ft_strcmp(env->key, "OLDPWD") != 0)
		env = env->next;
	if (old && ft_strcmp(env->key, "OLDPWD") == 0)
		pwds_actu_in(env, "OLDPWD=", old);
	env = g_data.env;
	while (env && ft_strcmp(env->key, "PWD") != 0)
		env = env->next;
	if (ft_strcmp(env->key, "PWD") == 0)
	{
		add = NULL;
		add = getcwd(add, 4096);
		if (!add)
			ft_free_and_exit(1);
		pwds_actu_in(env, "PWD=", add);
		free (add);
	}
}

void	home_cd(char *old)
{
	t_env	*env;

	env = g_data.env;
	while (env && ft_strcmp(env->key, "HOME") != 0)
		env = env->next;
	if (ft_strcmp(env->key, "HOME") == 0 && env->value
		&& chdir(env->value) == 0)
		pwds_actu(old);
	else
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
}

void	sh_cd(char **cmd)
{
	char	*add;

	if (cmd[1] && cmd[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		g_data.exit_code = 1;
	}
	else
	{
		add = NULL;
		add = getcwd(add, 4096);
		if (!add)
			ft_free_and_exit(1);
		if (!cmd[1])
			home_cd(add);
		else if (chdir(cmd[1]) == 0)
			pwds_actu(add);
		else
		{
			ft_dprintf(2, "minishell: cd: %s: No such file or directory\n",
				cmd[1]);
			g_data.exit_code = 1;
		}
		free (add);
	}
}
