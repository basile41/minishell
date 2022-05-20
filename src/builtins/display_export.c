/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:19:49 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/20 17:34:54 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_display_env(char **tenv)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (tenv[i])
	{
		j = i + 1;
		while (tenv[j])
		{
			if (ft_strncmp(tenv[i], tenv[j], ft_strlen(tenv[i])) > 0)
			{
				temp = tenv[j];
				tenv[j] = tenv[i];
				tenv[i] = temp;
			}
			j ++;
		}
		i ++;
	}
}

void	print_name_env(char *env)
{
	char	*name;
	int		i;

	i = 0;
	while (env[i] && env[i] != '=')
		i ++;
	name = malloc(sizeof(char) * i + 1);
	if (!name)
		ft_free_and_exit(1);
	ft_strlcpy(name, env, i + 1);
	name[i + 2] = '\0';
	printf("%s", name);
	free(name);
}

void	print_val_env(char *env)
{
	char	*val;

	val = NULL;
	val = ft_strchr(env, '=');
	if (val)
	{
		printf("=\"");
		printf("%s", val + 1);
		printf("\"");
	}
	printf("\n");
}

void	export_display(void)
{
	char	**tenv;
	t_env	*env;
	int		i;

	tenv = ft_calloc(sizeof(char *), g_data.env_size + 1);
	if (!tenv)
		ft_free_and_exit(1);
	env = g_data.env;
	i = -1;
	while (env)
	{
		tenv[++ i] = ft_strdup(env->var);
		if (!tenv[i])
			ft_free_and_exit(1);
		env = env->next;
	}
	sort_display_env(tenv);
	i = -1;
	while (tenv[++ i])
	{
		printf("declare -x ");
		print_name_env(tenv[i]);
		print_val_env(tenv[i]);
	}
	ft_free_strs(tenv);
}
