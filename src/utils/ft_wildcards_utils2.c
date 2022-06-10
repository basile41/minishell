/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcards_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:55:44 by cmarion           #+#    #+#             */
/*   Updated: 2022/06/10 14:57:38 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	if_not_found(char **content, char *str)
{
	content[0] = ft_strdup(str);
	if (!content[0])
		ft_free_and_exit(EXIT_FAILURE);
	content [1] = NULL;
}

void	sort_content(char **content)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (content[++ i])
	{
		j = i;
		while (content[++ j])
		{
			if (ft_strncmp(content[i], content[j], ft_strlen(content[i])) > 0)
			{
				temp = content[j];
				content[j] = content[i];
				content[i] = temp;
			}
		}
	}
}

char	**simple_star(char **content)
{
	int	i;

	i = -1;
	while (content[++ i])
	{
		if (content[i][0] == '.')
		{
			tab_del_one(content, i);
			i --;
		}
	}
	sort_content(content);
	return (content);
}
