# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 08:18:27 by oessamdi          #+#    #+#              #
#    Updated: 2022/02/16 12:05:18 by oessamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = draw_map.c get_map.c so_long.c so_long_utils.c error.c

GET_NEXT_LINE = get_next_line.c get_next_line_utils.c

FT_PRINTF = ft_printf.c ft_printf_utils.c

CC = @gcc $(SRC) $(GET_NEXT_LINE) $(FT_PRINTF) -lmlx -framework OpenGl -framework AppKit

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

$(NAME) : 
			$(CC) -o $(NAME)

all : $(NAME)

fclean :
			$(RM) $(NAME)

re : fclean all
