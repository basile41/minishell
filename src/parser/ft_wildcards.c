/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcards.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:27:30 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/20 12:27:26 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	aff_tabcchar(char **tab)
{
	int	i;

	i = 0;
	while (expwild[i])
	{
		printf("%s, %d\n", expwild[i], i);
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
	return (expwild);
}

char	**complex_star(void)
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
	return (expwild);
}

char	**ft_wildcard(char *wild)
{	
	char	**expwild;

	if (!wild[1])
		expwild = simple_star();
	else
		expwild = complex_star(&wild[1]);
	free (dir);
	return (expwild);
}
