/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:57:01 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/10 20:19:43 by bregneau         ###   ########.fr       */
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
	if (fd < 0)
		perror("minishell");
	free(tok->next->word);
	tok->next->word = ft_itoa(fd);
}

int	ft_pipeline(t_token **toks)
{
	//int	status;
	int			nb_cmds;
	t_pipeline	pl;

	pl.start = *toks;
	//if (*toks)
	//	printf("%s\n", (*toks)->word);
	nb_cmds = 1;
	while (*toks && (*toks)->type != OR_IF && (*toks)->type != AND_IF)
	{
		if ((*toks)->type == PIPE)
			nb_cmds++;
		if ((*toks)->type == LESS || (*toks)->type == GREAT || (*toks)->type == DGREAT)
			ft_open_redir(*toks);
		*toks = (*toks)->next;
	}
	pl.end = *toks;
	return (ft_pipex(&pl, nb_cmds));
}

t_token	*ft_get_next_ccom(t_token *curr, int status)
{
	t_token	*temp;
	t_type	op;

	if (curr == NULL)
		return (NULL);
	op = curr->type;
	if ((status != 0 && op == OR_IF) || (status == 0 && op == AND_IF))
		return (curr->next);
	temp = curr->next;
	if (op == OR_IF)
		while (temp && temp->type != AND_IF)
			temp = temp->next;
	if (op == AND_IF)
		while (temp && temp->type != OR_IF)
			temp = temp->next;
	if (temp == NULL)
		return (NULL);
	return (temp->next);
}

void	ft_parser(t_token *toks)
{
	t_token	*curr;
	int		status;

	curr = toks;
	while (curr)
	{
		// if (curr)
		// 	printf("%s\n", curr->word);
		status = ft_pipeline(&curr);
		curr = ft_get_next_ccom(curr, status);
	}
}
