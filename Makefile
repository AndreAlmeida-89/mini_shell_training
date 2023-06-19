# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 17:08:03 by pvieira-          #+#    #+#              #
#    Updated: 2023/06/19 11:00:53 by andde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	$(addprefix src/, main.c create_cmd.c run_cmd.c parse_cmd.c utils.c)
# PARSER		=	$(addprefix parser/, mini_parser.c)
# UTILS		=	$(addprefix utils/, mini_utils_1.c mini_utils_2.c)
# BUILTINS	=	$(addprefix builtins/, echo_builtin.c)

INC		=	./include/
OBJS	= 	$(SRCS:.c=.o)

NAME	= 	minishell

CC		= 	cc

RM		= 	rm -f

CFLAGS	= -Wall -Wextra -Werror

C_FLAGS = -I /opt/homebrew/Cellar/readline/8.2.1/include

C_FLAGS += -I ~/.brew/opt/readline/include

LFLAGS = -L ~/.brew/opt/readline/lib

.c.o:
		$(CC) $(CFLAGS) -c $< -I $(INC) -o $(<:.c=.o)
#--Mac
#$(NAME):	$(OBJS)
#			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline $(C_FLAGS) $(LFLAGS)
#--Linux
$(NAME):	libfta $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -lreadline -L. -lft -o $(NAME)

libfta:
			make -C ./libft
			cp ./libft/libft.a .

all:		$(NAME)

clean:
			make clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME) libft.a

re:			fclean all

.PHONY:		all clean fclean re
