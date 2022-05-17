/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:54:54 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/17 19:04:45 by bregneau         ###   ########.fr       */
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

int	ft_if_subshell(t_pipeline *pl)
{
	t_token	*curr;

	curr = pl->start;
	while (curr != pl->end && curr->type != PIPE)
	{
		if (curr->type == L_PARENTH)
		{
			ft_subshell()
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}

void	ft_simple_cmd(t_pipeline *pl)
{
	t_token	*tok;
	char	**cmd;

	ft_expand_cmd(pl);
	tok = pl->start;
	cmd = ft_toks_to_strs(pl);
	if (cmd == NULL)
		return ;
	if (is_builtins(*cmd))
	{
		builtins_ex(cmd);
		close(STDOUT_FILENO);
		open("/dev/tty", O_WRONLY);
		close(STDIN_FILENO);
		open("/dev/tty", O_RDONLY);
	}
	// else
	// 	;//exec
	free(cmd);
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
