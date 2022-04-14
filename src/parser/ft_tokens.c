/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:35:55 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/06 20:05:25 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_new_tok(char *word, t_type type)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->word = ft_strdup(word);
	new->type = type;
	return (new);
}

t_token	*ft_add_tok(t_token **last, t_token *tok)
{
	//t_token *curr;

	if (*last == NULL)
		*last = tok;
	else
	{
		(*last)->next = tok;
		tok->prev = *last;
		// curr = *last;
		// while (curr->next)
		// 	curr = curr->next;
		// curr->next = tok;
		// tok->prev = curr;
	}
	return (tok);
}

void	ft_free_toks(t_token **first)
{
	t_token	*curr;
	t_token	*next;

	if (*first == NULL)
		return ;
	curr = *first;
	while (curr)
	{
		next = curr->next;
		free(curr->word);
		free(curr);
		curr = next;
	}
	*first = NULL;
}
