
#include <stdbool.h>

// Définition des dimensions du tableau
#define COL_QTT 3
#define ROW_QTT 8
#define ANT_QTT 2  // Quantité maximale de fourmis, pour exister et exister dans la meme place
#define TRACE_GO_QTT 0.5
#define TRACE_RETURN_QTT 0.5
#define QTT_FOOD_ANT_CAN_TAKE 0.1
#define CYCLES 200

// Déclaration en globale pour l'instant
float table[ROW_QTT][COL_QTT];

struct Ant // 🐜
{
    int ant_x;
    int ant_y;
    bool hasFood;
    bool isAlive;
    int steps;  // Compter la quantité de pas
    int lastDirection;
    float qttOfFood;
};

struct Home
{
    int home_x;
    int home_y;
    float qttOfFood;
};

struct Food{
    int typeFood;
    float qttOfFood;
    int food_x;
    int food_y;
};

struct Block{
    float traceGO;  // Quantité de phéromones placés en cherchant la nourriture
    float traceRETURN;  // Quantité de phéromones placés dans le retour
    struct Food food;
    //struct Ant ant[ANT_QTT];  // Array pour pouvoir avoir plusieures dans le même block
    bool isHome;
    // Pour measurer la quantité de pas
    int stepsFromHome;  // Distance de la maison
    int stepsFromFood;  // Distance de la nourriture
};

// Définition objets uniques
struct Block map[ROW_QTT][COL_QTT];
struct Home home;
struct Food food;
struct Ant ant[ANT_QTT];