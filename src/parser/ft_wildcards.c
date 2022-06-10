/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcards.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:27:30 by cmarion           #+#    #+#             */
/*   Updated: 2022/06/10 14:06:56 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**w_contain(char **content, char *str, int i)
{
	int		j;
	char	*point;

	j = -1;
	point = ft_strchr(str, '.');
	while (content[++ j])
	{
		if (!str_contain(content[j], str, i))
		{	
			content = tab_del_one(content, j);
			j --;
		}
		else if (!point && ft_strchr(content[j], '.'))
		{	
			content = tab_del_one(content, j);
			j --;
		}
	}
	return (content);
}

char	**w_ending(char **content, char *str)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (content[++ i])
	{
		j = ft_strlen(content[i]) + 1;
		k = ft_strlen(str) + 1;
		while (content[i][-- j] == str[-- k])
			;
		if (!(content[i][j + 1] == str[k + 1] && str[k] == '*'))
		{
			content = tab_del_one(content, i);
			i --;
		}
		else if (str[0] != '.' && content[i][0] == '.')
		{
			content = tab_del_one(content, i);
			i --;
		}
	}
	return (content);
}

char	**w_begining(char **content, char *str, int i)
{	
	int	j;
	int	k;

	j = -1;
	while (content[++ j])
	{
		k = 0;
		while (content[j][k] == str[k] && k <= i)
			k ++;
		if (i != k)
		{
			content = tab_del_one(content, j);
			j --;
		}
	}
	return (content);
}

char	**complex_star(char *str, char **content)
{
	int		i;

	i = -1;
	while (str[++ i])
	{
		if (str[i] == '*')
		{
			if (str[i + 1] && str[i + 1] != '*' && star_after(&str[i + 1]) > 0)
				content = w_contain(content, &str[i + 1],
						star_after(&str[i + 1]));
			if (i > 0 && str[i - 1] && star_before(str, i - 1) == 0
				&& str[i - 1] != '*')
				content = w_begining(content, str, i);
			if (str[i + 1] && str[i + 1] != '*' && star_after(&str[i + 1]) == 0)
			{
				content = w_ending(content, &str[i + 1]);
				break ;
			}
		}
	}
	if (!content[0])
		if_not_found(content, str);
	return (content);
}

char	**ft_wildcard(char *word)
{	
	char			**expwild;
	struct dirent	*content;
	DIR				*dir;
	int				size;

	dir = opendir(".");
	content = readdir(dir);
	expwild = ft_calloc(2, sizeof (char *));
	size = 1;
	while (content)
	{
		expwild = ft_realloc(expwild, (size + 1) * sizeof(char *),
				(size + 2) * sizeof(char *));
		expwild[size - 1] = ft_strdup(content->d_name);
		content = readdir(dir);
		size ++;
	}
	free (dir);
	free (content);
	expwild[size - 1] = NULL;
	if (word[0] == '*' && !word[1])
		return (simple_star(expwild));
	return (complex_star(word, expwild));
}
