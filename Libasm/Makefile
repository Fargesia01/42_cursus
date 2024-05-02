ASM_SRCS =		$(wildcard src/asm/*.s)
ASM_OBJS =		$(patsubst src/asm/%.s, obj/asm/%.o, $(ASM_SRCS))
C_SRCS =		$(wildcard src/C/*.c)
C_OBJS =		$(patsubst src/C/%.c, obj/C/%.o, $(C_SRCS))
HEAD = 			include
LIBRARY =		libasm.a
TEST_EXE = 		test
LIB =			ar rcs
CC =			gcc
CFLAGS =		-Wall -Wextra -Werror

all: $(LIBRARY) $(TEST_EXE)

obj/asm/%.o: src/asm/%.s
	mkdir -p obj/asm
	nasm -f elf64 $< -o $@

$(LIBRARY): $(ASM_OBJS)
	$(LIB) $(LIBRARY) $(ASM_OBJS)

lib: $(LIBRARY)

obj/C/%.o: src/C/%.c
	mkdir -p obj/C
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD)

$(TEST_EXE): $(C_OBJS) $(LIBRARY)
	$(CC) -o $(TEST_EXE) $(C_OBJS) -L. -lasm

clean:
	rm -rf obj

fclean: clean
	rm -f $(LIBRARY) $(TEST_EXE)

re: fclean all

.PHONY: all clean fclean re $(LIBRARY) $(TEST_EXE)
