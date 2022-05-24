/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:46:34 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/24 13:59:36 by bregneau         ###   ########.fr       */
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
	line = (char *)1;
	while (line)
	{
		ft_signal1();
		ft_putstr_fd(MS_PROMPT, 2);
		line = readline(NULL);
		ft_signal2();
		if (line == NULL)
			break ;
		ft_minishell(line);
		free(line);
	}
	ft_putstr_fd("exit\n", 2);
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
