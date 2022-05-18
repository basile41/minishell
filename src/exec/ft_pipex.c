/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:54:54 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/18 21:24:46 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_last_cmd(t_pipeline *pl);

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
		builtins_ex(cmd);
	else
		ft_last_cmd(pl);
	free(cmd);
}

int	ft_pipex(t_pipeline *pl, int nb_cmds)
{
	t_token	*tok;

	tok = pl->start;
	if (nb_cmds == 1)
		ft_simple_cmd(pl);
	else
		ft_pipeline(pl, nb_cmds);
	return (0);
}
