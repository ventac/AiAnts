#include <stdio.h>
#include <stdlib.h>  // Pour pouvoir effacer la console
// Fonction sleep
//#include <windows.h> // Pour Windows
#include <unistd.h>  // Pour Linux (Et mac?)

// print the table with ant and path
#include "Buffer.h"

// TODO: Verifier comment détecter automatiquement le S.O.
#include "AiAnts.h"
#include "Ant.h"


//#include <system>
// Définition des dimensions du tableau
#define F 500  // ça va répresenter numériquement la fourmis, on peut changer après par -1
#define QTT_ANTC 1


// On peut d'abbord mettre toutes les fonctions ici et après on les catégorise et déplace
// dans des "Objets" si ça c'est possible en C, comme Obj Fourmis (move ant, AntPosition),
// Obj nourriture 
// (qtt nourriture)

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
/*

// Afficher le tableau
void ShowTable(){
    //system("cls");  // Windows
    system("clear");  //nix (Mac aussi?)
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
*/

// Où la fourmis va laisser son trace
void LeaveTrace(int x, int y){
    table[y][x] = table[y][x] - 8 + 1; // Efface la fourmis et ajoute la qtt
}

// "Secher" ou la fourmis a passé dans chaque tour
void DryTrace();

// Code principal
int main(void){

    // creating and giving the memory for the map
    int **map = (int**) malloc(ROW_QTT * sizeof(int*));//hauteur
    for(int i = 0 ; i < COL_QTT ; i++)
        map[i] = malloc(COL_QTT * sizeof(int)); //largeur


    FillTable(map,ROW_QTT,ROW_QTT);
    //ShowTable();



    // Pour tester, la position initielle sera le coin inférieur gauche (8,0)
    // et l'objectif sera le coin supérieur droite (0,8)


    // Position initielle fourmis: base gauche tableau |_
    int y_ini = ROW_QTT - 1, // -1 parce que la taille totale est de 8 et ça commence par 0
        x_ini = 0;
    
    int* y_ant = &y_ini,
       * x_ant = &x_ini;

    // Fourmis réprésenté par le No 8
    table[y_ini][x_ini] = F;

    
    for (int i = 0; i < 12; i++){
        // Nbre alèatoire de 1 a 9
        // 9 = pas de mouvement
        int nb = rand() % 9 + 1;

        //ShowTable();
        MoveAnt(nb,&x_ant,&y_ant);
        ShowTable(map,ROW_QTT,ROW_QTT);

    }
}



/*
    TODO:
    - Utiliser des arbres
    - Utiliser des listes

*/