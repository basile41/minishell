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

void	ft_free_env(t_env *env)
{
	t_env	*temp;

	if (g_data.env)
	{
		temp = g_data.env;
		while (temp)
		{
			if (temp->next == env)
			{
				temp->next = env->next;
				free(env->key);
				free(env);
				break ;
			}
			temp = temp->next;
		}
	}
}

void	ft_lstfree_env(void)
{
	t_env	*env;
	t_env	*temp;

	if (g_data.env)
	{
		env = g_data.env;
		while (env)
		{
			free(env->key);
			temp = env->next;
			free(env);
			env = temp;
		}
	}
}

void	ft_fill_env(char **envp)
{
	int	i;

	g_data.env = env_new(envp[0], 1);
	i = 1;
	while (envp[i])
	{
		env_add_back(&g_data.env, env_new(envp[i], 1));
		i ++;
	}
	g_data.env_size = i;
}
