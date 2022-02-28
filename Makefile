# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 18:43:49 by bregneau          #+#    #+#              #
#    Updated: 2022/02/28 22:29:53 by bregneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

LIBFT_PATH		=	./libft/
SRCS_PATH		=	./srcs/
OBJS_PATH		=	./objs/

INC				=	-I $(addprefix $(LIBFT_PATH),.)\
					-I ./includes

SRCS			= 	main.c \
					ft_parse_env.c

OBJS			=	$(addprefix $(OBJS_PATH),$(SRCS:.c=.o))

LIBFT			=	$(addprefix $(LIBFT_PATH),libft.a)

LIBS			=	-lreadline -Llibft -lft

CC				=	cc
CFLAGS			=	-MMD -Wall -Wextra -Werror -g3 $(INC)

all:				$(NAME)

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.c
					@mkdir -p $(OBJS_PATH)
					@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(LIBFT) $(OBJS)
					$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):	
					@echo "Compiling libft..."
					@make -C $(LIBFT_PATH)
					@make clean -C $(LIBFT_PATH)

clean:		
					rm -rf $(OBJS_PATH)

fclean:				clean
					rm -f $(LIBFT) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re
