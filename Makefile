# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarion <cmarion@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 18:43:49 by bregneau          #+#    #+#              #
#    Updated: 2022/04/14 15:13:04 by cmarion          ###   ########.fr        #
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
					ft_check_tok.c
 SRC_BUILTINS	=	display_export.c \
					sh_cd.c \
 					sh_echo.c \
 					sh_pwd.c \
 					sh_env.c \
 					sh_export.c \
					sh_unset.c \
					sh_exit.c \
					builtins_ex.c
SRC_EXEC		=	
SRC_UTILS		=	x_malloc.c \
					env_lst.c

SRC				= 	main.c \
					ft_minishell.c \
					ft_exit.c \
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
