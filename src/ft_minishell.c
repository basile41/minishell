/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:55:25 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/10 14:57:51 by cmarion          ###   ########.fr       */
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
	printf("aff\n");
	while (temp && temp->type != ENDLINE)
	{
		printf("%s : %i\n", temp->word, temp->type);
		temp = temp->next;
	}
	printf("\n");
}

void	ft_minishell(char *line)
{
	if (line == NULL || *line == '\0')
		return ;
	add_history(line);
	ft_dup_fd(1);
	if (ft_tok_rec(line) == 0)
		ft_parser(g_data.tok);
	ft_dup_fd(3);
	ft_free_toks(&g_data.tok);
	g_data.tok = NULL;
}
