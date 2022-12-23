#include <stdio.h>
#include <stdlib.h>  // Pour pouvoir effacer la console
// Fonction sleep
//#include <windows.h> // Pour Windows
#include <unistd.h>  // Pour Linux (Et mac?)
// TODO: Verifier comment détecter automatiquement le S.O.

#include "main.h"

// Définition des fonctions Ant
void DryTrace();

// TODO: La nourriture va changer de place et d'icone, pas la maison

// On peut d'abbord mettre toutes les fonctions ici et après on les catégorise et déplace
// dans des "Objets" si ça c'est possible en C, comme Obj Fourmis (move ant, AntPosition),
// Obj nourriture 
// (qtt nourriture)


// Remplir le tableau avec 0 partout
// TODO : Ajouter d'autres chiffres pour répresenter der murs/chemins plus complexes
void FillTable(/*int * tableau[][]*/){
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int col = 0; col < COL_QTT; col++){
            table[ligne][col] = 0.0;
        }
    }
}

void FillMap(){
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int col = 0; col < COL_QTT; col++){
            map[ligne][col].traceGO = 0.0;
            map[ligne][col].traceRETURN = 0.0;
            map[ligne][col].food.qttOfFood = 0.0;
        }
    }
}

// Pour afficher des types differents de nourriture
const char* GetFoodType(int nbFood){
    char* food;
    switch (nbFood)
    {
    case 1:
        food = "🍣";
        break;
    case 2:
        food = "🌮";
        break;
    case 3:
        food = "🍝";
        break;
    case 4:
        food = "🍔";
        break;
    case 5:
        food = "🍕";
        break;
    case 6:
        food = "🍰";
        break;
    case 7:
        food = "🥬";
        break;
    case 8:
        food = "🥟";
        break;
    default:
        break;
    }
    
    return food;
}

// Afficher le map
void ShowMap(){
    //system("cls");  // Windows
    system("clear");  //*nix (Mac aussi?)
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int col = 0; col < COL_QTT; col++){            
            // S'il y a de la nourriture, afficher son icone
            if (map[ligne][col].food.qttOfFood >= 1){
                printf("%s\t\t",GetFoodType(map[ligne][col].food.typeFood));            
            }else if(map[ligne][col].isHome == true){
                printf("🏠\t\t");
            }else{
                printf("%f\t",map[ligne][col].traceGO);
            }
        }
        printf("\n");
    }
    sleep(1);  // "Buffer" Linux/Mac(?) 
    //sleep(1000);  // "Buffer" Windows
    // IMPORTANT : Sur Linux/Mac(?) c'est en secondes, sur Win c'est en milisecondes


    //DryTrace();


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
                printf("%f\t", table[ligne][col]);
            }            
            
        }
        printf("\n");
    }
    sleep(1);  // "Buffer" Linux/Mac(?) 
    //sleep(1000);  // "Buffer" Windows
    // IMPORTANT : Sur Linux/Mac(?) c'est en secondes, sur Win c'est en milisecondes


    DryTrace();


}


// Où la fourmis va laisser son trace
/*void LeaveTrace(int x, int y){
    table[y][x] = table[y][x] - F + 1; // Efface la fourmis et ajoute la qtt
}*/

void LeaveTrace(int x, int y){
    map[y][x].traceGO = map[y][x].traceGO + 1;
}

// "Secher" ou la fourmis a passé dans chaque tour
void DryTrace(){
  for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int col = 0; col < COL_QTT; col++){
            if ((table[ligne][col] < HOME) && (table[ligne][col] > 0)){
                table[ligne][col] = table[ligne][col] - 0.01;
            }
        }
    }
}

