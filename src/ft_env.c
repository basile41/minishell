/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:46:41 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/01 10:47:27 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fill_env(char **envp, t_data *data)
{
	int	i;

	data->env = env_new(envp[0], 1);
	i = 1;
	while (envp[i])
	{
		env_add_back(&data->env, env_new(envp[i], 1));
		i ++;
	}
	data->env_size = i;
}
