/*#include <stdio.h>
#include <stdlib.h>  // Pour pouvoir effacer la console
// Fonction sleep
//#include <windows.h> // Pour Windows
#include <unistd.h>  // Pour Linux (Et mac?)
#include  <string.h>
#include <stdbool.h>

// print the table with ant and path

#include "AiAnts.h"
#include "Ant.h"
#include "Buffer.h"






// Code principal
int main(void){

    // creating and giving the memory for the map
    struct Tile *map[ROW_QTT];
    int **map = (int**) malloc(ROW_QTT * sizeof(int*));//hauteur
    for(int i = 0 ; i < ROW_QTT ; i++)
        map[i] = malloc(COL_QTT * sizeof(int)); //largeur

    FillTable(map);

    //FillTable(map,ROW_QTT,ROW_QTT);
    //ShowTable();



    // Pour tester, la position initielle sera le coin inférieur gauche (8,0)
    // et l'objectif sera le coin supérieur droite (0,8)


    // Position initielle fourmis: base gauche tableau |_
    int y_ini = ROW_QTT - 1, // -1 parce que la taille totale est de 8 et ça commence par 0
        x_ini = 0;
    
    int* y_ant = &y_ini,
       * x_ant = &x_ini;

    // Fourmis réprésenté par le No 8
    // table[y_ini][x_ini] = F;

    
    for (int i = 0; i < 12; i++){
        int nb = rand() % 9 + 1;
        //ShowTable();
        //MoveAnt(nb,&x_ant,&y_ant);
        ShowTable(map);

    }
}


*/
/*
    TODO:
    - Utiliser des arbres
    - Utiliser des listes

*/