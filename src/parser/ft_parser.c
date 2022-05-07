/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:57:01 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/07 22:52:43 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	ft_execution(t_token *first, t_token *last)
// {
// 	char	**cmd;

// 	while (first && first != last && first->type != PIPE)
// 	{
// 	}
// }

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

void	ft_split_exp(t_token **tok_exp, char *value)
{
	char	**strs;
	int		i;

	strs = ft_split_f(value, isblank);
	i = 0;

	while (strs[i])
	{
		(*tok_exp)->word = ft_add_to_str((*tok_exp)->word, strs[i],
				ft_strlen(strs[i]));
		if (strs[++i])
			*tok_exp = ft_add_tok(tok_exp, ft_new_tok(NULL, WORD));
	}
	ft_free_strs(strs);
}

int	ft_expand_dollar(t_token **tok_exp, char *str, int quoted)
{
	int		i;
	char	*value;

	i = 1;
	if (ft_isalpha(str[i]) == 0)
		return (i);
	while (str[i] && ft_isalnum(str[i]))
		i++;
	value = ft_strndup(ft_get_exp(str + i + 1), i - 1);
	if (quoted == DQUOTED)
		(*tok_exp)->word = ft_add_to_str((*tok_exp)->word, value, i - 1);
	else
	{
		ft_split_exp(tok_exp, value);
	}
	free(value);
	return (i);
}

t_quoted	ft_set_quoted(t_quoted q, char c)
{
	if (c == '\'' && q == NOT_QUOTED)
		return (QUOTED);
	if (c == '\'' && q == QUOTED)
		return (NOT_QUOTED);
	if (c == '\"' && q == NOT_QUOTED)
		return (DQUOTED);
	if (c == '\"' && q == DQUOTED)
		return (NOT_QUOTED);
	return (q);
}

char	*ft_delete_quotes(char	*s)
{
	return (ft_substr(s, 1, ft_strchr(s + 1, *s) - s + 1));
}

int	ft_q_size(char *s)
{
	return (ft_strchr(s + 1, *s) - s + 1);
}

t_token	*ft_expand_in(t_token *tok_exp, char *word)
{
	t_quoted	quoted;
	int			i;

	i = 0;
	quoted = NOT_QUOTED;
	while (word[i])
	{
		quoted = ft_set_quoted(quoted, word[i]);
		if (i && quoted == DQUOTED)
		{
			tok_exp->word = ft_add_to_str(tok_exp->word, word, i - 1);
			i = 0;
		}
		if (quoted == QUOTED)
		{
			tok_exp->word = ft_add_to_str(tok_exp->word, word, i - 1);
			tok_exp->word = ft_add_to_str(tok_exp->word, &word[i + 1],
					ft_q_size(&word[i]));
			word += ft_q_size(word + i) + 1 + i;
			i = 0;
		}
		else if (quoted == DQUOTED && word[i] != '\"')
			tok_exp->word = ft_add_to_str(tok_exp->word, word, 1);
		else if (word[i] == '$')
			word += ft_expand_dollar(&tok_exp, word + i, quoted);
		else
			i++;
	}
	return (tok_exp);
}

void	ft_expand(t_token **tok)
{
	t_token		*tok_exp;
	char		*word;

	word = (*tok)->word;
	if (0 == (ft_strchr(word, '$') && ft_strchr(word, '\'')
			&& ft_strchr(word, '\"')))
		return ;
	tok_exp = ft_new_tok(NULL, WORD);
	(*tok)->prev->next = tok_exp;
	tok_exp->prev = (*tok)->prev;
	tok_exp = ft_expand_in(tok_exp, word);
	tok_exp->next = (*tok)->next;
	(*tok)->next->prev = tok_exp;
}

int	ft_pipeline(t_token **toks)
{
	//int	status;
	t_token	*curr;
	int		nb_pipes;

	// if (*toks)
	// 	printf("%s\n", (*toks)->word);
	curr = *toks;
	nb_pipes = 0;
	while (curr && curr->type != OR_IF && curr->type != AND_IF)
	{
		if (curr->type == PIPE)
			nb_pipes++;
		if (curr->type == LESS || curr->type == GREAT || curr->type == DGREAT)
			ft_open_redir(curr);
		// if (curr->type == WORD)

		curr = curr->next;
	}

	// ft_execution(toks, curr);
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
