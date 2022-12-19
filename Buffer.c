#include "Buffer.h"
#define COL_QTT 8
#define ROW_QTT 8
#define F 500  // ça va répresenter numériquement la fourmis, on peut changer après par -1
#define QTT_ANTC 1
int table[ROW_QTT][COL_QTT];

// Afficher le tableau
void ShowTable(){
    //system("cls");  // Windows
    system("clear");  //nix (Mac aussi?)
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int col = 0; col < COL_QTT; col++){
            if (table[ligne][col] == F){
                printf("🐜\tTEST");
            }
            else
                printf("%d\t", table[ligne][col]);
        }
        printf("\n");
    }
    sleep(1);  // "Buffer" //
    // IMPORTANT : Sur Linux/Mac(?) c'est en secondes, sur Win c'est en milisecondes
}