// Random va définir la direction au début
// TODO :  Ajouter ça dans une Structure ant
// Futurement: void MoveAnt(int direction, ant ant, pris nourriture? TRUE/FALSE -> Augmente le
// score/ qtt trace)
// Mouvement pour chercher la nouriture. Après la trouver, elle va utiliser le trace pour rétourner
/*void MoveAnt(int direction, int **x_ant, int **y_ant){    

    LeaveTrace(**x_ant,**y_ant);

    switch (direction)
    {
    case 1: // ↑                
        **y_ant -= 1;  // La bouger
        break;
    case 2: // →
        **x_ant += 1;  
        break;
    case 3: // ↓
        **y_ant += 1;
        break;
    case 4: // ←
        **x_ant -= 1;  
        break; 
    default:
        break;
    }

    // Eviter colisions y
    if(**y_ant < 0){
        **y_ant = 0;
    }else if(**y_ant > ROW_QTT - 1){
        **y_ant = ROW_QTT - 1;
    }
    
    // Eviter colisions x
    if(**x_ant < 0){
        **x_ant = 0;
    }else if(**x_ant > COL_QTT - 1){
        **x_ant = COL_QTT - 1;
    }

    // La bouger effectivement;
    table[**y_ant][**x_ant] = F;
}*/


void MoveAnt(struct Ant a){    

    LeaveTrace(a.ant_x,a.ant_y);

    int direction = rand() % 4 + 1;

    switch (direction)
    {
    case 1: // ↑                
        a.ant_y -= 1;  // La bouger
        break;
    case 2: // →
        a.ant_x += 1;  
        break;
    case 3: // ↓
        a.ant_y += 1;
        break;
    case 4: // ←
        a.ant_x -= 1;  
        break; 
    default:
        break;
    }

    // Eviter colisions y
    if(a.ant_y < 0){
        a.ant_y = 0;
    }else if(a.ant_y > ROW_QTT - 1){
        a.ant_y = ROW_QTT - 1;
    }
    
    // Eviter colisions x
    if(a.ant_x < 0){
        a.ant_x = 0;
    }else if(a.ant_x > COL_QTT - 1){
        a.ant_x = COL_QTT - 1;
    }

    // La bouger effectivement;
    //table[**y_ant][a.ant_x] = F;
}

// Definir position et type aleatoire nourriture
void PlaceFood(){    
    int y_rand = rand() % (ROW_QTT-1) + 1;  // -1 pour pas dépasser la limite du tableau
    int x_rand = rand() % (COL_QTT-1) + 1;
    srand (time(NULL));  // Eviter que le même no de debut se repet (changement de seed)
    int typeFood = rand() % 8 + 1;  // Choisir aleatoirement le type de la nourriture    

    map[y_rand][x_rand].food.qttOfFood = 1;   
    map[y_rand][x_rand].food.typeFood = typeFood;
}

void PlaceHome(){
    int y_rand = rand() % (ROW_QTT-1) + 1;  // -1 pour pas dépasser la limite du tableau
    int x_rand = rand() % (COL_QTT-1) + 1;

    map[y_rand][x_rand].isHome = true;    
    home.home_x = x_rand;
    home.home_y = y_rand;
}

void CreateAnts();

// Code principal
int main(void){

/*
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
        int nb = rand() % 4 + 1;

        // Enregistrer chaque nb dans un tableau
        // Le moins de pas le plus de pounts pour les chiffres
        // Chaque fois mieux, augmente la probabilité de répéter les pas

        ShowTable();
        MoveAnt(nb,&x_ant,&y_ant);
        ShowTable(); 
    } 
    // Retourner à la maison 
*/



    // Remplir le map avec la structure
    FillMap();
    PlaceFood();
    PlaceHome();
    ShowMap();
    // Création de toutes les fourmis
    struct Ant ant[ANT_QTT];
    for (int i=0;i<ANT_QTT;i++){
        ant[i].isAlive = true; 
        ant[i].hasFood = false;        
        ant[i].ant_x = home.home_x;
        ant[i].ant_y = home.home_y;        
    }

    
    MoveAnt(ant[0]);
    ShowMap();

}



/*
    TODO:
    - Utiliser des arbres
    - Utiliser des listes

*/