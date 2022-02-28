/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:19:39 by bregneau          #+#    #+#             */
/*   Updated: 2021/12/04 05:59:46 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;

	start = NULL;
	if (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			return (NULL);
		start = new;
		while (lst->next)
		{
			lst = lst->next;
			new->next = ft_lstnew(f(lst->content));
			new = new->next;
			if (!new)
			{
				ft_lstclear(&start, del);
				return (NULL);
			}
		}
	}
	return (start);
}
