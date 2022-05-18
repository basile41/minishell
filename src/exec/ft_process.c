/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:37:25 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/18 19:23:48 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_process(t_pipeline *pl)
{
	char	**cmd;

	ft_expand_cmd(pl);
	cmd = ft_toks_to_strs(pl);
	if (cmd == NULL)
		exit(EXIT_SUCCESS);
	ft_exec(cmd);
	ft_free_strs(cmd);
}
