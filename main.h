
#include <stdbool.h>

// Définition des dimensions du tableau
#define COL_QTT 8
#define ROW_QTT 8
#define ANT_QTT 1  // Quantité maximale de fourmis, pour exister et exister dans la meme place
#define F 999  // Ca va répresenter numériquement la fourmis, on peut changer après par -1
               // le plus important est que ce soit un chiffre qui on n'arrive pas 
               // simplement avec le trace de la fourmis
#define FOOD 998
#define HOME 997


// Déclaration en globale pour l'instant
float table[ROW_QTT][COL_QTT];

struct Ant{
    // Bool has food;
    //int ant_x;
    //int ant_y;
    bool hasFood;
};

struct Food{
    int typeFood;
    int qttOfFood;
};

// Struct home?

struct Block{
    float traceGO;  // Quantité de phéromones placer en cherchant la nourriture
    float traceRETURN;  // Quantité de phéromones placer dans le retour
    struct Food food;
    struct Ant ant[ANT_QTT];  // Array pour pouvoir avoir plusieures dans le même block
    bool isHome;
};

struct Block map[ROW_QTT][COL_QTT];