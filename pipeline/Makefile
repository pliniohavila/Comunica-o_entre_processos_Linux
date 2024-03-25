CC 		= gcc
FLAGS	= -Wall -Wextra -Werror
SANIT 	= -fsanitize=address
DBG   	= -g3
# REDL	= -lreadline


all:
	$(CC) $(FLAGS) main.c -o main

sanit:
	$(CC) $(FLAGS) $(SANIT) main.c -o main

parser:
	$(CC) $(FLAGS) parser.c parser_test.c -o parser

pipeline:
	$(CC) $(FLAGS) parser.c pipeline.c -o pipeline	

run:
	./main

%: %.c
	$(CC) $(FLAGS) $< -o $@ 

clean: 
	rm pipeline