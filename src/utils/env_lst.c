/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:10:31 by cmarion           #+#    #+#             */
/*   Updated: 2022/04/01 10:43:14 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_env	*env_new(char *val, int env_disp)
{
	t_env	*new;

	new = malloc(sizeof (t_env));
	if (!new)
		return (NULL);
	new->var = val;
	new->env_disp = env_disp;
	new->next = NULL;
	return (new);
}
