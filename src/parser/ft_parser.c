/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:57:01 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/19 17:01:41 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipeline(t_token **curr)
{
	while (*curr && (*curr)->type != OR_IF && (*curr)->type != AND_IF)
	{
		*curr = (*curr)->next;
	}
	return (0);
}

t_token	*ft_get_next_ccom(t_token *curr, int status)
{
	t_token	*temp;
	t_type	op;

	if (curr == NULL)
		return (NULL);
	op = curr->type;
	if (status != 0 && op == OR_IF || status == 0 && op == AND_IF)
		return (curr->next);
	temp = curr->next;
	while (temp && temp != curr)
		temp = temp->next;
	return (temp);
}

void	ft_parser(t_token *toks)
{
	t_token	*curr;
	int		status;

	curr = toks;
	while (curr)
	{
		status = ft_pipeline(&curr);
		curr = ft_get_next_ccom(curr, status);

	}
}
