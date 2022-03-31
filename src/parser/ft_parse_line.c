/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:33:44 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/31 18:58:45 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_type	ft_get_type(char *s)
{
	if (ft_strncmp(s, "&&", 2) == 0)
		return (AND_IF);
	if (ft_strncmp(s, "||", 2) == 0)
		return (OR_IF);
	if (ft_strncmp(s, "<<", 2) == 0)
		return (DLESS);
	if (ft_strncmp(s, ">>", 2) == 0)
		return (DGREAT);
	if (*s == '|')
		return (PIPE);
	if (*s == '<')
		return (LESS);
	if (*s == '>')
		return (GREAT);
	if (*s == '(')
		return (L_PARENTH);
	if (*s == ')')
		return (R_PARENTH);
	return (WORD);
}

int	ft_heredoc(char	*delimiter)
{
	char	*line;
	int		pipefd[2];

	pipe(pipefd);
	line = readline("heredoc> ");
	while (line && ft_strcmp(line, delimiter))
	{
		write(pipefd[1], line, ft_strlen(line));
		free(line);
		line = readline("heredoc> ");
	}
	free(line);
	close(pipefd[1]);
	return (pipefd[0]);
}

int	ft_tok_rec(char *line, t_data *data)
{
	char	**strs;
	t_token	*tok;
	int		i;

	strs = ft_split_toks(line);
	if (strs == NULL)
		return (0);
	i = 0;
	tok = data->tok;
	while (strs[i])
	{
		tok = ft_add_tok(&tok, ft_new_tok(strs[i], ft_get_type(strs[i])));
		if (tok->type == DLESS)
		{
			ft_heredoc(strs[++i]);
		}
		i++;
	}
	ft_free_strs(strs);
	return (1);
}
