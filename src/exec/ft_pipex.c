/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:54:54 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/12 11:26:02 by bregneau         ###   ########.fr       */
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

void	ft_simple_cmd(t_pipeline *pl)
{
	t_token	*tok;
	char	**cmd;

	ft_expand_cmd(pl);
	tok = pl->start;
	cmd = ft_toks_to_strs(pl);
	if (is_builtins(*cmd))
		builtins_ex(cmd);
	// else
	// 	;//exec
}

int	ft_pipex(t_pipeline *pl, int nb_cmds)
{
	t_token	*tok;

	tok = pl->start;
	if (nb_cmds == 1)
		ft_simple_cmd(pl);
	// else
	// 	//exec
	return (0);
}
