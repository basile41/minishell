/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:46:34 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/02 19:49:09 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1)
		return (0);
	(void)argv;
	ft_bzero(&data, sizeof(data));
	ft_parse_env(envp, &data);
	data.line = 1;
	while (data.line)
	{
		data.line = readline("Minishell$ ");
		add_history(data.line);
		free(data.line);
	}
	ft_free_and_exit(&data, 0);
}
