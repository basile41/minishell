/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcards_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:55:44 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/23 16:53:08 by cmarion          ###   ########.fr       */
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
