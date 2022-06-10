/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:02:16 by cmarion           #+#    #+#             */
/*   Updated: 2022/06/10 15:02:22 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_open_redir(t_token *tok)
{
	int	fd;

	if (tok->type == LESS)
		fd = open(tok->next->word, O_RDONLY);
	if (tok->type == GREAT)
		fd = open(tok->next->word, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
				| S_IRGRP | S_IROTH | S_IWUSR);
	if (tok->type == DGREAT)
		fd = open(tok->next->word, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR
				| S_IRGRP | S_IROTH | S_IWUSR);
	if (fd == -1)
	{
		ft_del_cmd(&tok->next->next);
		perror(tok->next->word);
	}
	free(tok->next->word);
	tok->next->word = ft_itoa(fd);
	tok->next->type = IO_NUMBER;
}
