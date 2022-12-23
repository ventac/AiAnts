


// Définition des dimensions du tableau
#define COL_QTT 8
#define ROW_QTT 8
#define F 999  // Ca va répresenter numériquement la fourmis, on peut changer après par -1
               // le plus important est que ce soit un chiffre qui on n'arrive pas 
               // simplement avec le trace de la fourmis
#define FOOD 998
#define HOME 997

// Déclaration en globale pour l'instant
float table[ROW_QTT][COL_QTT];

struct Food{
    int typeFood;
    int qttOfFood;
};

struct Block{
    float traceGO;  // Quantité de phéromones placer en cherchant la nourriture
    float traceRETURN;  // Quantité de phéromones placer dans le retour
    struct Food food;
    char lettre;
};

struct Block map[ROW_QTT][COL_QTT];