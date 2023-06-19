# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/28 13:23:37 by pvieira-          #+#    #+#              #
#    Updated: 2022/12/28 16:38:12 by pvieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=   ft_dec_hex_l.c ft_dec_hex_u.c ft_printf.c out_id.c out_p.c out_s.c\
			out_c.c out_l_x.c out_u_x.c out_perc.c out_u.c

PREFD	=	$(addprefix ./obj/, $(SRCS))

OBJF	=	$(PREFD:.c=.o)

SRCPATH	=	./src/

OBJPATH	=	./obj/

OB		=	./obj

INCPATH	=	./include/

NAME	= 	libftprintf.a

CC		= 	cc

RM		= 	rm -f

CFLAGS	= -Wall -Wextra -Werror

AR 		= ar -rcs

$(OBJPATH)%.o: $(SRCPATH)%.c
			$(CC) $(CFLAGS) -c $< -I $(INCPATH) -o $@

$(NAME):	$(OB) $(OBJF) $(INCPATH)ft_printf.h
			make -C ../gnl
			cp ../gnl/libgnl.a ./libftprintf.a
			$(AR) $(NAME) $(OBJF)

all:		$(NAME)

$(OB):		
			mkdir obj

comp:		principal

principal:	./main.c	
			$(CC) $(CFLAGS) $< -L. -lftprintf -o $@

clean:
			make clean -C ../gnl
			$(RM) $(OBJF)
			rm -rf obj

fclean:		clean
			make fclean -C ../gnl
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
