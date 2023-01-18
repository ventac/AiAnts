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

// numbers in range [lower, upper].
int RamdomNb(int lower, int upper){   
    srand (time(NULL)); // Eviter que le même no de debut se repet (changement de seed)
    int num = (rand() %(upper - lower + 1)) + lower;
    return num;
}


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
    int test;
    float qttFood;

    //system("cls");  // Windows
    system("clear");  //*nix (Mac aussi?)
    printf("TraceGO:\n");
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int col = 0; col < COL_QTT; col++){            
            // S'il y a de la nourriture, afficher son icone
            if (map[ligne][col].food.qttOfFood > 0){
                printf("%s\t\t",GetFoodType(map[ligne][col].food.typeFood));            
                qttFood = map[ligne][col].food.qttOfFood;
            }else if(map[ligne][col].isHome == true){
                printf("🏠\t\t");

            }else if// Temporaire
            //for (int i = 0; i<ANT_QTT;i++)
             (ant[0].ant_x == col && ant[0].ant_y == ligne){
                printf("🐜\t\t");
             }
            
            
            
            else{
                printf("%1f\t",map[ligne][col].traceGO);
            }

            
        }
        printf("\n");
    }

    /// TEMPORAIRE
    // Afficher le map avec le trace retour
    printf("\n");
    printf("\n");
    printf("TraceRETURN:\n");
    for (int ligne = 0; ligne < ROW_QTT; ligne++){
        for (int col = 0; col < COL_QTT; col++){            
            // S'il y a de la nourriture, afficher son icone
            if (map[ligne][col].food.qttOfFood >= 1){
                printf("%s\t\t",GetFoodType(map[ligne][col].food.typeFood));            
            }else if(map[ligne][col].isHome == true){
                printf("🏠\t\t");            
            }
            /*else if// Temporaire
            //for (int i = 0; i<ANT_QTT;i++)
             (ant[0].ant_x == col && ant[0].ant_y == ligne){
                printf("🐜\t\t");
             }*/
            else{
                printf("%1f\t",map[ligne][col].traceRETURN);
               if (map[ligne][col].traceRETURN>0){
                test = 1;
               }
            }
        }
        printf("\n");
    }
    /// END TEMPORAIRE

    printf("Quantité de nourriture : %f",qttFood);



    sleep(1);  // "Buffer" Linux/Mac(?) 
    //sleep(1000);  // "Buffer" Windows
    // IMPORTANT : Sur Linux/Mac(?) c'est en secondes, sur Win c'est en milisecondes


    DryTrace();


}

// Où la fourmis va laisser son trace
/*void LeaveTrace(int x, int y){
    table[y][x] = table[y][x] - F + 1; // Efface la fourmis et ajoute la qtt
}*/

void LeaveTrace(int x, int y,bool hasFood,int steps){
    // Si elle n'a pas encore trouvée la nourriture, elle déposite
    // les phéromones de recherche, sinon, les phéromones de retour
    if (hasFood == false){
        // TODO: Pour que le moins de pas donnent le plus de points
        map[y][x].traceGO = map[y][x].traceGO + TRACE_GO_QTT;// * (50-steps);
        // Laisser la qtt de pas de la maison
        /*if (map[y][x].stepsFromFood == 0 || steps < map[y][x].stepsFromFood){
            map[y][x].stepsFromFood = steps;
        }*/
    }else{
        map[y][x].traceRETURN = map[y][x].traceRETURN + TRACE_RETURN_QTT;// * (50-steps);
        // Laisser la qtt de pas de la maison
        /*if (map[y][x].stepsFromHome == 0 || steps < map[y][x].stepsFromFood){
            map[y][x].stepsFromHome = steps;
        } */
    }    
}/// TODO: Aumentar qtt movimentos a cada passo

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
int Search(int x, int y, bool hasFood,int lastDirection){

    float biggest = 0, smallest = 0;
    float a, b, c, d, aS, bS, cS, dS;
    int direction = 0, directionS, directionB;
    int test;
        
    // Si c'est la nourriture, aller direct
    if (hasFood == false){  
        if (map[x][y-1].food.qttOfFood > 0) direction = 1; // ↑
        else if (map[x+1][y].food.qttOfFood > 0) direction = 2; // → 
        else if (map[x][y+1].food.qttOfFood > 0) direction = 3; // ↓
        else if (map[x-1][y].food.qttOfFood > 0) direction = 4; // ←
    }  // Même pour la maison
    else{
        if (map[x][y-1].isHome == true) direction = 1; // ↑
        else if (map[x+1][y].isHome == true) direction = 2; // → 
        else if (map[x][y+1].isHome == true) direction = 3; // ↓
        else if (map[x-1][y].isHome == true) direction = 4; // ←  
    }

    // DEBUG : Vérifier si il est a cote de la nourriture
    if (direction != 0){
        test = 1;
    }

    // Si l'objet cherché n'est pas juste à cote:
    if (direction == 0){

        // Définition variable map
        //Block 

        // Définition des variables pour la comparation
        // et choix du plus grand
        if (hasFood == false){   
            a = map[x][y-1].traceRETURN; // ↑
            b = map[x+1][y].traceRETURN; // → 
            c = map[x][y+1].traceRETURN; // ↓
            d = map[x-1][y].traceRETURN; // ←
            aS = map[x][y-1].stepsFromHome; // ↑
            bS = map[x+1][y].stepsFromHome; // → 
            cS = map[x][y+1].stepsFromHome; // ↓
            dS = map[x-1][y].stepsFromHome; // ←
        }
        else {
            a = map[x][y-1].traceGO; // ↑
            b = map[x+1][y].traceGO; // → 
            c = map[x][y+1].traceGO; // ↓
            d = map[x-1][y].traceGO; // ←
            aS = map[x][y-1].stepsFromFood; // ↑
            bS = map[x+1][y].stepsFromFood; // → 
            cS = map[x][y+1].stepsFromFood; // ↓
            dS = map[x-1][y].stepsFromFood; // ←
        }

      

        /*
        // Récuperer le chemin le plus court
        smallest = aS;
        directionS = 1; // ↑
        if (bS > smallest && lastDirection != 2){
            smallest = bS;
            directionS = 2; // → 
        }else if (cS > smallest && lastDirection != 3){
            smallest = cS;
            directionS = 3; // ↓
        }else if (dS > smallest && lastDirection != 4){
            smallest = dS;
            directionS = 4; // ←
        }*/

        // Éviter d'aller deux fois dans le meme block

        // Trouver la plus grand valeur
        biggest = a;
        if (lastDirection != 1) directionB = 1; // ↑
        if (b > biggest && lastDirection != 2){
            biggest = b;
            directionB = 2; // → 
        }else if (c > biggest && lastDirection != 3){
            biggest = c;
            directionB = 3; // ↓
        }else if (d > biggest && lastDirection != 4){
            biggest = d;
            directionB = 4; // ←
        }

        //if(directionS == directionB) direction = 
        


        direction = directionB;


        // Si trouve pas (si biggest reste a 0), va en random.
        if (biggest == 0) direction = RandomNb(1,4);
        // Éviter la répétition de la valeur rétournée par random.
        while (direction == lastDirection){
            direction = RamdomNb(1,4);
        }

    }


    return direction;

    //if 
    // S'il y a de la nourriture, chercher le plus grand traceGO

    // Sinon, le traceRETURN

    // Dire la direction
    //return
}

