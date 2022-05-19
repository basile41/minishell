/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:46:34 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/19 14:21:13 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_data;

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	*prompt;

	(void)argc;
	(void)argv;
	ft_bzero(&g_data, sizeof(g_data));
	ft_fill_env(envp);

	if (isatty(STDIN_FILENO))
		prompt = ft_strdup("Minishell$ ");
	else
		prompt = ft_strdup("");

	//builtins_ex(argv, (void (*)(char **))argv[1]);

	line = (char *)1;
	while (line)
	{
		tcsetattr()
		line = readline(prompt);
		if (line == NULL)
			break ;
		ft_minishell(line);
		free(line);
	}
	ft_putstr_fd("exit\n", 2);
	free(prompt);
	ft_free_and_exit(0);
}

// int main(int ac, char **av)
// {
// 	t_token	*tok;
// 	t_token	*curr;

// 	(void)ac;
// 	tok = ft_new_tok(*av++, WORD);
// 	curr = tok;
// 	while (*av)
// 	{
// 		curr = ft_add_tok(&curr, ft_new_tok(*av, WORD));
// 		av++;
// 	}
// 	while (curr->prev)
// 	{
// 		printf("%s\n", curr->word);
// 		curr = curr->prev;
// 	}
// 	printf("\n");
// 	while (curr->next)
// 	{
// 		printf("%s\n", curr->word);
// 		curr = curr->next;
// 	}

// }
