SRCS	= push_swap.c utils.c ope/swap.c ope/push.c ope/rotate.c ope/reverse_rotate.c algo/radix.c errors.c ft_split.c algo/trois.c algo/cinq.c

HEAD	= push_swap.h

OBJS 	= $(SRCS:.c=.o)

NAME	= push_swap

LIB		= ar rcs

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEAD)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
