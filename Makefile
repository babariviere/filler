NAME=$(shell whoami).filler

SRC_NAME=main.c
SRC=$(addprefix src/, $(SRC_NAME))
OBJ=$(patsubst src/%.c, obj/%.o, $(SRC))

CC=clang
CFLAGS=-Wall -Werror -Wextra -O3

all: $(NAME)

$(NAME): $(OBJ)
	@printf "==> compiling $@\n" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ)

obj/%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	@printf "==> compiling %s\n" $@
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all
