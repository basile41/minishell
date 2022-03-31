/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:42:57 by cmarion           #+#    #+#             */
/*   Updated: 2022/03/29 11:50:43 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sh_pwd(t_data *data)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, 4096);
	if (!buf)
		ft_free_and_exit(data, 1);
	printf("%s\n", buf);
	free(buf);
}
