# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 12:21:57 by groubaud          #+#    #+#              #
#    Updated: 2021/06/11 23:24:07 by groubaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLT		=	client
SERV	=	server

DIR_L	=	./libft/
DIR_S	=	./

INC_L	=	$(DIR_L)include/

CC		=	gcc
CFLAGS	=	-Wall -Wextra
LIB		=	-L $(DIR_S) -lft

OBS_SERV=	ft_server.o

OBS_CLT	=	ft_client.o

## commande

all		:	$(SERV) $(CLT)

%.o		:	%.c
			$(CC) $(CFLAGS) -I$(INC_L) -c -o $@ $<

lib		:
			make -C $(DIR_L) all
			cp $(DIR_L)libft.a $(DIR_S)

$(SERV)	:	$(OBS_SERV)
			make lib
			$(CC) $(CFLAGS) -I$(INC_L) $(OBS_SERV) $(LIB) -o $@

$(CLT)	:	$(OBS_CLT)
			make lib
			$(CC) $(CFLAGS) -I$(INC_L) $(OBS_CLT) $(LIB) -o $@

clean	:
			rm -rf $(OBS_SERV) $(OBS_CLT)

fclean	:	clean
			rm -rf $(SERV) $(CLT)
			make -C $(DIR_L) fclean
			rm -rf libft.a

re		:	fclean all			

.PHONY	:	all clean fclean re
