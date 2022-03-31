/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:39:11 by cmarion           #+#    #+#             */
/*   Updated: 2022/03/31 14:39:47 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_env(t_data *data)
{
	t_env	*env;

	env = data->env;
	while(env)
	{
		if (ft_strchr(env->var, '='))
			printf("%s\n", env->var);
		env = env->next;
	}
}