/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:28:00 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/08 14:54:50 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*ft_new_node(char *content)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	return (new);
}


void	ft_parse_list(char *line, t_node **btree)
{
	t_node	*node;
	char	*ptr;

	if (!line)
		return ;
	ptr = ft_strrchr(line, '|');
	if (ptr != line && ptr[-1] 
}
