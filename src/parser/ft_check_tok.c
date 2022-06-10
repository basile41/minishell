/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:07:42 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/10 14:53:39 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_redir(t_type type)
{
	if (type == LESS || type == DLESS || type == GREAT || type == DGREAT)
		return (1);
	return (0);
}

int	ft_check_word(t_token *last)
{
	t_token	*curr;

	curr = last;
	while (curr && curr->type != AND_IF && curr->type != OR_IF
		&& curr->type != PIPE && curr->type != L_PARENTH)
	{
		if (curr->type == R_PARENTH)
			return (0);
		curr = curr->prev;
	}
	return (1);
}

int	ft_check_tok_in(t_token *last, t_type type)
{
	if ((type == OR_IF || type == AND_IF || type == PIPE || type == ENDLINE)
		&& last->type != WORD && last->type != R_PARENTH
		&& last->type != IO_NUMBER)
		return (0);
	if (type == L_PARENTH && last->type != AND_IF && last->type != OR_IF
		&& last->type != PIPE && last->type != L_PARENTH)
		return (0);
	if (type == R_PARENTH && last->type != WORD && last->type != type)
		return (0);
	if ((ft_is_redir(type) || type == ENDLINE) && ft_is_redir(last->type))
		return (0);
	if (type == WORD && ft_is_redir(last->type) == 0)
		return (ft_check_word(last));
	return (1);
}

int	ft_check_tok(t_token *last, t_type type)
{
	static int	parenth;

	if (last == NULL)
		parenth = 0;
	if ((type == L_PARENTH && ++parenth) || (type == R_PARENTH && --parenth))
		if (parenth < 0)
			return (0);
	if (type == ENDLINE && parenth > 0)
		return (0);
	if (last)
		return (ft_check_tok_in(last, type));
	else if (type == PIPE || type == AND_IF || type == OR_IF)
		return (0);
	return (1);
}
