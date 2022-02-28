/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:28:03 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/28 22:31:46 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_env(char **envp, t_data *data)
{
	if (envp == NULL)
		return ;
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (ft_strncmp(*envp, "PATH=", 5) == 0)
		data->paths = ft_split(*envp + 5, ':');
}
