/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:24:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/08 19:39:03 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_quoted	ft_set_quoted(t_quoted q, char c);
char		*ft_delete_quotes(char	*s);
int			ft_q_size(char *s);
int			ft_expand_status(t_token **tok_exp);

void	ft_split_exp(t_token **tok_exp, char *value)
{
	char	**strs;
	int		i;

	strs = ft_split_f(value, isblank);
	if (strs != NULL && ft_isblank(*value) && (*tok_exp)->word)
		*tok_exp = ft_add_tok(*tok_exp, ft_new_tok(NULL, WORD));
	i = 0;
	while (strs[i])
	{
		(*tok_exp)->word = ft_add_to_str((*tok_exp)->word, strs[i],
				ft_strlen(strs[i]));
		if (strs[++i])
			*tok_exp = ft_add_tok(*tok_exp, ft_new_tok(NULL, WORD));
	}
	ft_free_strs(strs);
}

int	ft_expand_dollar(t_token **tok_exp, char *str, int quoted)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	if (*(++str) == '?')
		return (ft_expand_status(tok_exp));
	if (ft_isalpha(*(str)) == 0)
		return (i);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	key = ft_strndup(str, i);
	if (key == NULL)
		return (i);
	value = ft_get_value(key);
	free(key);
	if (value == NULL)
		return (i);
	if (quoted == DQUOTED)
		(*tok_exp)->word = ft_add_to_str((*tok_exp)->word,
				value, ft_strlen(value));
	else
		ft_split_exp(tok_exp, value);
	free(value);
	return (i);
}

t_token	*ft_do_expand_in(t_token *tok_exp, char **word, t_quoted quoted)
{
	if (quoted == QUOTED)
	{
		tok_exp->word = ft_add_to_str(tok_exp->word, *word + 1,
				ft_q_size(*word));
		*word += ft_q_size(*word) + 1;
	}
	else if (**word == '$')
		*word += ft_expand_dollar(&tok_exp, *word, quoted);
	else if (quoted == DQUOTED && **word != '\"')
		tok_exp->word = ft_add_to_str(tok_exp->word, *word, 1);
	return (tok_exp);
}

t_token	*ft_do_expand(t_token *tok_exp, char *word)
{
	t_quoted	quoted;
	int			i;

	i = 0;
	quoted = NOT_QUOTED;
	while (word[i])
	{
		quoted = ft_set_quoted(quoted, word[i]);
		if (quoted != 0 || word[i] == '$' || word[i] == '\"'
			|| (!word[i + 1] && ++i))
		{
			if (i)
				tok_exp->word = ft_add_to_str(tok_exp->word, word, i);
			word += i;
			i = 0;
			tok_exp = ft_do_expand_in(tok_exp, &word, quoted);
			if (*word)
				word++;
		}
		else
			i++;
	}
	return (tok_exp);
}

t_token	*ft_expand(t_token **tok)
{
	t_token		*start;
	t_token		*end;
	t_token		*tmp;
	char		*word;

	tmp = *tok;
	word = (*tok)->word;
	if ((*tok)->type != WORD && 0 == (ft_strchr(word, '$')
			|| ft_strchr(word, '\'') || ft_strchr(word, '\"')))
		return (*tok);
	*tok = ft_new_tok(NULL, WORD);
	start = *tok;
	end = ft_do_expand(*tok, word);
	if (tmp->prev)
		ft_add_tok(tmp->prev, start);
	else
		g_data.tok = start;
	*tok = end;
	if (tmp->next)
		ft_add_tok(*tok, tmp->next);
	free(tmp->word);
	free(tmp);
	return (start);
}
