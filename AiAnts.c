#include <stdio.h>
#include <stdlib.h>  // Pour pouvoir effacer la console
// Fonction sleep
//#include <windows.h> // Pour Windows
#include <unistd.h>  // Pour Linux (Et mac?)
// TODO: Verifier comment détecter automatiquement le S.O.

#include "AiAnts.h"



// TODO: Avant de prendre la nourriture, plus probable d'aller à la droite. Après, plus probable à gauche
// TODO: La nourriture va changer de place et d'icone, pas la maison


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
}

// Afficher le tableau
void ShowTable(){
    //system("cls");  // Windows
    system("clear");  //*nix (Mac aussi?)
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int col = 0; col < COL_QTT; col++){
            if (table[ligne][col] == F){  // Afficher la fourmie où il y a la valeur de la fourmie
                printf("🐜\t");
            }else if(table[ligne][col] == FOOD){ // Nourriture 🍣 
                printf("🍣\t");
            }else if(table[ligne][col] == HOME){
                printf("🏠\t");
            }else{
                printf("%d\t", table[ligne][col]);
            }            
            
        }
        printf("\n");
    }
    sleep(1);  // "Buffer" Linux/Mac(?) 
    //sleep(1000);  // "Buffer" Windows
    // IMPORTANT : Sur Linux/Mac(?) c'est en secondes, sur Win c'est en milisecondes
}


// Où la fourmis va laisser son trace
void LeaveTrace(int x, int y){
    table[y][x] = table[y][x] - F + 1; // Efface la fourmis et ajoute la qtt
}

// "Secher" ou la fourmis a passé dans chaque tour
void DryTrace();

// Random va définir la direction au début
// TODO :  Ajouter ça dans une Structure ant
// Futurement: void MoveAnt(int direction, ant ant, pris nourriture? TRUE/FALSE -> Augmente le
// score/ qtt trace)
// Mouvement pour chercher la nouriture. Après la trouver, elle va utiliser le trace pour rétourner
void MoveAnt(int direction, int **x_ant, int **y_ant){    

    LeaveTrace(**x_ant,**y_ant);

    switch (direction)
    {
    case 1: // ↑                
        **y_ant -= 1;  // La bouger
        break;
    case 2: // ⬈
        **y_ant -= 1;
        **x_ant += 1;  
        break;
    case 3: // →
        **x_ant += 1;  
        break;
    case 4: // ⬊
        **y_ant += 1;
        **x_ant += 1;  
        break;
    case 5: // ↓
        **y_ant += 1;
        break;
    case 6: // ⬋
        **y_ant += 1;
        **x_ant -= 1; 
        break;
    case 7: // ←
        **x_ant -= 1;  
        break;
    case 8: // ⬉
        **y_ant -= 1;
        **x_ant -= 1;  
        break; 
    default:
        break;
    }

    // Eviter colisions y
    if(**y_ant < 0){
        **y_ant = 0;
    }else if(**y_ant > ROW_QTT){
        **y_ant = ROW_QTT;
    }
    
    // Eviter colisions x
    if(**x_ant < 0){
        **x_ant = 0;
    }else if(**x_ant > COL_QTT){
        **x_ant = COL_QTT;
    }

    // La bouger effectivement;
    table[**y_ant][**x_ant] = F;
}


// Code principal
int main(void){


    FillTable();
    ShowTable();
    
    // Pour tester, la position initielle sera le coin inférieur gauche (8,0)
    // et l'objectif sera le coin supérieur droite (0,8)


    // Position initielle fourmis: base gauche tableau |_
    int y_ini = ROW_QTT - 1, // -1 parce que la taille totale est de 8 et ça commence par 0
        x_ini = 0;
    
    int* y_ant = &y_ini,
       * x_ant = &x_ini;

    // Position initielle nourriture
    table[0][COL_QTT] = FOOD;

    // Position initielle maison
    table[y_ini][x_ini] = HOME;

    // Placer la fourmie
    table[y_ini][x_ini] = F;

    // Chercher
    // While foundFood == false
    // int steps = 0;
    // steps++;  // Compter la quantité de pas pour trouver le chemin le plus court et donner le bonus

    for (int i = 0; i < 50; i++){
        // Nbre alèatoire de 1 a 9
        // 9 = pas de mouvement
        int nb = rand() % 9 + 1;

        // Enregistrer chaque nb dans un tableau
        // Le moins de pas le plus de pounts pour les chiffres
        // Chaque fois mieux, augmente la probabilité de répéter les pas

        ShowTable();
        MoveAnt(nb,&x_ant,&y_ant);
        ShowTable(); 
    } 
    // Retourner à la maison 







}



/*
    TODO:
    - Utiliser des arbres
    - Utiliser des listes

*/