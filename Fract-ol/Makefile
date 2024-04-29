SRCS	= fract_ol.c mandelbrot.c key_hook.c utils.c burningship.c colors.c thread.c buddha.c 

HEAD	= fract_ol.h

OBJS 	= $(SRCS:.c=.o)

NAME	= fract_ol

LIB		= ar rcs

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra 

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEAD)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS)  $(OBJS) -I./mlx -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
