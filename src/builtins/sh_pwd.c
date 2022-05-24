/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:42:57 by cmarion           #+#    #+#             */
/*   Updated: 2022/05/24 13:38:31 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_pwd(void)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, 4096);
	if (!buf)
		ft_free_and_exit(1);
	printf("%s\n", buf);
	free(buf);
	g_data.exit_code = 0;
}
