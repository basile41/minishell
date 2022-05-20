/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:13:28 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/20 12:27:52 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	ft_exit_unlink(char *file, int fd, char *message);

int	ft_create_tmp_file(char *here_doc)
{
	static size_t	i;
	int				fd;
	char			*tmp_file;

	tmp_file = ft_itoa(i);
	if (tmp_file)
		tmp_file = ft_strjoin("/tmp/-ms-thd-", tmp_file);
	if (tmp_file == NULL)
		ft_exit_perror("malloc");
	fd = open(tmp_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
			| S_IRGRP | S_IROTH | S_IWUSR);
	if (fd == -1)
		ft_exit_perror("open");
	if (here_doc != NULL)
		write(fd, here_doc, ft_strlen(here_doc));
	close(fd);
	fd = open(tmp_file, O_RDONLY);
	if (fd == -1)
		ft_exit_perror("open");
	unlink(tmp_file);
	i++;
	return (fd);
}

int	ft_heredoc(char	*delimiter)
{
	char	*line;
	char	*here_doc;
	int		fd;

	here_doc = NULL;
	line = readline("> ");
	while (line && ft_strcmp(line, delimiter))
	{
		here_doc = ft_add_to_str(here_doc, line, ft_strlen(line));
		here_doc = ft_add_to_str(here_doc, "\n", 1);
		free(line);
		line = readline("> ");
	}
	free(line);
	fd = ft_create_tmp_file(here_doc);
	free(here_doc);
	return (fd);
}

// int	ft_heredoc(char	*delimiter)
// {
// 	char	*line;
// 	int		pipefd[2];

// 	pipe(pipefd);
// 	line = readline("heredoc> ");
// 	while (line && ft_strcmp(line, delimiter))
// 	{
// 		write(pipefd[1], line, ft_strlen(line));
// 		free(line);
// 		line = readline("heredoc> ");
// 	}
// 	free(line);
// 	close(pipefd[1]);
// 	return (pipefd[0]);
// }