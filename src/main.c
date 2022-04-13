/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:46:34 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/13 09:12:46 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_data;

int	main(int argc, char **argv, char **envp)
{
	//char	*line;
	
	/*if (argc != 1)
		return (0);*/
	(void)argc;
	ft_bzero(&g_data, sizeof(g_data));
	ft_fill_env(envp);

	sh_exit(argv);

	/*line = (char *)1;
	while (line)
	{
		line = readline("Minishell$ ");
		ft_minishell(line);
		free(line);
	}*/
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
