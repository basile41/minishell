/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:19:49 by cmarion           #+#    #+#             */
/*   Updated: 2022/04/01 11:43:00 by cmarion          ###   ########.fr       */
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

void	print_name_env(t_data *data, char *env)
{
	char	*name;
	int		i;

	i = 0;
	while (env[i] && env[i] != '=')
		i ++;
	name = malloc(sizeof(char) * i + 1);
	if (!name)
		ft_free_and_exit(data, 1);
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

void	export_display(t_data *data)
{
	char	**tenv;
	t_env	*env;
	int		i;

	env = data->env;
	i = 0;
	tenv = malloc(sizeof(char *) * data->env_size);
	if (!tenv)
		ft_free_and_exit(data, 1);
	while (env)
	{
		tenv[i] = ft_strdup(env->var);
		if (!tenv[i ++])
			ft_free_and_exit(data, 1);
		env = env->next;
	}
	sort_display_env(tenv);
	i = 0;
	while (tenv[i])
	{
		printf("declare -x ");
		print_name_env(data, tenv[i]);
		print_val_env(tenv[i ++]);
	}
	ft_free_strs(tenv);
}
