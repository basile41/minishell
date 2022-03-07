/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:49:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/03 22:25:12 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	*line;
	char	**paths;
}	t_data;

typedef struct s_process
{
	int		pipefd[2];
	pid_t	*child;
	char	**cmd;
	char	*nextcmd;
	int		pipe;
}	t_process;

//ft_parse_env.c
void	ft_parse_env(char **envp, t_data *data);

//ft_exit.c
void	ft_free_and_exit(t_data *data, int status);

#endif