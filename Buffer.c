#include "Buffer.h"
#include "AiAnts.h"

// Afficher le tableau
void ShowTable(struct Tile **map[]){
    //system("cls");  // Windows
    system("clear");  //nix (Mac aussi?)
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int colone = 0; colone < COL_QTT; colone++){
            if (map[ligne][colone]->num_toFood == 1)
                printf("o \t");
        }
        printf("\n");
    }
    sleep(2);  // "Buffer" //
    // IMPORTANT : Sur Linux/Mac(?) c'est en secondes, sur Win c'est en milisecondes
}

void FillTable(struct Tile **map[]){
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int colone = 0; colone < COL_QTT; colone++){
            map[ligne][colone]->num_toFood = 1;
            printf("%d",map[ligne][colone]->num_toFood);
        }
    }
}

