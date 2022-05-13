# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 17:43:00 by bregneau          #+#    #+#              #
#    Updated: 2022/05/12 16:52:45 by bregneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c ft_strncmp.c ft_isalpha.c \
					ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_tolower.c \
				   	ft_bzero.c ft_isascii.c ft_memmove.c ft_strrchr.c \
					ft_strlen.c ft_toupper.c ft_isdigit.c ft_memset.c \
					ft_memchr.c ft_strnstr.c ft_atoi.c ft_strlcat.c \
					ft_calloc.c ft_strdup.c ft_memcmp.c ft_substr.c \
					ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
					ft_putnbr_fd.c ft_strmapi.c ft_striteri.c \
					ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
					ft_realloc.c ft_atoi_base.c ft_strcpy.c ft_free_strs.c \
					ft_printf/ft_print_char.c ft_printf/ft_print_hexa.c \
					ft_printf/ft_print_int.c ft_printf/ft_print_ptr.c \
					ft_printf/ft_print_str.c  ft_printf/ft_print_uint.c \
					ft_printf/ft_printf.c \
					ft_split_f.c ft_add_to_str.c
					
OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
					ft_lstiter.c ft_lstmap.c
BONUS_OBJS		= $(BONUS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g3 -I.

NAME			= libft.a

all:			bonus

%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)
				@ranlib $(NAME)
				@echo "$(NAME) created"

clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(NAME) deleted"

re:				fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
				@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
				@ranlib $(NAME)
				@echo "$(NAME) created"

.PHONY:			all clean fclean re bonus
