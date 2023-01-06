#include "Buffer.h"
#include "AiAnts.h"

// Afficher le tableau
void ShowTable(Map **map){
    //system("cls");  // Windows
    system("clear");  //nix (Mac aussi?)
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int colone = 0; colone < COL_QTT; colone++){
            if (map[ligne]->tile[colone]->num_toFood == 1)
                printf("o \t");
        }
        printf("\n");
    }
    sleep(2);  // "Buffer" //
    // IMPORTANT : Sur Linux/Mac(?) c'est en secondes, sur Win c'est en milisecondes
}

void FillTable(Map **map){
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int colone = 0; colone < COL_QTT; colone++){
            map[ligne]->tile[colone]->num_toFood = 1;
        }
    }
}

