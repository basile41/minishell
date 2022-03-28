/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:35:55 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/28 17:17:46 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_new_tok(char *word, t_type type)
{
	t_token *new;
	
	new = ft_calloc(1, sizeof(t_token));
	if (new == NULL)
		return (NULL);
	new->word = ft_strdup(word);
	new->type = type;
	return (new);
}

void	ft_add_tok(t_token **first, t_token *tok)
{
	t_token *curr;
	
	if (*first == NULL)
	{
		*first = tok;
		return ;
	}
	curr = *first;
	while (curr->next)
		curr = curr->next;
	curr->next = tok;
}

void	ft_free_toks(t_token **first)
{
	t_token *curr;
	t_token *next;
	

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