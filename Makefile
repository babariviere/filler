NAME=$(shell whoami).filler

SRC_NAME=main.c map.c piece.c locate.c place.c poss.c find.c
SRC=$(addprefix src/, $(SRC_NAME))
OBJ=$(patsubst src/%.c, obj/%.o, $(SRC))
INC=-Iinclude -Ilibft/include
LIB=-Llibft -lft

CC=clang
CFLAGS=-Wall -Werror -Wextra -g $(INC)

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
	@./res/filler_vm -f res/maps/map01 -p2 ./$(NAME)  -p1 res/players/carli.filler 2> log

test_self: all
	@./res/filler_vm -f res/maps/map01 -p1 ./$(NAME)  -p2 ./$(NAME) 2> log | ./fillme
