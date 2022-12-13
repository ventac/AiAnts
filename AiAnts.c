#include <stdio.h>
// Définition des dimensions du tableau
#define X_TABLEAU 8
#define Y_TABLEAU 8

// Déclaration en globale pour l'instant
int tableau[X_TABLEAU][Y_TABLEAU];

// Remplir le tableau avec 1 partout
// TODO : Ajouter d'autres chiffres pour répresenter der murs/chemins plus complexes
void RemplirTableau(/*int * tableau[][]*/){
    for (int ligne = 0; ligne < X_TABLEAU; ligne++){
        for (int col = 0; col < Y_TABLEAU; col++){
            tableau[ligne][col] = ligne;
        }
    }
    //return tableau;
}

// Afficher le tableau
void AfficherTableau(){
    for (int ligne = 0; ligne < X_TABLEAU; ligne++){
        for (int col = 0; col < Y_TABLEAU; col++){
            printf("%d \t", tableau[ligne][col]);
        }
        printf("\n");
    }
}

// Code principal
int main(void){


    RemplirTableau();
    AfficherTableau();
    
    // Pour tester, la position initielle sera le coin inférieur gauche (8,0)
    // et l'objectif sera le coin supérieur droite (0,8)

    



}



/*
    TODO:
    - Utiliser des arbres
    - Utiliser des listes

*/