all: AiAnts.h Buffer.h mainArwen.c Buffer.c
	gcc -Wall mainArwen.c Buffer.c -o AiAnts
	./AiAnts
