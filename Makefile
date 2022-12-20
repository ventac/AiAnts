all: AiAnts.h Buffer.h Ant.h main_GUI.c Buffer.c Ant.c
	gcc -Wall main_GUI.c Buffer.c Ant.c -o AiAnts
	#./AiAnts

