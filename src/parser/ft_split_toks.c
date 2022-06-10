/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_toks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:02:38 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/10 14:56:09 by cmarion          ###   ########.fr       */
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

int	ft_get_end_quote(char *s)
{
	int	i;

	i = 1;
	while (s[i] && s[i] != *s)
		i++;
	if (s[i] == '\0')
	{
		ft_dprintf(2,
			"minishell: unexpected NL while looking for matching `%c'\n", *s);
		return (-1);
	}
	if (s[i] == *s)
		i++;
	return (i);
}

int	ft_get_next_sep(char *s)
{
	int	i;
	int	ret;

	if (ft_strncmp(s, "||", 2) == 0
		||ft_strncmp(s, "&&", 2) == 0
		||ft_strncmp(s, "<<", 2) == 0
		||ft_strncmp(s, ">>", 2) == 0)
		return (2);
	if (ft_is_sep(s) && *s != '&')
		return (1);
	i = 0;
	while (s[i] && ft_is_sep(s + i) == 0)
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			ret = ft_get_end_quote(s + i);
			if (ret == -1)
				return (ret);
			i += ret;
		}
		else
			i++;
	}
	return (i);
}

int	str_count_toks(char *str)
{
	int	i;
	int	ret;

	i = 0;
	while (ft_isblank(*str))
		str++;
	ret = ft_get_next_sep(str);
	while (ret > 0)
	{
		str += ret;
		i++;
		while (ft_isblank(*str))
			str++;
		ret = ft_get_next_sep(str);
	}
	if (ret == -1)
		return (-1);
	return (i);
}

char	**ft_split_toks(char *s)
{
	char	**strs;
	int		i;
	int		j;
	int		size;

	size = str_count_toks(s);
	if (size < 0)
		return (NULL);
	strs = malloc((size + 2) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = -1;
	while (ft_isblank(*s))
		s++;
	while (++i < size)
	{
		j = ft_get_next_sep(s);
		strs[i] = ft_strndup(s, j);
		s += j;
		while (ft_isblank(*s))
			s++;
	}
	strs[i] = ft_strndup("\\n", 2);
	strs[++i] = NULL;
	return (strs);
}
