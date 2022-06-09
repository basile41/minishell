/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:46:34 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/09 13:51:59 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_data;

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argc;
	(void)argv;
	ft_bzero(&g_data, sizeof(g_data));
	ft_fill_env(envp);
	line = (char *)1;
	while (line)
	{
		ft_signal1();
		line = readline(MS_PROMPT);
		ft_signal2();
		if (line == NULL)
			break ;
		ft_minishell(line);
		free(line);
	}
	ft_putstr_fd("exit\n", 2);
	ft_free_and_exit(0);
}
