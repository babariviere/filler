NAME=$(shell whoami).filler

SRC_NAME=main.c map.c piece.c
SRC=$(addprefix src/, $(SRC_NAME))
OBJ=$(patsubst src/%.c, obj/%.o, $(SRC))
INC=-Iinclude -Ilibft/include
LIB=-Llibft -lft

CC=clang
CFLAGS=-Wall -Werror -Wextra -O3 $(INC)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@printf "==> compiling $@\n" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB)

obj/%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	@printf "==> compiling %s\n" $@
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf obj
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

test: all
	@./res/filler_vm -f res/maps/map01 -p1 ./$(NAME)  -p2 res/players/superjeannot.filler 2> log
