/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:49:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/07 23:03:07 by bregneau         ###   ########.fr       */
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
# include <sys/stat.h>
# include <fcntl.h>

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
int		ft_check_tok(t_token *last, t_type type);
void	ft_parser(t_token *toks);
void	ft_expand(t_token **tok);

//ft_exit.c
void	ft_free_and_exit(int status);

//ft_env.c
void	ft_free_env(t_env *env);
void	ft_lstfree_env(void);
void	ft_fill_env(char **envp);

//Builtins
void	sh_echo(char **cmd);
void	sh_pwd(void);
void	sh_env(void);
void	sh_export(char **cmd);
void	export_display(void);
void	sh_cd(char **cmd);
void	sh_unset(char **cmd);
void	sh_exit(char **cmd);
int		is_builtins(char *cmd);
void	builtins_ex(char **cmd, void (*f)(char **));

//Utils
void	*ft_xmalloc(size_t size);
void	*x_malloc(size_t size);
void	freex_malloc(t_mall *mall);
char	*get_env_key(char *var);
char	*get_env_value(char *var);
void	env_add_back(t_env **alst, t_env *new);
t_env	*env_new(char *val, int env_disp);
char	*ft_get_exp(char *key);

#endif