# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 00:22:45 by lnicoter          #+#    #+#              #
#    Updated: 2023/03/21 19:43:13 by lnicoter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client

NAME2 = server

SRCS1 = client.c ft_atoi.c ft_printf.c ft_utils_hex.c ft_utils.c \

SRCS2 = server.c ft_printf.c ft_utils_hex.c ft_utils.c \

# OBJ1 = $(SRCS1:.c=.o);
# OBJ2 = $(SRCS2:.c=.o);

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -g

all: $(NAME1) $(NAME2)

$(NAME1): $(SRCS1)
					$(CC) $(SRCS1) -o $(NAME1)

$(NAME2): $(SRCS2)
					$(CC) $(SRCS2) -o $(NAME2)

clean:
				${RM} ${OBJ1}
				${RM} $(OBJ2)

fclean:			clean
				rm -f $(NAME1)
				rm -f $(NAME2)

re:				fclean all
