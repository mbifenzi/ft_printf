

SRC = ft_atoi.c ft_edit_flags.c ft_execute_flags_d.c ft_hexa.c  ft_isdigit.c ft_itoa.c ft_printf_utils.c ft_printf.c \
ft_putchastr.c ft_strchr.c ft_strlen.c ft_execute_flags_s.c ft_execute_flags_x.c ft_utoa.c ft_execute_flags_u.c \
ft_execute_flags_i.c ft_execute_flags_p.c hexap.c

OBJECT = *.o

NAME = libftprintf.a

all : $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all

