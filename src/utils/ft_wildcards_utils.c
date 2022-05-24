/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcards_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:55:44 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/24 09:27:02 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	int	j;

	i = 0;
	while (str[i] && str[i] == '*')
		i ++;
	j = 0;
	while (str[i + j] && str[i + j] != '*')
		i ++;
	if (str[i + j] && str[i + j] == '*')
		return (j);
	return (0);
}
