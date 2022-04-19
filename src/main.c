/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:46:34 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/19 17:05:42 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_data;

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argc;
	(void)argv;
	(void)envp;
	ft_bzero(&g_data, sizeof(g_data));
	ft_fill_env(envp);

	//builtins_ex(argv, (void (*)(char **))argv[1]);

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
	ft_free_and_exit(0);
}
