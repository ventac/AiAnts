all: AiAnts.h Buffer.h Ant.h mainArwen.c Buffer.c Ant.c
	gcc -Wall mainArwen.c Buffer.c Ant.c -o AiAnts
	./AiAnts
