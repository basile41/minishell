/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcards_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:55:44 by cmarion           #+#    #+#             */
/*   Updated: 2022/06/09 13:17:28 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_contain(char *where, char *what, int len)
{
	int	j;
	int	k;

	j = -1;
	while (where[++ j])
	{
		k = 0;
		while (where[j + k] == what[k] && k <= len)
			k ++;
		if (k == len)
			return (1);
	}
	return (0);
}

char	**tab_del_one(char **tchar, int del)
{
	while (tchar[del])
	{
		free (tchar[del]);
		if (tchar[del + 1])
			tchar[del] = ft_strdup(tchar[del + 1]);
		else
			tchar[del] = NULL;
		del ++;
	}
	return (tchar);
}

int	tabchar_len(char **tchar)
{
	int	i;

	i = 0;
	while (tchar[i] != NULL)
		i ++;
	return (i);
}

int	star_before(char *str, int i)
{
	while (i >= 0 && str[i] && str[i] != '*')
		i --;
	if (i >= 0 && str[i] && str[i] == '*')
		return (1);
	return (0);
}

int	star_after(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '*')
		i ++;
	if (str[i] && str[i] == '*')
		return (i);
	return (0);
}
