/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:55:25 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/03 16:35:22 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_aff(t_token *first)
{
	t_token	*temp;

	temp = first;
	while (temp)
	{
		printf("%s : %i\n", temp->word, temp->type);
		temp = temp->next;
	}
}

void	ft_minishell(char *line, t_data *data)
{
	if (line == NULL)
		return ;
	add_history(line);
	ft_tok_rec(line, data);
	ft_aff(data->tok);
	ft_free_toks(&data->tok);
	data->tok = NULL;
}
