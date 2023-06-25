SRCS	= ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunint.c ft_putnbr_hexa.c ft_putptr.c

HEAD	= ft_printf.h

OBJS 	= $(SRCS:.c=.o)

NAME	= libftprintf.a

LIB		= ar rcs

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEAD)

$(NAME): $(OBJS)
		$(LIB) $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
