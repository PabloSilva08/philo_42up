# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 13:02:25 by pvieira-          #+#    #+#              #
#    Updated: 2023/05/06 18:01:10 by pvieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	main.c util_philo.c util_philo_2.c init.c routine.c error.c\
			current_time.c philo_free.c action.c

OBJS	= 	$(SRCS:.c=.o)

NAME	= 	philo

CC		= 	cc

RM		= 	rm -f

CFLAGS	= -Wall -Wextra -Werror $(DFLAGS)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) 
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
