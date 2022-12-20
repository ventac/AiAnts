#include <stdio.h>
#include <stdlib.h>  // Pour pouvoir effacer la console
// Fonction sleep
//#include <windows.h> // Pour Windows
#include <unistd.h>  // Pour Linux (Et mac?)

// print the table with ant and path
#include "Buffer.h"
#include "AiAnts.h"
#include "Ant.h"



int main(){
    
    int **map = (int**) malloc(ROW_QTT * sizeof(int*));//hauteur
    for(int i = 0 ; i < ROW_QTT ; i++)
        map[i] = malloc(COL_QTT * sizeof(int)); //largeur

    int **table[ROW_QTT][COL_QTT];

    FillTable(**table,ROW_QTT,COL_QTT);
    

}