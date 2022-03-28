/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:46:34 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/28 17:13:31 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_aff(t_token *first)
{

	//printf("%s : %i\n", first->word, first->type);
	while (first)
	{
		printf("%s : %i\n", first->word, first->type);
		first = first->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*line;

	if (argc != 1)
		return (0);
	(void)argv;
	ft_bzero(&data, sizeof(data));
	(void)envp;
	//ft_parse_env(envp, &data);
	line = (char *)1;
	while (line)
	{
		line = readline("Minishell$ ");
		ft_minishell(line, &data);
		//ft_aff(data.tok);
		free(line);
	}
	ft_free_and_exit(&data, 0);
}
