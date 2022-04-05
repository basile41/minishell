/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:10:31 by cmarion           #+#    #+#             */
/*   Updated: 2022/04/04 17:01:41 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_key(char *var)
{
	char	*key;
	int		i;

	i = 0;
	while (var[i] && var[i] != '=')
		i ++;
	key = malloc(sizeof(char) * i + 1);
	if (!key)
		ft_free_and_exit(1);
	ft_strlcpy(key, var, i + 1);
	key[i + 2] = '\0';
	return (key);
}

char	*get_env_value(char *var)
{
	int		i;

	i = 0;
	while (var[i] && var[i] != '=')
		i ++;
	if (i < (int)ft_strlen(var))
		return (var + i + 1);
	else
		return (NULL);
}

t_env	*env_last(t_env *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	env_add_back(t_env **alst, t_env *new)
{
	t_env	*list;

	if (*alst)
	{
		list = env_last(*alst);
		list->next = new;
	}
	else
		*alst = new;
}

t_env	*env_new(char *var, int env_disp)
{
	t_env	*new;

	new = malloc(sizeof (t_env));
	if (!new)
		ft_free_and_exit(1);
	new->var = var;
	new->key = get_env_key(var);
	new->value = get_env_value(var);
	new->env_disp = env_disp;
	new->next = NULL;
	return (new);
}
