#include "Buffer.h"


// Afficher le tableau
void ShowTable(int **cells,int row,int col){
    //system("cls");  // Windows
    system("clear");  //nix (Mac aussi?)
    for (int ligne = 0; ligne < row; ligne++){
        for (int colone = 0; colone < col; colone++){
            if (cells[ligne][colone] == 8){
                printf("🐜\tTEST");
            }
            else
                printf("%d\t", cells[ligne][colone]);
        }
        printf("\n");
    }
    sleep(1);  // "Buffer" //
    // IMPORTANT : Sur Linux/Mac(?) c'est en secondes, sur Win c'est en milisecondes
}

void FillTable(int **cells,int row,int col){
    for (int ligne = 0; ligne < row; ligne++){
        for (int colone = 0; colone < col; col++){
            cells[ligne][colone] = 0;
        }
    }
}