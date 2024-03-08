SRCS	= $(wildcard src/*.c)

OBJS    = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

OBJ_DIR = obj

NAME	= libft.a

LIB		= ar rcs

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I.

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

all:	$(NAME)
	@echo "TEST " $(SRCS)

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fsrc/%.ce
