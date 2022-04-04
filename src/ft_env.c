/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:46:41 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/04 17:00:08 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	ft_free_env(t_env env)
{
	t_env	*env;
	t_env	*temp;

	if (data->env)
	{
		env = data->env;
		while (env)
		{
			free(env->key);
			temp = env->next;
			free(env);
			env = temp;
		}
	}
}*/

void	ft_lstfree_env(t_data *data)
{
	t_env	*env;
	t_env	*temp;

	if (data->env)
	{
		env = data->env;
		while (env)
		{
			free(env->key);
			temp = env->next;
			free(env);
			env = temp;
		}
	}
}

void	ft_fill_env(char **envp, t_data *data)
{
	int	i;

	data->env = env_new(data, envp[0], 1);
	i = 1;
	while (envp[i])
	{
		env_add_back(&data->env, env_new(data, envp[i], 1));
		i ++;
	}
	data->env_size = i;
}
