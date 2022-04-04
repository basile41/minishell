/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:49:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/04 17:10:06 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "structs.h"
# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>

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

void	ft_minishell(char *line);

//tokens
t_token	*ft_new_tok(char *word, t_type type);
t_token	*ft_add_tok(t_token **last, t_token *tok);
void	ft_free_toks(t_token **first);

//ft_parser
char	**ft_split_toks(char *s);
int		ft_tok_rec(char *line);
void	ft_parse_env(char **envp);
int		ft_heredoc(char	*delimiter);

//ft_exit.c
void	ft_free_and_exit(int status);

void	ft_fill_env(char **envp, t_env **env);

//Builtins
void	sh_echo(char **cmd);
void	sh_pwd(t_data *data);
void	sh_env(t_data *data);
void	sh_export(t_data *data, char **cmd);

//Malloc
void	*x_malloc(t_data *data, size_t size);
void	freex_malloc(t_mall *mall);

#endif