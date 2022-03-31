/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_toks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:02:38 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/25 15:35:13 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_sep(char *c)
{
	if (ft_strncmp(c, "&&", 2) == 0 || *c == '|' || *c == '<' || *c == '>'
		 || *c == '(' || *c == ')' || ft_isblank(*c))
		return (1);
	return (0);
}

int ft_get_end_quote(char *s)
{
	int i;
	
	i = 1;
	while (s[i] && s[i] != *s)
		i++;
	if (s[i] == *s)
		i++;
	return (i);
}

int	ft_get_next_sep(char *s)
{
	int i;

	if (ft_strncmp(s, "||", 2) == 0 || 
			ft_strncmp(s, "&&", 2) == 0 || 
			ft_strncmp(s, "<<", 2) == 0 || 
			ft_strncmp(s, ">>", 2) == 0)
		return (2);
	if (ft_is_sep(s) && *s != '&')
		return (1);
	i = 0;
	while (s[i] && ft_is_sep(s + i) == 0)
	{
		if (s[i] == '\'' || s[i] == '\"')
			i += ft_get_end_quote(s + i);
		else
			i++;
	}
	return (i);
}

int	str_count_toks(char *str)
{
	int	i;
	
	i = 0;
	while (ft_isblank(*str))
		str++;
	while (ft_get_next_sep(str))
	{
		str += ft_get_next_sep(str);
		i++;
		while (ft_isblank(*str))
			str++;
	}
	return (i);
}

char	**ft_split_toks(char *s)
{
	char	**strs;
	size_t	i;
	int j;
	size_t	size;
	
	size = str_count_toks(s);
	strs = malloc((size + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (ft_isblank(*s))
		s++;
	while (i < size)
	{
		j = ft_get_next_sep(s);
		strs[i] = ft_strndup(s, j);
		s += j;
		while (ft_isblank(*s))
			s++;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}