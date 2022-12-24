#include <stdio.h>
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

    // creating the map
    Map *map = malloc(ROW_QTT * sizeof(Map));
    map->tile = malloc(COL_QTT * sizeof(Tile*));


    int n = 1; // number of ants on the map at once
    // list containing all ants
    struct Ants pos[n];

    pos[0].pos_x = 0;
    pos[0].pos_y = 0;
    printf("%d",pos[0].pos_x);


    FillTable(*map);

    //FillTable(map,ROW_QTT,ROW_QTT);
    ShowTable(*map);


/*
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
        //ShowTable(map);

    }
    */
}



/*
    TODO:
    - Utiliser des arbres
    - Utiliser des listes

*/