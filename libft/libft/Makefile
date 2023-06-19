# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvieira- <pvieira-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/28 13:23:37 by pvieira-          #+#    #+#              #
#    Updated: 2022/06/16 07:24:40 by pvieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isprint.c ft_putnbr_fd.c ft_strmapi.c ft_itoa.c ft_putstr_fd.c\
		  ft_strncmp.c ft_atoi.c ft_memchr.c ft_strchr.c ft_strnstr.c\
		  ft_bzero.c ft_memcmp.c ft_strdup.c ft_strrchr.c ft_calloc.c\
		  ft_memcpy.c ft_striteri.c ft_strtrim.c ft_isalnum.c ft_memmove.c\
		  ft_strjoin.c ft_substr.c ft_isalpha.c ft_memset.c ft_strlcat.c\
		  ft_tolower.c ft_isascii.c ft_putchar_fd.c ft_strlcpy.c ft_toupper.c\
		  ft_isdigit.c ft_putendl_fd.c ft_strlen.c ft_split.c

BONUS_SRCS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c

OBJS	= 	$(SRCS:.c=.o)

OBJBNS	=	$(BONUS_SRCS:.c=.o)

NAME	= 	libft.a

CC		= 	cc

RM		= 	rm -f

CFLAGS	= -Wall -Wextra -Werror

AR 		= ar -rcs

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) 
			$(AR) $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

bonus: $(OBJBNS)
			ar qs $(NAME) $(OBJBNS)

clean:
			$(RM) $(OBJS) $(OBJBNS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
