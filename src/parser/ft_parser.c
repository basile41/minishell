/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:57:01 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/10 15:05:09 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_del_cmd(t_token **tok)
{
	while ((*tok)->type != AND_IF && (*tok)->type != OR_IF
		&& (*tok)->type != PIPE && (*tok)->type != ENDLINE)
		*tok = ft_del_one_tok(*tok);
}

void	ft_parse_pipeline(t_token **toks)
{
	int			nb_cmds;
	t_pipeline	pl;

	pl.start = *toks;
	nb_cmds = 1;
	while (*toks && (*toks)->type != ENDLINE
		&& (*toks)->type != OR_IF && (*toks)->type != AND_IF)
	{
		if ((*toks)->type == PIPE)
			nb_cmds++;
		if ((*toks)->type == LESS || (*toks)->type == GREAT
			|| (*toks)->type == DGREAT)
			ft_open_redir(*toks);
		*toks = (*toks)->next;
	}
	pl.end = *toks;
	ft_pipex(&pl, nb_cmds);
}

int	ft_if_parenth(int parenth, t_type type)
{
	if (type == L_PARENTH)
		return (parenth + 1);
	if (type == R_PARENTH)
		return ((parenth - 1));
	return (parenth);
}

t_token	*ft_get_next_ccom(t_token *curr, int status)
{
	int	parenth;

	parenth = 0;
	if (curr == NULL)
		return (NULL);
	if (status == 0)
	{
		while (curr && (curr->type != AND_IF || parenth > 0))
		{
			parenth = ft_if_parenth(parenth, curr->type);
			curr = curr->next;
		}
	}
	else
	{
		while (curr && (curr->type != OR_IF || parenth > 0))
		{
			parenth = ft_if_parenth(parenth, curr->type);
			curr = curr->next;
		}
	}
	if (curr == NULL)
		return (NULL);
	return (curr->next);
}

void	ft_parser(t_token *toks)
{
	t_token	*curr;

	curr = toks;
	while (curr)
	{
		ft_parse_pipeline(&curr);
		curr = ft_get_next_ccom(curr, g_data.exit_code);
	}
}
