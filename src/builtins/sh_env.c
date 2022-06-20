/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:39:11 by cmarion           #+#    #+#             */
/*   Updated: 2022/06/20 16:57:48 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_env(void)
{
	t_env	*env;

	env = g_data.env;
	if (!env)
		g_data.exit_code = 1;
	while (env && env->var)
	{
		if (env->env_disp)
		{
			printf("%s", env->key);
			if (env->value)
				printf("=%s\n", env->value);
			else
				printf("=\n");
		}
		env = env->next;
	}
	g_data.exit_code = 0;
}
