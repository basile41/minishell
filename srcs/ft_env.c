/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:46:41 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/07 19:35:42 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fill_env(char **envp, t_env **env)
{
	*env = (t_env *)ft_lstnew(envp[0]);
	envp++;
	while (*envp)
	{
		ft_lstadd_back((t_list **)env, (t_list *)ft_lstnew(*envp));
		envp++;
	}
}
