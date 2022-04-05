/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:39:11 by cmarion           #+#    #+#             */
/*   Updated: 2022/03/31 18:54:39 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_env(void)
{
	t_env	*env;

	env = g_data.env;
	while (env)
	{
		if (env->env_disp)
		{
			printf("%s", env->key);
			if (env->value)
				printf("=%s", env->value);
			printf("\n");
		}
		env = env->next;
	}
}
