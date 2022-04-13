/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:46:34 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/13 21:15:24 by bregneau         ###   ########.fr       */
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
	//ft_fill_env(envp);

	//sh_export(argv);
	while (1)
	{
		line = readline("Minishell$ ");
		if (line == NULL)
			break ;
		ft_minishell(line);
		free(line);
	}
	ft_free_and_exit(0);
}

// int	main(int argc, char **argv)
// {
// 	t_data	data;

// 	(void)argc;
// 	ft_bzero(&data, sizeof(data));
// 	ft_tok_rec(argv[1], &data);
// 	ft_free_toks(&data.tok);
// }
