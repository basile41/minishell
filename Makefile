# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 18:43:49 by bregneau          #+#    #+#              #
#    Updated: 2022/04/01 21:19:59 by bregneau         ###   ########.fr        #
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
					ft_heredoc.c
SRC_BUILTINS	=	sh_echo.c \
					sh_pwd.c \
					sh_env.c \
					sh_export.c
SRC_EXEC		=	
SRC_UTILS		=

SRC				= 	main.c \
					ft_minishell.c \
					ft_exit.c \
					ft_env.c \
					$(addprefix $(PARSER_PATH), $(SRC_PARSER)) \
					$(addprefix $(BUILTINS_PATH), $(SRC_BUILTINS)) \
					$(addprefix $(EXEC_PATH), $(SRC_EXEC)) \
					$(addprefix $(UTILS_PATH), $(SRC_UTILS))
					
OBJ				=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

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

re:					fclean all

.PHONY:				all bonus clean fclean re
