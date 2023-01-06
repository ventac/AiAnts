#include <stdio.h>
#include <stdlib.h>  // Pour pouvoir effacer la console
// Fonction sleep
//#include <windows.h> // Pour Windows
#include <unistd.h>  // Pour Linux (Et mac?)
// TODO: Verifier comment détecter automatiquement le S.O.

#include "main.h"
#include <time.h>

// Définition des fonctions Ant
void DryTrace();

// TODO: La nourriture va changer de place et d'icone, pas la maison

// On peut d'abbord mettre toutes les fonctions ici et après on les catégorise et déplace
// dans des "Objets" si ça c'est possible en C, comme Obj Fourmis (move ant, AntPosition),
// Obj nourriture 
// (qtt nourriture)


// Remplir le tableau avec 0 dans tous les paramètres
// TODO : Ajouter d'autres chiffres pour répresenter der murs/chemins plus complexes
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
                printf("%1f\t",map[ligne][col].traceGO);
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

void LeaveTrace(int x, int y,bool hasFood){
    // Si elle n'a pas encore trouvée la nourriture, elle déposite
    // les phéromones de recherche, sinon, les phéromones de retour
    if (hasFood == false){
        map[y][x].traceGO = map[y][x].traceGO + 1;
    }else{
        map[y][x].traceRETURN = map[y][x].traceRETURN + 1;
    }    
}

// "Secher" ou la fourmis a passé dans chaque tour
void DryTrace(){
  for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int col = 0; col < COL_QTT; col++){
            if (map[ligne][col].isHome == false){
                if (map[ligne][col].traceGO > 0){
                map[ligne][col].traceGO -= 0.01;
                }
                if (map[ligne][col].traceRETURN > 0){
                map[ligne][col].traceRETURN -= 0.01;
                }
            }
        }
    }
}

// Régarder en haut, bas, droite et gauche pour trouver la méilieure direction où aller
int Search(int x, int y, bool hasFood){

    int biggest = 0;

    //if 
    // S'il y a de la nourriture, chercher le plus grand traceGO

    // Sinon, le traceRETURN

    // Dire la direction
    //return
}

// Bouger la fourmis
void MoveAnt(struct Ant* a){    

    LeaveTrace(a->ant_x,a->ant_y,a->hasFood);
    int direction;




    // Si hasFood == false -> random, sinon, detecter
    if (a->hasFood==false){
        direction = rand() % 4 + 1;
    }else{
        // Detecter le meilleur chemin, le plus récent
        // mais sans révénir en arrière
        direction = rand() % 4 + 1;
    }

    switch (direction)
    {
    case 1: // ↑                
        a->ant_y -= 1;  // La bouger
        break;
    case 2: // →
        a->ant_x += 1;  
        break;
    case 3: // ↓
        a->ant_y += 1;
        break;
    case 4: // ←
        a->ant_x -= 1;  
        break; 
    default:
        break;
    }

    // Eviter colisions y
    if(a->ant_y < 0){
        a->ant_y = 0;
    }else if(a->ant_y > ROW_QTT - 1){
        a->ant_y = ROW_QTT - 1;
    }
    
    // Eviter colisions x
    if(a->ant_x < 0){
        a->ant_x = 0;
    }else if(a->ant_x > COL_QTT - 1){
        a->ant_x = COL_QTT - 1;
    }

    //Trouvé nourriture? Activer mode retour
    if ((a->ant_x == food.food_x) && (a->ant_y == food.food_y)){
        a->hasFood = true;
    }

    // La bouger effectivement;
    //table[**y_ant][a->ant_x] = F;
}

// Definir position et type aleatoire nourriture
void PlaceFood(){    
    int y_rand = rand() % (ROW_QTT-1) + 1;  // -1 pour pas dépasser la limite du tableau
    int x_rand = rand() % (COL_QTT-1) + 1;
    srand (time(NULL));  // Eviter que le même no de debut se repet (changement de seed)
    int typeFood = rand() % 8 + 1;  // Choisir aleatoirement le type de la nourriture    

    map[y_rand][x_rand].food.qttOfFood = 1;   
    map[y_rand][x_rand].food.typeFood = typeFood;
    food.food_x = x_rand;
    food.food_y = y_rand;
}

// Définir la position de la maison de manière aléatoire
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
    for (int i=0;i<ANT_QTT;i++){
        ant[i].isAlive = true; 
        ant[i].hasFood = false;        
        ant[i].ant_x = home.home_x;
        ant[i].ant_y = home.home_y;        
    }

    for (int i=0;i<50;i++){
        // For chaque fourmis
        MoveAnt(&ant[0]);
        ShowMap();
    }

}



/*
    TODO:
    - Utiliser des arbres
    - Utiliser des listes

*/