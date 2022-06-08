/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:39:30 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/08 19:08:30 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_expand_cmd(t_pipeline *pl)
{
	t_token	*tok;

	tok = pl->start->next;
	pl->start = ft_expand(&pl->start);
	// 	printf("%s\n", pl->start->word);
	// ft_expand(&pl->start);
	while (tok != pl->end && tok->type != PIPE)
	{
		// printf("%s\n", (tok)->word);
		ft_expand(&tok);
		tok = tok->next;
	}
}

void	ft_redir(t_token *tok)
{
	int	fd;

	fd = ft_atoi(tok->word);
	if (tok->prev->type == DLESS || tok->prev->type == LESS)
		dup2(fd, STDIN_FILENO);
	else
		dup2(fd, STDOUT_FILENO);
	close(fd);
}

char	**ft_expand_wildc(char **cmd, int *pos, char *word)
{
	char	**wc;
	int		size;
	int		i;

	if (ft_strchr(word, '*'))
	{
		wc = ft_wildcard(word);
		size = tabchar_len(wc);
		cmd = ft_realloc(cmd, (*pos + 1) * sizeof(*cmd),
				(*pos + size + 1) * sizeof(*cmd));
		if (cmd == NULL)
			return (NULL);
		i = -1;
		while (++i < size)
			cmd[*pos + i] = wc[i];
		cmd[*pos + i] = NULL;
		*pos += i - 1;
		free(wc);
		return (cmd);
	}
	cmd = ft_realloc(cmd, (*pos + 1) * sizeof(*cmd), (*pos + 2) * sizeof(*cmd));
	cmd[*pos] = ft_strdup(word);
	cmd[*pos + 1] = NULL;
	return (cmd);
}

char	**ft_toks_to_strs(t_pipeline *pl)
{
	t_token	*tok;
	char	**cmd;
	int		i;

	tok = pl->start;
	i = 0;
	cmd = NULL;
	while (tok->word && tok != pl->end && tok->type != PIPE)
	{
		if (tok->type == WORD)
		{
			cmd = ft_expand_wildc(cmd, &i, tok->word);
			i++;
		}
		if (tok->type == IO_NUMBER)
			ft_redir(tok);
		tok = tok->next;
	}
	if (cmd)
		cmd[i] = NULL;
	return (cmd);
}
