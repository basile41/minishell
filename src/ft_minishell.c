/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:55:25 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/10 13:46:45 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_expand(t_token **tok)
{
	t_token	*curr;
	t_token	*next;

	curr = *tok;
	while (curr)
	{
		next = curr->next;
		if ((curr)->type == WORD)
			ft_expand(&curr);
		if (curr->prev == NULL)
			*tok = curr;
		curr = next;
	}
}

void	ft_aff(t_token *first)
{
	t_token	*temp;

	temp = first;
	while (temp && temp->type != ENDLINE)
	{
		printf("%s : %i\n", temp->word, temp->type);
		temp = temp->next;
	}
}

void	ft_minishell(char *line)
{
	if (line == NULL)
		return ;
	add_history(line);
	if (ft_tok_rec(line) == 0)
		ft_parser(g_data.tok);
//test_expand(&g_data.tok);
	// ft_aff(g_data.tok);
	ft_free_toks(&g_data.tok);
	g_data.tok = NULL;
}
