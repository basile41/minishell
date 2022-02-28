/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:02:38 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/28 15:26:44 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>


int	main(int argc, char **argv, char **envp)
{
	char *line;

	line = NULL;
	while (1)
	{
		line = readline("minishell: ");
		//printf("%s/n", line);
		printf("prout");
		add_history(line);
		execve(argv[1], argv + 1, envp);
		free(line);
	}
	//clear_history();
}