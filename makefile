# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 13:47:39 by rcarbonn          #+#    #+#              #
#    Updated: 2023/09/07 17:51:21 by rcarbonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Commande -- #

RM    = rm -f
CC    = gcc
FL    = -Wall -Werror -Wextra
COMP    = $(CC) $(FL)

# -- SRC -- #

SRC =  serveur.c\
		client.c\	


SRCO    = $(SRC:.c=.o)

NAME    = minitalk.a

# -- Target -- #

all:		$(NAME) 

$(NAME): $(OBJ)
		$(CC) -Wall -Werror -Wextra -c $(SRC)
		ar -rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:
		$(RM) $(NAME) $(OBJ)

re:		fclean all

.PHONY: all clean fclean re
