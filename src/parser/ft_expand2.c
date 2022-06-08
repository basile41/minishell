/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:21:29 by cmarion           #+#    #+#             */
/*   Updated: 2022/06/08 14:38:19 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_quoted	ft_set_quoted(t_quoted q, char c)
{
	if (c == '\'' && q == NOT_QUOTED)
		return (QUOTED);
	if (q == QUOTED)
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
	return (ft_strchr(s + 1, *s) - s - 1);
}

int	ft_expand_status(t_token **tok_exp)
{
	char	*str;

	str = ft_itoa(g_data.exit_code);
	(*tok_exp)->word = ft_add_to_str((*tok_exp)->word, str, ft_strlen(str));
	free(str);
	return (1);
}

