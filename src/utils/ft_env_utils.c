/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:19:53 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/11 14:11:41 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_value(char *key)
{
	t_env	*curr;

	curr = g_data.env;
	while (curr)
	{
		if (ft_strcmp(curr->key, key) == 0)
			return (strdup(curr->value));
		curr = curr->next;
	}
	return (NULL);
}
