/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:10:31 by cmarion           #+#    #+#             */
/*   Updated: 2022/06/20 16:17:53 by bregneau         ###   ########.fr       */
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
	char	*ret;

	i = 0;
	while (var[i] && var[i] != '=')
		i ++;
	if (var[i] == '=' && var[i + 1])
		ret = ft_strdup(var + i + 1);
	else
		ret = ft_strdup("");
	if (!ret)
		ft_free_and_exit(EXIT_FAILURE);
	return (ret);
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
	g_data.env_size ++;
}

t_env	*env_new(char *var, int env_disp)
{
	t_env	*new;

	new = malloc(sizeof (t_env));
	if (!new)
		ft_free_and_exit(EXIT_FAILURE);
	if (var)
	{
		new->var = ft_strdup(var);
		if (!new->var)
			ft_free_and_exit(EXIT_FAILURE);
		new->key = get_env_key(new->var);
		new->value = get_env_value(new->var);
		new->env_disp = env_disp;
		new->next = NULL;
	}
	else
	{
		new->var = NULL;
		new->key = NULL;
		new->value = NULL;
		new->env_disp = env_disp;
		new->next = NULL;
	}
	return (new);
}
