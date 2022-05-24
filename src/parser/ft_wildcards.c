/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcards.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:27:30 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/24 09:48:12 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	aff_tabcchar(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s, %d\n", tab[i], i);
		i ++;
	}
}

char	**w_content(char **content, char *str, int i, char **ret)
{
	int	j;
	int	k;
	int	l;
	int	ret_size;

	j = -1;
	while (content[++ j])
	{
		k = -1;
		while (content[j][++ k])
		{
			l = 0;
			while (content[j][k + l] == str[l] && l < i)
				l ++;
			if (l == i)
			{	
				ret_size = tabchar_len(ret);
				ret = ft_realloc(ret, ret_size * sizeof(char *),
						(ret_size + 1) * sizeof(char *));
				ret[ret_size] = ft_strdup(content[j]);
				ret[ret_size + 1] = NULL;
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
	int	ret_size;

	i = -1;
	while (content[++ i])
	{
		j = ft_strlen(content[i]) + 1;
		k = ft_strlen(str) + 1;
		while (content[i][-- j] == str[-- k])
			;
		if (content[i][j + 1] == str[k + 1] && (k == -1 || str[k] == '*'))
		{
			ret_size = tabchar_len(ret);
			ret = ft_realloc(ret, ret_size * sizeof(char *),
					(ret_size + 1) * sizeof(char *));
			ret[ret_size] = ft_strdup(content[i]);
			ret[ret_size + 1] = NULL;
		}
	}
	return (ret);
}

char	**w_begining(char **content, char *str, int i, char **ret)
{	
	int	j;
	int	k;
	int	ret_size;

	j = -1;
	while (content[++ j])
	{
		k = 0;
		while (content[j][k] == str[k] && k <= i)
			k ++;
		if (i == k)
		{
			ret_size = tabchar_len(ret);
			ret = ft_realloc(ret, ret_size * sizeof(char *),
					(ret_size + 1) * sizeof(char *));
			ret[ret_size] = ft_strdup(content[j]);
			ret[ret_size + 1] = NULL;
		}
	}
	return (ret);
}

char	**complex_star(char *str, char **content)
{
	int		i;
	char	**ret;

	ret = ft_calloc(1, sizeof(char *));
	i = -1;
	while (str[++ i])
	{
		if (str[i] == '*')
		{
			if (star_after(&str[i + 1]) > 0)
			{
				ret = w_content(content, &str[i + 1], star_after(&str[i + 1]), ret);
				i = i + star_after(&str[i + 1]);
			}
			if (star_before(str, i - 1) == 0 && str[i - 1])
				ret = w_begining(content, str, i, ret);
			if (str[i + 1] && star_after(&str[i + 1]) == 0)
			{
				ret = w_ending(content, &str[i + 1], ret);
				break ;
			}
		}
	}
	i = -1;
	while (content[++ i])
		free (content[i]);
	free (content);
	aff_tabcchar(ret);
	return (ret);
}

char	**ft_wildcard(char *wild)
{	
	char			**expwild;
	struct dirent	*content;
	DIR				*dir;
	int				size;

	dir = opendir(".");
	//content = malloc(sizeof(struct dirent));
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
	printf("************\n");
	aff_tabcchar(expwild);
	printf("************\n");
	if (wild[0] == '*' && !wild[1])
		return (expwild);
	return (complex_star(wild, expwild));
}
