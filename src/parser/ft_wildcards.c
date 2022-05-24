/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcards.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:27:30 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/24 12:30:10 by cmarion          ###   ########.fr       */
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

char	**w_content(char **content, char *str, int i)
{
	int	j;
	int	k;
	int	l;
	int	cont_size;

	j = -1;
//	aff_tabcchar(content);
	while (content[++ j])
	{
		k = -1;
		printf("************\n");
		aff_tabcchar(content);
		printf("************\n");
		printf("%d %zu\n", tabchar_len(content), ft_strlen(content[j]));
		while (content[j][++ k])
		{
			l = 0;
			while (content[j][k + l] == str[l] && l <= i)
				l ++;
			if (l != i)
			{	
				cont_size = tabchar_len(content);
				content = tab_del_one(content, j);
				content = ft_realloc(content, cont_size * sizeof(char *),
						(cont_size - 1) * sizeof(char *));
				j --;
				printf("j= %d\n", j);
				printf("%d %zu\n", tabchar_len(content), ft_strlen(content[++ j]));
				//printf("j= %d\n", j);
			}
		}
	}
	return (content);
}

char	**w_ending(char **content, char *str)
{
	int	i;
	int	j;
	int	k;
	int	cont_size;

	i = -1;
	while (content[++ i])
	{
		j = ft_strlen(content[i]) + 1;
		k = ft_strlen(str) + 1;
		while (content[i][-- j] == str[-- k])
			;
		if (!(content[i][j + 1] == str[k + 1] && str[k] == '*'))
		{
			cont_size = tabchar_len(content);
			content = tab_del_one(content, i);
			content = ft_realloc(content, cont_size * sizeof(char *),
					(cont_size + 1) * sizeof(char *));
			i --;
		}
	}
	return (content);
}

char	**w_begining(char **content, char *str, int i)
{	
	int	j;
	int	k;
	int	cont_size;

	j = -1;
	while (content[++ j])
	{
		k = 0;
		while (content[j][k] == str[k] && k <= i)
			k ++;
		if (i != k)
		{
			cont_size = tabchar_len(content);
			content = tab_del_one(content, j);
			content = ft_realloc(content, cont_size * sizeof(char *),
					(cont_size + 1) * sizeof(char *));
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
				content = w_content(content, &str[i + 1], star_after(&str[i + 1]));
			if (str[i - 1] && star_before(str, i - 1) == 0 && str[i - 1] != '*')
				content = w_begining(content, str, i);
			if (str[i + 1] && str[i + 1] != '*' && star_after(&str[i + 1]) == 0)
			{
				content = w_ending(content, &str[i + 1]);
				break ;
			}
		}
	}
	aff_tabcchar(content);
	return (content);
}

char	**ft_wildcard(char *wild)
{	
	char			**expwild;
	struct dirent	*content;
	DIR				*dir;
	int				size;

	dir = opendir(".");
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
	//printf("************\n");
	//aff_tabcchar(expwild);
	//printf("************\n");
	if (wild[0] == '*' && !wild[1])
		return (expwild);
	return (complex_star(wild, expwild));
}
