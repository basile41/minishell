/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:49:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/20 11:16:22 by cmarion          ###   ########.fr       */
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
# include <dirent.h>

void		ft_minishell(char *line);

//tokens
t_token		*ft_new_tok(char *word, t_type type);
t_token		*ft_add_tok(t_token *last, t_token *tok);
void		ft_free_toks(t_token **first);

//ft_parser
char		**ft_split_toks(char *s);
int			ft_tok_rec(char *line);
void		ft_parse_env(char **envp);
int			ft_heredoc(char	*delimiter);
int			ft_check_tok(t_token *last, t_type type);
int			ft_is_redir(t_type type);
void		ft_parser(t_token *toks);
t_token		*ft_expand(t_token **tok);
char		**ft_wildcard(char *address);

//exec
void		ft_pipex(t_pipeline *pl, int nb_cmds);
void		ft_pipeline(t_pipeline *pl, int nb_cmds);
void		ft_process(t_pipeline *pl);
void		ft_exec(char **cmd);

//ft_env.c
void		ft_free_env(t_env *env);
void		ft_lstfree_env(void);
char		**ft_get_env(void);
void		ft_fill_env(char **envp);

//Builtins
void		sh_echo(char **cmd);
void		sh_pwd(void);
void		sh_env(void);
void		sh_export(char **cmd);
void		export_display(void);
void		sh_cd(char **cmd);
void		sh_unset(char **cmd);
void		sh_exit(char **cmd);
int			is_builtins(char *cmd);
void		builtins_ex(char **cmd);

//Utils
void		*ft_xmalloc(size_t size);
void		*x_malloc(size_t size);
char		*get_env_key(char *var);
char		*get_env_value(char *var);
void		env_add_back(t_env **alst, t_env *new);
t_env		*env_new(char *val, int env_disp);
char		*ft_get_value(char *key);
char		*ft_get_path(char *cmd_name);
void		ft_free_and_exit(int status);
void		ft_exit_perror(char *message);
//pipex
void		ft_expand_cmd(t_pipeline *pl);
char		**ft_toks_to_strs(t_pipeline *pl);

void	ft_aff(t_token *first);

#endif