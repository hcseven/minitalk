# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hseven <hseven@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 12:21:13 by hseven            #+#    #+#              #
#    Updated: 2022/08/04 17:20:21 by hseven           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= clang

CFLAGS		= -Wall -Werror -Wextra 

RM			= rm -rf

SRC	= ft_printf.c ft_printf1.c ft_printf_lf.c

OBJ = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) 
			ar rc $(NAME) $(OBJ)

clean:
			rm -f *.o
			$(RM) $(NAME)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re