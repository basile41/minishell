/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:39:11 by cmarion           #+#    #+#             */
/*   Updated: 2022/03/30 13:18:08 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sh_env(t_data *data)
{
	t_env	*env;

	env = data->env;
	while(env)
	{
		if (ft_strchr(env->var, '='))
			printf("%s", env->var);
		env = env->next;
	}
}