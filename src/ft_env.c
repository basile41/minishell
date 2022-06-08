/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:46:41 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/08 20:24:51 by bregneau         ###   ########.fr       */
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
				free (env->var);
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
			free(env->var);
			free(env->value);
			temp = env->next;
			free(env);
			env = temp;
		}
	}
}

char	**ft_get_env(void)
{
	char	**env;
	t_env	*curr;
	int		i;

	curr = g_data.env;
	i = 0;
	env = NULL;
	while (curr)
	{
		env = ft_realloc(env, (i + 1) * sizeof(*env),
				(i + 2) * sizeof(*env));
		if (env == NULL)
			return (NULL);
		env[i] = ft_strdup(curr->var);
		i++;
		curr = curr->next;
	}
	if (env)
		env[i] = NULL;
	return (env);
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
