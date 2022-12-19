#include "Buffer.h"

// Afficher le tableau
void ShowTable(){
    //system("cls");  // Windows
    system("clear");  //*nix (Mac aussi?)
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int col = 0; col < COL_QTT; col++){
            if (table[ligne][col] == F){
                printf("🐜\tTEST");
            }
            printf("%d\t", table[ligne][col]);
        }
        printf("\n");
    }
    sleep(1);  // "Buffer" //
    // IMPORTANT : Sur Linux/Mac(?) c'est en secondes, sur Win c'est en milisecondes
}