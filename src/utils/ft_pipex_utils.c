/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:39:30 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/16 20:45:16 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redir(t_token *tok)
{
	int	fd;

	fd = ft_atoi(tok->word);
	if (tok->prev->type == DLESS || tok->prev->type == LESS)
		dup2(fd, STDIN_FILENO);
	else
		dup2(fd, STDOUT_FILENO);
}

char	**ft_toks_to_strs(t_pipeline *pl)
{
	t_token	*tok;
	char	**cmd;
	int		i;

	tok = pl->start;
	i = 0;
	cmd = NULL;
	while (tok != pl->end && tok->type != PIPE)
	{
		if (tok->type == WORD)
		{
			cmd = ft_realloc(cmd, (i + 1) * sizeof(*cmd),
					(i + 2) * sizeof(*cmd));
			if (cmd == NULL)
				return (NULL);
			cmd[i] = tok->word;
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
