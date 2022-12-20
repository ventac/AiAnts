#include "Buffer.h"

// Afficher le tableau
void ShowTable(int **map){
    //system("cls");  // Windows
    system("clear");  //nix (Mac aussi?)
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int colone = 0; colone < COL_QTT; colone++){
            if (map[ligne][colone] == ANT){
                printf("🐜\tTEST");
            }
            else
                printf("%d\t", map[ligne][colone]);
        }
        printf("\n");
    }
    sleep(1);  // "Buffer" //
    // IMPORTANT : Sur Linux/Mac(?) c'est en secondes, sur Win c'est en milisecondes
}

void FillTable(int **map){
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int colone = 0; colone < COL_QTT; colone++){
            map[ligne][colone] = 0;
        }
    }
}


//////// TEST GUI

// Afficher le tableau
void ShowTable(int **cells){
    //system("cls");  // Windows
    system("clear");  //nix (Mac aussi?)
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int col = 0; col < COL_QTT; col++){
            if (cells[ligne][col] == ANT){
                printf("🐜\tTEST");
            }
            printf("%d\t",cells[ligne][col]);
        }
        printf("\n");
    }
    sleep(1);  // "Buffer" //
    // IMPORTANT : Sur Linux/Mac(?) c'est en secondes, sur Win c'est en milisecondes
}