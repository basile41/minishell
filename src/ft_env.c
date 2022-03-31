/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:46:41 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/31 18:13:41 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fill_env(char **envp, t_data *data)
{
	int	i;

	data->env = (t_env *)ft_lstnew(envp[0]);
	i = 1;
	while (envp[i])
	{
		ft_lstadd_back((t_list **)&data->env, (t_list *)ft_lstnew(envp[i]));
		i ++;
	}
	data->env_size = i;
}
