# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/19 14:30:01 by ofedorov          #+#    #+#              #
#    Updated: 2016/10/19 14:39:23 by ofedorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

SRCSFL	=	ins_del.c interpret.c print.c solve.c ft_strlen.c

SRCSFD	=	srcs
OBJSFD	=	objs
INCLFD	=	includes

SRCS	=	$(addprefix $(SRCSFD)/, $(SRCSFL))
OBJS	=	$(addprefix $(OBJSFD)/, $(SRCSFL:.c=.o))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLFD) $(OBJS) -o $(NAME)

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: $(SRCSFD)/%.c | $(OBJSFD)
	$(CC) $(CFLAGS) -I$(INCLFD) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJSFD)

fclean: clean
	rm -rf $(NAME)

re: fclean all
