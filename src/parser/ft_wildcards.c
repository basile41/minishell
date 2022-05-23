/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcards.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:27:30 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/23 14:10:46 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	aff_tabcchar(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s, %d\n", tab[i], i);
		i ++;
	}
}*/

char	**w_content(char **content, char *str, int i, char **ret)
{
	int	j;
	int	k;
	int	l;
	int	m;

	j = -1;
	while (content[++ j])
	{
		k = -1;
		while (content[j][++ k])
		{
			l = k;
			m = i;
			while (content[j][l] == str[l] && m --)
				l ++;
			if (m == 0)
			{	
				ret = ft_realloc(ret, tabchar_len(ret) * sizeof(char *),
						tabchar_len(ret) * sizeof(char *) + 1);
				ret[tabchar_len(ret) + 1] = ft_strdup(content[j]);
			}
		}
	}
	return (ret);
}

char	**w_ending(char **content, char *str, char **ret)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (content[++ i])
	{
		j = ft_strlen(content[i]);
		k = ft_strlen(str);
		while (content[i][j --] == str[k --])
			;
		if (k == 0)
		{
			ret = ft_realloc(ret, tabchar_len(ret) * sizeof(char *),
					tabchar_len(ret) * sizeof(char *) + 1);
			ret[tabchar_len(ret) + 1] = ft_strdup(content[i]);
		}
	}
	return (ret);
}

char	**w_begining(char **content, char *str, int i, char **ret)
{	
	int	j;
	int	k;

	j = -1;
	while (content[++ j])
	{
		k = 0;
		while (content[j][k] == str[k] && k <= i)
			k ++;
		if (i == k)
		{
			ret = ft_realloc(ret, tabchar_len(ret) * sizeof(char *),
					tabchar_len(ret) * sizeof(char *) + 1);
			ret[tabchar_len(ret) + 1] = ft_strdup(content[j]);
		}
	}
	return (ret);
}

char	**complex_star(char *str, char **content)
{
	int		i;
	char	**ret;

	ret = NULL;
	i = -1;
	while (str[++ i])
	{
		if (str[i] == '*')
		{
			if (star_before(str, i) > 0 && star_after(&str[i]) > 0)
				w_content(content, &str[star_before(str, i)], star_after(&str[i]), ret);
			if (star_before(str, i) > 0 && star_after(&str[i]) == 0)
				w_ending(content, &str[i], ret);
			if (star_before(str, i) == 0 && star_after(&str[i]) > 0)
				w_begining(content, str, i, ret);
		}
	}
	return (ret);
}

char	**ft_wildcard(char *wild)
{	
	char			**expwild;
	struct dirent	*content;
	DIR				*dir;
	int				size;

	dir = opendir(".");
	content = malloc(sizeof(struct dirent));
	content = readdir(dir);
	expwild = NULL;
	size = 1;
	while (content)
	{
		expwild = ft_realloc(expwild, size * sizeof(char *),
				(size + 1) * sizeof(char *));
		expwild[size - 1] = ft_strdup(content->d_name);
		content = readdir(dir);
		size ++;
	}
	free (dir);
	free (content);
	expwild[size - 1] = NULL;
	if (wild[0] == '*' && !wild[1])
		return (expwild);
	return (complex_star(wild, expwild));
}
