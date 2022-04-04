/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:42:57 by cmarion           #+#    #+#             */
/*   Updated: 2022/04/04 17:04:23 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
