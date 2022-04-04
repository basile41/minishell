/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:13:28 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/01 19:14:07 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_heredoc(char	*delimiter)
{
	char	*line;
	int		pipefd[2];

	pipe(pipefd);
	line = readline("heredoc> ");
	while (line && ft_strcmp(line, delimiter))
	{
		write(pipefd[1], line, ft_strlen(line));
		free(line);
		line = readline("heredoc> ");
	}
	free(line);
	close(pipefd[1]);
	return (pipefd[0]);
}
