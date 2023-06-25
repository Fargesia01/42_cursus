# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 19:54:24 by ycornamu          #+#    #+#              #
#    Updated: 2022/08/15 15:28:03 by ycornamu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c \
	   	heredoc.c \
		signals.c \
		prompt.c \
		line.c \
		lexer.c \
		lexer_ext.c \
		vars.c \
		flags.c \
		parser.c \
		builtins_one.c \
		export.c \
		cmd_unset.c \
		malloc_command_table.c \
		utils.c \
		exec.c \
		pipex_utils.c \
		redirections.c \
		error_parsing.c \
		cd.c \
		echo.c
SRCS_DIR = src

OBJS = $(SRCS:.c=.o)
OBJS_DIR = obj

DIRS = obj

_SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS))
_OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS))

HEADERS = includes

LIBFT = libft.a
LIBFT_DIR = libft

CC = gcc
CFLAGS = -I $(HEADERS) -I $(LIBFT_DIR)
LFLAGS = $(CFLAGS) -lreadline
DEBUG_LFLAGS = ""
DEBUG_CFLAGS = -g3 -fsanitize=address -fno-omit-frame-pointer

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	DEBUG_LFLAGS = -static-libasan
endif

.PHONY : all debug clean fclean re

all: $(NAME)

debug: LFLAGS += $(DEBUG_LFLAGS)
debug: CFLAGS += $(DEBUG_CFLAGS)
debug: $(NAME)

$(NAME): $(_OBJS)
	$(CC) $(_OBJS) $(LIBFT_DIR)/$(LIBFT) $(LFLAGS) -o $(NAME)

$(_OBJS): $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(DIRS) $(LIBFT_DIR)/$(LIBFT)
	$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT_DIR)/$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all
	$(MAKE) -C $(LIBFT_DIR) bonus
	#cp $(LIBFT_DIR)/libft.h $(HEADERS)/libft.h

$(DIRS):
	mkdir -p $(DIRS)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	rm -rf $(OBJS_DIR) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
