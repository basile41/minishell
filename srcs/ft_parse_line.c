/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:24:06 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/11 22:54:33 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_op(char c)
{
	if (c == '&' || c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

void	ft_add_tok(t_token **first, char *word)
{
	t_token	*tok;

	tok = ft_newtok(word);
	//definir type
}

void	ft_parse_line(char *line, t_data *data)
{
	int		delimited;
	int		quoted;
	int		i;

	if (!line)
		return ;
	quoted = 0;
	i = -1;
	while (line[++i])
	{
		delimited = 0;
		if (line[i] == '\n')//1
			delimited = 1;
		//if(!quoted && i && ft_is_op(line[i - 1]) && line[i] == line[i])//2
		else if (!quoted && i && ft_is_op(line[i - 1]) && line[i] != line[i])//3
			delimited = 1;
		else if (!quoted && line[i] == '\'' || line[i == '\"'])//4
			quoted = 1;
		else if (!quoted && i && ft_is_op(line[i]))//6
			delimited = 1;
		else if (!quoted && ft_isblank(line[i]))//7
			delimited = 1;
		if (delimited)
		{
			ft_add_tok(&data->tok, ft_strndup(line, i));
			line += i;
			i = -1;
			while (ft_isblank(*line))
				line++;
		}
	}
}
