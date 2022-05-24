/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcards_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:55:44 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/24 11:39:16 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while (str[i] && str[i] != '*' && i > 0)
		i --;
	if (str[i] && str[i] == '*')
		return (i);
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
