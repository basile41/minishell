/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:24:06 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/11 19:31:24 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_op(char c)
{
	if (c == '&' || c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

void	ft_parse_line(char *line, t_data *data)
{
	t_token	*tok;
	int		delimited;
	int		quoted;
	int		i;

	if (!line)
		return ;
	quoted = 0;
	delimited = 0;
	i = 0;
	while (line[i])
	{
		//if (i && ft_is_op(line[i - 1]) && line[i - 1] == line[i])
		if (i && ft_is_op(line[i - 1]) && line[i - 1] != line[i])
			delimited = 1;
		else if (line[i] == '\'' || line[i == '\"'])
		
		i++;
	}
	
}
