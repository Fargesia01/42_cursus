ASM_SRCS =			$(wildcard src/asm/*.s)
ASM_OBJS =			$(patsubst src/asm/%.s, obj/asm/%.o, $(ASM_SRCS))
C_SRCS =			$(wildcard src/C/*.c)
C_OBJS =			$(patsubst src/C/%.c, obj/C/%.o, $(C_SRCS))
BONUS_ASM_SRCS =	$(wildcard bonus/asm/*.s)
BONUS_ASM_OBJS =	$(patsubst bonus/asm/%.s, obj/bonus/%.o, $(BONUS_ASM_SRCS))
HEAD = 				include
LIBRARY =			libasm.a
BONUS_LIBRARY =		libasm_bonus.a
TEST_EXE = 			test
LIB =				ar rcs
CC =				gcc
CFLAGS =			-Wall -Wextra -Werror

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
	$(CC) -o $(TEST_EXE) $(C_OBJS) -L. -lasm -no-pie


obj/bonus/%.o: bonus/asm/%.s
	mkdir -p obj/bonus
	nasm -f elf64 $< -o $@

$(BONUS_LIBRARY): $(BONUS_ASM_OBJS)
	$(LIB) $(BONUS_LIBRARY) $(BONUS_ASM_OBJS)

bonus_lib: $(BONUS_LIBRARY) $(LIBRARY)

bonus_test: $(C_OBJS) $(LIBRARY) $(BONUS_LIBRARY)
	$(CC) -o $(TEST_EXE) $(C_OBJS) -L. -lasm_bonus -lasm -no-pie

bonus: bonus_lib bonus_test


clean:
	rm -rf obj

fclean: clean
	rm -f $(LIBRARY) $(TEST_EXE) $(BONUS_LIBRARY)

re: fclean all

.PHONY: all clean fclean re $(LIBRARY) $(TEST_EXE)
