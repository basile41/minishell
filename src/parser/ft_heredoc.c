/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:13:28 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/20 14:42:41 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_create_tmp_file(char *here_doc)
{
	int				fd;

	fd = open(HD_TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
			| S_IRGRP | S_IROTH | S_IWUSR);
	if (fd == -1)
		perror("open");
	if (here_doc != NULL)
		write(fd, here_doc, ft_strlen(here_doc));
	close(fd);
	fd = open(HD_TMP_FILE, O_RDONLY);
	if (fd == -1)
		perror("open");
	unlink(HD_TMP_FILE);
	return (fd);
}

int	ft_heredoc(char	*delimiter)
{
	char	*line;
	char	*here_doc;
	int		fd;

	here_doc = NULL;
	signal(SIGINT, ft_handler_hd);
	line = readline("> ");
	while (line && ft_strcmp(line, delimiter))
	{
		here_doc = ft_add_to_str(here_doc, line, ft_strlen(line));
		here_doc = ft_add_to_str(here_doc, "\n", 1);
		free(line);
		line = readline("> ");
	}
	ft_signal2();
	free(line);
	fd = ft_create_tmp_file(here_doc);
	free(here_doc);
	return (fd);
}
