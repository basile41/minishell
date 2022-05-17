/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:37:25 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/16 19:12:44 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_redirections(t_pipeline *pl)
{

}

void	ft_process(t_pipeline *pl)
{
	char **cmd;

	cmd = ft_toks_to_strs(pl);

	ft_free_strs(cmd);
}
