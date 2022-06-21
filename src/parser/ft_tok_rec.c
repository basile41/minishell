/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok_rec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:33:44 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/21 17:00:40 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_type	ft_get_type(char *s, char *next)
{
	if (ft_strncmp(s, "&&", 2) == 0)
		return (AND_IF);
	if (ft_strncmp(s, "||", 2) == 0)
		return (OR_IF);
	if (ft_strncmp(s, "<<", 2) == 0)
		return (DLESS);
	if (ft_strncmp(s, ">>", 2) == 0)
		return (DGREAT);
	if (ft_strncmp(s, "\\n", 2) == 0 && next == NULL)
		return (ENDLINE);
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

	if (ft_check_tok(last, type) == 0)
		return ((last = NULL, 0));
	new = ft_new_tok(str, type);
	if (!new)
		return ((last = NULL, 0));
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
		last = ft_add_tok(last, new);
	if (type == ENDLINE)
		last = NULL;
	return (1);
}

int	ft_tok_rec(char *line)
{
	char	**strs;
	int		i;
	int		ret;

	strs = ft_split_toks(line);
	if (strs == NULL)
		return (1);
	i = -1;
	ret = 1;
	while (strs[++i] && ret)
		ret = ft_parse_tok(strs[i], ft_get_type(strs[i], strs[i + 1]));
	if (ret == 0)
	{
		ft_dprintf(2, "minishell: syntax error near unexpected token `%s'\n",
			strs[i - 1]);
		g_data.exit_code = 2;
		ft_free_strs(strs);
		return (2);
	}
	ft_free_strs(strs);
	return (0);
}
