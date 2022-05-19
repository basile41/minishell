/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:54:54 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/19 17:07:33 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_last_cmd(t_pipeline *pl, pid_t *child);

void	ft_simple_cmd(t_pipeline *pl, pid_t *child)
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
		ft_last_cmd(pl, child);
	free(cmd);
}

void	ft_pipex(t_pipeline *pl, int nb_cmds)
{
	t_token	*tok;
	pid_t	*childs;
	int		i;

	childs = malloc((nb_cmds + 1) * sizeof(*childs));
	if (childs == NULL)
		ft_exit_perror("malloc");
	memset(childs, 0, (nb_cmds + 1) * sizeof(*childs));
	tok = pl->start;
	if (nb_cmds == 1)
		ft_simple_cmd(pl, childs);
	else
		ft_pipeline(pl, nb_cmds, childs);
	i = 0;
	while (i < nb_cmds && childs[i])
		waitpid(childs[i++], &g_data.exit_code, 0);
	free(childs);
}
