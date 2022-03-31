/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:46:34 by bregneau          #+#    #+#             */
<<<<<<< HEAD:srcs/main.c
/*   Updated: 2022/03/30 18:50:23 by cmarion          ###   ########.fr       */
=======
/*   Updated: 2022/03/29 17:54:52 by bregneau         ###   ########.fr       */
>>>>>>> d547056f10803a580c8da182f626aa9dd97ea4d8:src/main.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_aff(t_token *first)
{
	t_token *temp;

	temp = first;
	while (temp)
	{
		printf("%s : %i\n", temp->word, temp->type);
		temp = temp->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	//char	*line;

	if (argc != 1)
		return (0);
	(void)argv;
	ft_bzero(&data, sizeof(data));
	(void)envp;
	ft_fill_env(envp, &data.env);
	sh_export(&data, argv);
	
	
	
	/*line = (char *)1;
	while (line)
	{
		line = readline("Minishell$ ");
		ft_minishell(line, &data);
		ft_aff(data.tok);
		free(line);
	}*/
	ft_free_and_exit(&data, 0);
}
