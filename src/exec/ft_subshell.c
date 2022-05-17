/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subshell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:05:07 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/17 19:26:39 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

void	ft_subshell(t_token *tok)
{
	int		parenth;
	t_token	*curr;

	parenth = 0;
	curr = tok;
	while (curr->type != R_PARENTH || parenth != 0)
	{
		if (curr->type == L_PARENTH)
			parenth++;
		if (curr->type == R_PARENTH)
			parenth--;
		curr = curr->next;
	}
}
