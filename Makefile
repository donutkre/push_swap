

NAME = push_swap checker

SOURCES = \
		srcs/lib/util1.c \
		srcs/lib/util2.c \
		srcs/lib/util3.c \
		srcs/lib/util4.c \
		srcs/lib/util5.c \
		srcs/lib/util6.c \
		srcs/operation/op1.c \
		srcs/operation/op2.c \
		srcs/operation/op3.c \
		srcs/operation/op4.c \
		srcs/operation/op5.c \
		srcs/operation/op6.c \
		srcs/operation/next.c \
		srcs/spec/array.c \
		srcs/spec/del.c \
		srcs/spec/specc.c \
		srcs/spec/specr.c \
		srcs/spec/specr2.c \
		srcs/spec/spect.c \
		srcs/spec/spect2.c \
		srcs/spec/valid.c \
		srcs/spec/read.c \
		srcs/algo.c \
		srcs/stack.c \
		srcs/stack2.c \


PUSH_SWAP_MAIN_SRC = srcs/push_swap.c
CHECKER_MAIN_SRC = srcs/checker.c

OBJECTS = $(SOURCES:.c=.o)
PUSH_SWAP_MAIN_OBJ = $(PUSH_SWAP_MAIN_SRC:.c=.o)
CHECKER_MAIN_OBJ = $(CHECKER_MAIN_SRC:.c=.o)

RM = rm -rf
INC_DIR = -I./src
FLAGS = -Wall -Wextra -Werror
LIBS = -lm
CC = gcc

all: $(NAME)

$(OBJECTS): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

$(PUSH_SWAP_MAIN_OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

$(CHECKER_MAIN_OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

push_swap: $(OBJECTS) $(PUSH_SWAP_MAIN_OBJ)
	$(CC) $(FLAGS) $^ -o $@ $(INC_DIR) $(LIBS)

checker: $(OBJECTS) $(CHECKER_MAIN_OBJ)
	$(CC) $(FLAGS) $^ -o $@ $(INC_DIR) $(LIBS)

$(MAINOBJECTS): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJECTS) $(PUSH_SWAP_MAIN_OBJ) $(CHECKER_MAIN_OBJ) test.o

re: fclean
	make all

norm:
	find . -name "*.c" -o -name "*.h" | grep -v test | xargs norminette

.PHONY: all bonus clean fclean re norm test .c.o