// Bouger la fourmis
void MoveAnt(struct Ant* a){    

    LeaveTrace(a->ant_x,a->ant_y,a->hasFood,a->steps);
    int direction;


    // Si hasFood == false -> random, sinon, detecter
    // Detecter le meilleur chemin, le plus récent
    // mais sans révénir en arrière
    direction = Search(a->ant_x,a->ant_y,a->hasFood,a->lastDirection);

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
        a->ant_y -= 1;
        break; 
    }

    // Enregistrer la derniere position pour éviter la répetition    
    a->lastDirection = direction;

    // Ajouter la qtt de pas
    a->steps++;

    // Eviter colisions y
    if(a->ant_y < 0){
        a->ant_y = 1;
    }else if(a->ant_y > ROW_QTT - 1){
        a->ant_y = ROW_QTT - 2;
    }
    
    // Eviter colisions x
    if(a->ant_x < 0){
        a->ant_x = 1;  // Donné une distance pour éviter qu'il reste au mûr
    }else if(a->ant_x > COL_QTT - 1){
        a->ant_x = COL_QTT - 2;
    }

    // Trouvé nourriture? Activer mode retour
    if ((a->ant_x == food.food_x) && (a->ant_y == food.food_y) && (a->hasFood == false)){
        a->hasFood = true;
        a->qttOfFood += QTT_FOOD_ANT_CAN_TAKE;
        map[a->ant_x][a->ant_y].food.qttOfFood-=QTT_FOOD_ANT_CAN_TAKE;
        a->steps = 0;  // Reset le No de pas
    // Ramenée a la maison? Activer mode recherche
    } else if ((a->ant_x == home.home_x) && (a->ant_y == home.home_y) && (a->hasFood == true)){
        a->hasFood = false;
        
        // Laisser la nourriture à la maison
        home.qttOfFood += a->qttOfFood;
        a->qttOfFood = 0;
        a->steps = 0;
    }


}

// Definir position et type aleatoire nourriture
void PlaceFood(){    
    int y_rand = RamdomNb(1,ROW_QTT-1);  // -1 pour pas dépasser la limite du tableau
    int x_rand = RamdomNb(1,COL_QTT-1);
    int typeFood = RamdomNb(1,8);  // Choisir aleatoirement le type de la nourriture    

    map[y_rand][x_rand].food.qttOfFood = 1;   
    map[y_rand][x_rand].food.typeFood = typeFood;
    food.food_x = x_rand;
    food.food_y = y_rand;
 
}

// Définir la position de la maison de manière aléatoire
void PlaceHome(){
    int y_rand = RandomNb(0,ROW_QTT-1);  // -1 pour pas dépasser la limite du tableau
    int x_rand = RandomNb(0,COL_QTT-1);
    

    map[y_rand][x_rand].isHome = true;    
    home.home_x = x_rand;
    home.home_y = y_rand;

}

void CreateAnts();

// Code principal
int main(void){

    // Remplir le map avec la structure
    FillMap();
    PlaceHome();
    PlaceFood();
    
    // Création de toutes les fourmis    
    for (int i=0;i<ANT_QTT;i++){
        ant[i].isAlive = true; 
        ant[i].hasFood = false;        
        ant[i].ant_x = home.home_x;
        ant[i].ant_y = home.home_y;        
    }

    ShowMap();
    for (int i=0;i<CYCLES;i++){
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