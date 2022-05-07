/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:41:08 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/07 15:15:40 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_quoted
{
	NOT_QUOTED,
	QUOTED,
	DQUOTED
}	t_quoted;

typedef struct s_env
{
	char			*var;
	char			*key;
	char			*value;
	int				env_disp;
	struct s_env	*next;
}	t_env;

typedef struct s_mall
{
	char			*var;
	struct s_mall	*next;
}	t_mall;

typedef enum type
{
	WORD,
	ASSIGNMENT_WORD,
	NAME,
	ENDLINE,
	IO_NUMBER,
	AND_IF,
	OR_IF,
	LESS,
	GREAT,
	DLESS,
	DGREAT,
	PIPE,
	L_PARENTH,
	R_PARENTH
}	t_type;

typedef struct s_token
{
	char			*word;
	t_type			type;
	struct s_token	*sub;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_clist
{
	t_token			*start;
	t_token			*end;
	struct s_clist	*next;
}	t_clist;

typedef struct s_global
{
	t_env	*env;
	t_mall	*mall;
	t_token	*tok;
	int		env_size;
	int		exit_code;
}	t_global;

extern t_global	g_data;

#endif