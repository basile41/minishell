/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcards_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:55:44 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/23 14:11:51 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tabchar_len(char **tchar)
{
	int	i;

	i = 0;
	while (tchar[i])
		i ++;
	return (i);
}

int	star_before(char *str, int i)
{
	while (str[i] && str[i] != '*')
		i --;
	if (str[i] == '*')
		return (i);
	return (0);
}

int	star_after(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '*')
		i ++;
	if (str[i] == '*')
		return (i);
	return (0);
}
