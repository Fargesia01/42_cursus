SRCS	= $(wildcard src/*.c)
OBJS    = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))
OBJ_DIR = obj
NAME	= libftprintf.a
LIB		= ar rcs
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

$(OBJ_DIR)/%.o: src/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I.

$(NAME): $(OBJS)
		$(LIB) $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -r $(NAME)

re:		fclean all

.PHONY: all clean fclean re
