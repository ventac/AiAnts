#include <stdio.h>
// Définition des dimensions du tableau
#define COL_QTT 8
#define ROW_QTT 8

// Déclaration en globale pour l'instant
int table[ROW_QTT][COL_QTT];

// Remplir le tableau avec 1 partout
// TODO : Ajouter d'autres chiffres pour répresenter der murs/chemins plus complexes
void FillTable(/*int * tableau[][]*/){
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int col = 0; col < COL_QTT; col++){
            table[ligne][col] = 0;
        }
    }
    //return tableau;
}

// Afficher le tableau
void ShowTable(){
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int col = 0; col < COL_QTT; col++){
            printf("%d \t", table[ligne][col]);
        }
        printf("\n");
    }
}

// Code principal
int main(void){


    FillTable();
    ShowTable();
    
    // Pour tester, la position initielle sera le coin inférieur gauche (8,0)
    // et l'objectif sera le coin supérieur droite (0,8)


}



/*
    TODO:
    - Utiliser des arbres
    - Utiliser des listes

*/