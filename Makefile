# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klakbuic <klakbuic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 16:06:03 by klakbuic          #+#    #+#              #
#    Updated: 2024/06/08 09:28:25 by klakbuic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME         = philo
BONUS        = checker
HEADER       = /inc/header.h

CC           = cc
CFLAGS       = -Wall -Wextra -Werror -g3
DEBUG        = -g3 -fsanitize=thread

SRCSDIR      = src
SRCSFILES    = ft_atoi.c  init.c  lib.c  main.c  parsing.c  philo.c  routine.c  sumilation.c  utils.c  geters.c  seters.c  more_geters.c
SRCS	     = $(addprefix $(SRCSDIR)/, $(SRCSFILES))

OBJSDIR      = obj
OBJSFILES    = $(SRCSFILES:.c=.o)
OBJS	     = $(addprefix $(OBJSDIR)/, $(OBJSFILES))

OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -I $(HEADER) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS_B)
	@$(CC) $(CFLAGS) $(OBJS_B) $(LIB) -I $(HEADER) -o $(BONUS)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_B)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus