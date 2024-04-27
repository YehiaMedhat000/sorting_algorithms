CC=gcc
FLAGS=-Wall -pedantic -Werror -Wextra -std=gnu89 -g
FILES=*.c

all:
	@$CC $FILES $FLAGS
	@echo "Executing at $(date +%T)\n" >> out.txt
	@echo >> out.txt
	@./a.out >> out.txt
	@echo >> out.txt
	@rm a.out
	@nv out.txt
