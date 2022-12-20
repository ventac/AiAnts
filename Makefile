all: AiAnts.h Buffer.h Ant.h AiAnts.c Buffer.c Ant.c
	gcc -Wall AiAnts.c Buffer.c Ant.c -o AiAnts
	./AiAnts
