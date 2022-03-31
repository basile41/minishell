/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:41:08 by bregneau          #+#    #+#             */
/*   Updated: 2022/03/30 11:53:03 by cmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H


typedef struct s_env
{
	char			*var;
	struct s_env	*next;
}	t_env;

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


typedef struct s_data
{
	t_env	*env;
	t_token	*tok;
}	t_data;

#endif