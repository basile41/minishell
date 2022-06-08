/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:10:31 by cmarion           #+#    #+#             */
/*   Updated: 2022/06/08 20:24:12 by bregneau         ###   ########.fr       */
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
	key = malloc(sizeof(char) * (i + 1));
	if (!key)
		ft_free_and_exit(1);
	key[0] = '\0';
	ft_strlcpy(key, var, i + 1);
	return (key);
}

char	*get_env_value(char *var)
{
	int		i;

	i = 0;
	while (var[i] && var[i] != '=')
		i ++;
	if (var[i] == '=' && var[i + 1])
		return (ft_strdup(var + i + 1));
	else
		return (ft_strdup(""));
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
	new->var = ft_strdup(var);
	new->key = get_env_key(new->var);
	new->value = get_env_value(new->var);
	new->env_disp = env_disp;
	new->next = NULL;
	return (new);
}
