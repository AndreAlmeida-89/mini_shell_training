SRCLIB		=	ft_isprint.c ft_putnbr_fd.c ft_strmapi.c ft_itoa.c\
				ft_putstr_fd.c ft_strncmp.c ft_atoi.c ft_memchr.c ft_strchr.c\
				ft_strnstr.c ft_bzero.c ft_memcmp.c ft_strdup.c ft_strrchr.c\
				ft_calloc.c	ft_memcpy.c ft_striteri.c ft_strtrim.c ft_isalnum.c\
				ft_memmove.c ft_strjoin.c ft_substr.c ft_isalpha.c ft_memset.c\
				ft_strlcat.c ft_tolower.c ft_isascii.c ft_putchar_fd.c\
				ft_strlcpy.c ft_toupper.c ft_isdigit.c ft_putendl_fd.c\
				ft_strlen.c ft_split.c

SRCGNL		=   get_next_line.c  get_next_line_utils.c

SRCPTF		=	ft_dec_hex_l.c ft_dec_hex_u.c ft_printf.c out_id.c\
				out_p.c out_s.c out_c.c out_l_x.c out_u_x.c out_perc.c out_u.c



PREFL	=	$(addprefix ./libft/, $(SRCLIB))
PREFG	=	$(addprefix ./gnl/, $(SRCGNL))
PREFP	=	$(addprefix ./ft_printf/src/, $(SRCPTF))

NAME	=	libft.a	
RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(PREFL) $(PREFG) $(PREFP)
			make -C ./ft_printf
			cp ./ft_printf/libftprintf.a ./$(NAME)

clean:
			make clean -C ./ft_printf

fclean:		clean
			make fclean -C ./ft_printf
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
