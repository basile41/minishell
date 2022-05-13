# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 18:43:49 by bregneau          #+#    #+#              #
#    Updated: 2022/05/13 15:16:23 by bregneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

INC				=	-I $(addprefix $(LIBFT_PATH),.)\
					-I ./includes

LIBFT_PATH		=	./libft/
SRC_PATH		=	./src/
OBJ_PATH		=	./obj/

PARSER_PATH		=	parser/
BUILTINS_PATH	=	builtins/
EXEC_PATH		=	exec/
UTILS_PATH		=	utils/

OBJ_DIRS		=	$(OBJ_PATH) \
					$(addprefix $(OBJ_PATH),parser/ builtins/ exec/ utils/)

SRC_PARSER		=	ft_tok_rec.c \
					ft_tokens.c \
					ft_split_toks.c \
					ft_heredoc.c \
					ft_check_tok.c \
					ft_parser.c \
					ft_expand.c \
					ft_expand2.c
SRC_BUILTINS	=	display_export.c \
					sh_cd.c \
 					sh_echo.c \
 					sh_pwd.c \
 					sh_env.c \
 					sh_export.c \
					sh_unset.c \
					sh_exit.c \
					builtins_ex.c
SRC_EXEC		=	ft_pipex.c \
					ft_pipex2.c \
					ft_exec.c
SRC_UTILS		=	env_lst.c \
					ft_env_utils.c \
					ft_exit.c \
					ft_pipex_utils.c 
					
SRC				= 	main.c \
					ft_minishell.c \
					$(addprefix $(PARSER_PATH), $(SRC_PARSER)) \
					$(addprefix $(EXEC_PATH), $(SRC_EXEC)) \
					$(addprefix $(UTILS_PATH), $(SRC_UTILS)) \
					$(addprefix $(BUILTINS_PATH), $(SRC_BUILTINS)) \
					ft_env.c \
					
OBJ				=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))
DEPS			=	$(addprefix $(OBJ_PATH),$(SRC:.c=.d))

LIBFT			=	$(addprefix $(LIBFT_PATH),libft.a)

LIBS			=	-lreadline -Llibft -lft

CC				=	cc
CFLAGS			=	-MMD -Wall -Wextra -Werror -g3 $(INC)

all:				$(NAME)

$(OBJ_DIRS):
					@mkdir -p $(OBJ_DIRS)

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c
					@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJ_DIRS) $(LIBFT) $(OBJ)
					$(CC) $(OBJ) $(LIBS) -o $(NAME) #-fsanitize=address

$(LIBFT):	
					@echo "Compiling libft..."
					@make -C $(LIBFT_PATH)
					@make clean -C $(LIBFT_PATH)

clean:		
					rm -rf $(OBJ_PATH)

fclean:				clean
					rm -f $(LIBFT) $(NAME)

re:					fclean
					make all

-include			$(DEPS)

.PHONY:				all bonus clean fclean re
