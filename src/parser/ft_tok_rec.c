/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok_rec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:33:44 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/06 19:42:55 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_type	ft_get_type(char *s)
{
	if (ft_strncmp(s, "&&", 2) == 0)
		return (AND_IF);
	if (ft_strncmp(s, "||", 2) == 0)
		return (OR_IF);
	if (ft_strncmp(s, "<<", 2) == 0)
		return (DLESS);
	if (ft_strncmp(s, ">>", 2) == 0)
		return (DGREAT);
	if (*s == '|')
		return (PIPE);
	if (*s == '<')
		return (LESS);
	if (*s == '>')
		return (GREAT);
	if (*s == '(')
		return (L_PARENTH);
	if (*s == ')')
		return (R_PARENTH);
	return (WORD);
}

int	ft_parse_tok(char *str, t_type type)
{
	static t_token	*last;
	t_token			*new;

	new = ft_new_tok(str, type);
	if (!new)
		return (0);
	if (last && last->type == DLESS && type == WORD)
	{
		new->type = IO_NUMBER;
		free(new->word);
		new->word = ft_itoa(ft_heredoc(str));
	}
	if (last == NULL)
	{
		last = new;
		g_data.tok = new;
	}
	else
		last = ft_add_tok(&last, new);
	return (1);
}

int	ft_tok_rec(char *line)
{
	char	**strs;
	t_token	*tok;
	int		i;

	strs = ft_split_toks(line);
	if (strs == NULL)
		return (0);
	tok = NULL;
	i = 0;
	while (strs[i])
	{
		ft_parse_tok(strs[i], ft_get_type(strs[i]));
		i++;
	}
	ft_free_strs(strs);
	return (1);
}
