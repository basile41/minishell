/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:46:34 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/14 15:44:19 by cmarion          ###   ########.fr       */
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
	//builtins_ex(argv, (void (*))argv[1]);
	line = (char *)1;
	while (line)
	{
		line = readline("Minishell$ ");
		if (line == NULL)
			break ;
		ft_minishell(line);
		free(line);
	}
	ft_putstr("exit\n");
	ft_free_and_exit(g_data.exit_code);
}
