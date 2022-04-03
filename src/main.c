/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:46:34 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/03 19:55:19 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*line;

	if (argc != 1)
		return (0);
	(void)argv;
	ft_bzero(&data, sizeof(data));
	(void)envp;
	ft_fill_env(envp, &data.env);
	//sh_env(&data);
	line = (char *)1;
	while (line)
	{
		line = readline("Minishell$ ");
		ft_minishell(line, &data);
		free(line);
	}
	ft_free_and_exit(&data, 0);
}

// int	main(int argc, char **argv)
// {
// 	t_data	data;

// 	(void)argc;
// 	ft_bzero(&data, sizeof(data));
// 	ft_tok_rec(argv[1], &data);
// 	ft_free_toks(&data.tok);
// }
