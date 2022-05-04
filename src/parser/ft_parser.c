/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:57:01 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/04 21:31:57 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execution(t_token *first, t_token *last)
{
	char	**cmd;

	while (first && first != last && first->type != PIPE)
	{
	}
}

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

void	ft_expand_dollars(char *str)
{
	
}

char	ft_expand(char *word)
{
	int		i;
	int		j;
	int		dquoted;

	i = -1;
	str = NULL;
	while (word && word[i])
	{
		if (word[i] == '$' || word[i] == '\'' || word[i] == '\"')
		{
			str = ft_add_to_str(str, word, i - 1);
		}
		if (word[i] == '\'')
		{
			j = 1;
			while (word[i + j] != '\'')
				j++;
			str = ft_add_to_str(str, &word[i + 1], j - 2);
			word += i + j + 1;
			i = 0;
		}
		if (word[i] == '$' && ft_isalpha(word[i + 1]) )
			ft_expand_dollars(word + i);

	}
}

int	ft_pipeline(t_token **toks)
{
	//int	status;
	t_token	*curr;
	int		nb_pipes;

	if (*toks)
		printf("%s\n", (*toks)->word);
	curr = toks;
	nb_pipes = 0;
	while (curr && curr->type != OR_IF && curr->type != AND_IF)
	{
		if (curr->type == PIPE)
			nb_pipes++;
		if (curr->type == LESS || curr->type == GREAT || curr->type == DGREAT)
			ft_open_redir(curr);
		if (curr->type == WORD)

		curr = curr->next;
	}

	ft_execution(toks, curr);
	return (0);
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
		status = ft_pipeline(&curr);
		curr = ft_get_next_ccom(curr, status);
	}
}
