/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcards.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:27:30 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/20 17:27:18 by cmarion          ###   ########.fr       */
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

char	**simple_star(void)
{
	struct dirent	*content;
	DIR				*dir;
	int				size;
	char			**expwild;

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
	expwild[size - 1] = NULL;
	free (dir);
	free (content);
	return (expwild);
}

int	has_more_star(char *str)
{
	int	i;

	while (str[i] == '*')
		i ++;
	if (ft_strchr(&str[i], '*'))
		return (i);
	return (0);
}

char	**wilcards_type(char **content, char *str)
{
	int		i;
	char	**ret;

	if (str[0] == '*' && has_more_star(&str[1]) == 0)
		ending_chr(str);
	i = 1;
	
	if ()
	while (str[i])
	{
		if (str[i] == '*' && ret == 1)
		{
			while (str[i] == '*')
				i ++;
				
		}
			tes;
	}
}

char	**complex_star(char *str)
{
	struct dirent	*content;
	DIR				*dir;
	int				size;
	char			**expwild;

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
	expwild[size - 1] = NULL;
	return (expwild);
}

char	**ft_wildcard(char *wild)
{	
	char	**expwild;

	if (wild[0] == '*' && !wild[1])
		expwild = simple_star();
	else
		expwild = complex_star(wild);
	aff_tabcchar(expwild);
	return (expwild);
}
