SRCS	= main.cpp HumanA.cpp Weapon.cpp HumanB.cpp

OBJS 	= $(SRCS:.cpp=.o)

NAME	= violence_inutile

CC		= c++

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS)
	 $(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
