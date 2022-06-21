/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:37:25 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/21 16:12:07 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_process(t_pipeline *pl)
{
	char	**cmd;

	ft_expand_cmd(pl);
	cmd = ft_toks_to_strs(pl);
	if (cmd == NULL)
		ft_free_and_exit(EXIT_SUCCESS);
	if (is_builtins(*cmd))
	{
		builtins_ex(cmd);
		ft_free_and_exit(g_data.exit_code);
	}
	else
		ft_exec(cmd);
	ft_free_strs(cmd);
}
