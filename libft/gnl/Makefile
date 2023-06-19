# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/28 13:23:37 by pvieira-          #+#    #+#              #
#    Updated: 2022/12/28 16:33:33 by pvieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=   get_next_line_bonus.c  get_next_line_utils_bonus.c

OBJS	=	$(SRCS:.c=.o)

NAME	= 	libgnl.a

CC		= 	cc

RM		= 	rm -f

CFLAGS	= -Wall -Wextra -Werror

AR 		= ar -rcs

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make -C ../libft
			make bonus -C ../libft
			cp ../libft/libft.a ./libgnl.a
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

comp:		principal

principal:	./main.c	
			$(CC) $(CFLAGS) $< -L. -lgnl -o $@

clean:
			make clean -C ../libft
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ../libft
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
