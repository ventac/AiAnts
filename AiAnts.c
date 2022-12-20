#include <stdio.h>
#include <stdlib.h>  // Pour pouvoir effacer la console
// Fonction sleep
//#include <windows.h> // Pour Windows
#include <unistd.h>  // Pour Linux (Et mac?)
#include  <string.h>

// print the table with ant and path

#include "AiAnts.h"
#include "Ant.h"
#include "Buffer.h"

/*
//#include <system>
// Définition des dimensions du tableau
#define F 500  // ça va répresenter numériquement la fourmis, on peut changer après par -1
#define QTT_ANTC 1
#define COL_QTT 8
#define ROW_QTT 8
#define ANT 500
*/

// Code principal
int main(void){

    // creating and giving the memory for the map
    int **map = (int**) malloc(ROW_QTT * sizeof(int*));//hauteur
    for(int i = 0 ; i < ROW_QTT ; i++)
        map[i] = malloc(COL_QTT * sizeof(int)); //largeur

    FillTable(map);

    for (int i = 0; i < 12; i++){
        int nb = rand() % 9 + 1;
        //ShowTable();
        //MoveAnt(nb,&x_ant,&y_ant);
        ShowTable(map);

    }
}



/*
    TODO:
    - Utiliser des arbres
    - Utiliser des listes

*/