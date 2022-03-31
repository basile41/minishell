/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:19:49 by cmarion           #+#    #+#             */
/*   Updated: 2022/03/31 14:39:52 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_display_env(char **tenv)
{
	int     i;
	int     j;
	char    *temp;

	i = 0;
	while (tenv[i])
	{
		j = i + 1;
		while(tenv[j])
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
	name = NULL;
	while(env[i] && env[i] != '=')
	{
		name[i] = env[i];
		i ++;
	}
	name[i] = '\0';
	printf("%s", name);
}

char	*get_val_env(t_data *data, char *env)
{
	char	*val;
	
	val = malloc(sizeof(char) * ft_strlen(ft_strchr(env, '=')) + 1);
	if (!val)
		ft_free_and_exit(data, 1);
	val = ft_strchr(env, '=');
	return (val);
}

void	export_display(t_data *data)
{
	char    **tenv;
	t_env   *env;
	char	*val;
	int     i;

	env = data->env;
	i = 0;
	tenv = malloc(sizeof(char *) * 100);
	while (env)
	{
		tenv[i] = ft_strdup(data->env->var);
		env = env->next;
		i ++;        
	}
	tenv[i] = NULL;
	sort_display_env(tenv);
	i = 0;
	while (tenv[i])
	{
		printf("declare -x ");
		print_name_env(tenv[i]);
		val = get_val_env(data, tenv[i]);
		if (val)
		{
			printf("=\"");
			printf("%s", get_val_env(data, tenv[i]));
			printf("\"");
		}
		printf("\n");
		free (val);
		i ++;
	}
}

void	sh_export(t_data *data, char **cmd)
{
	if (!cmd[1])
		export_display(data);
	/*else
		add_var_to_env(**cmd);*/
}