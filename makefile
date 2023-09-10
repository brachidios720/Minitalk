# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 13:47:39 by rcarbonn          #+#    #+#              #
#    Updated: 2023/09/08 20:36:17 by rcarbonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM	= rm -f
CC	= cc
FL	= -Wall -Werror -Wextra
COMP	= $(CC) $(FL)

# -- SRC -- #

SRCC	= 	srcs/client/client.c

SRCS	=	srcs/server/server.c

all: server client

client:
	$(CC) $(FL) $(SRCC) -o client
	
server:
	$(CC) $(FL) $(SRCS) -o server

clean:
	$(RM) server client

fclean: clean
	$(RM) **.o

re:			clean all