/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:41:08 by bregneau          #+#    #+#             */
/*   Updated: 2022/04/06 19:03:17 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	NEWLINE,
	IO_NUMBER,
	AND_IF,
	OR_IF,
	LESS,
	GREAT,
	DLESS,
	DGREAT,
	PIPE,
	L_PARENTH,
	R_PARENTH,
}	t_type;

typedef struct s_token
{
	char			*word;
	t_type			type;
	struct s_token	*sub;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_global
{
	t_env	*env;
	t_mall	*mall;
	t_token	*tok;
	int		env_size;
}	t_global;

extern t_global	g_data;

#endif