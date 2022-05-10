/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:24:38 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/09 21:19:46 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*x_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		ft_free_and_exit(1);
	ft_lstadd_back((t_list **)g_data.mall, (t_list *)ft_lstnew(ret));
	return (ret);
}

void	freex_malloc(t_mall *mall)
{
	t_mall	*temp;

	temp = mall;
	while (temp)
	{
		free(temp->var);
		temp = temp->next;
	}
}
