/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:07:42 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/14 14:37:14 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_redir(t_type type)
{
	if (type == LESS || type == DLESS || type == GREAT || type == DGREAT)
		return (1);
	return (0);
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
	{
		if ((type == OR_IF || type == AND_IF || type == PIPE || type == ENDLINE)
			&& last->type != WORD && last->type != R_PARENTH)
			return (0);
		if (type == L_PARENTH && last->type != AND_IF && last->type != OR_IF
			&& last->type != PIPE)
			return (0);
		if (type == R_PARENTH && last->type != WORD)
			return (0);
		if ((ft_is_redir(type) || type == ENDLINE) && ft_is_redir(last->type))
			return (0);
	}
	else if (type == PIPE || type == AND_IF || type == OR_IF)
		return (0);
	return (1);
}
