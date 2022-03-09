/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:49:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/08 19:51:33 by bregneau         ###   ########.fr       */
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
	char	**strs;
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

typedef struct s_pipeline
{
	int		redir_in;
	int		redir_out;
	char	**cmd;
}	t_pipeline;

typedef struct s_env
{
	char			*var;
	struct s_env	*next;
}	t_env;

typedef struct s_node
{
	char			*content;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_node;

//ft_parse_env.c
void	ft_parse_env(char **envp, t_data *data);

//ft_exit.c
void	ft_free_and_exit(t_data *data, int status);

void	ft_fill_env(char **envp, t_env **env);

#endif