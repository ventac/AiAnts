#include <AiAnts.c>
// Random va définir la direction au début
// TODO :  Ajouter ça dans une Structure ant
// Futurement: void MoveAnt(int direction, ant ant, pris nourriture? TRUE/FALSE -> Augmente le
// score/ qtt trace)
void MoveAnt(int direction, int **x_ant, int **y_ant){    

    // TODO : Eviter contact avec le mur
    // Modifier la valeur de x et y (-1) pour éviter que ça dépasse
    // sinon, changer direction
    // sinon, rester dans default jusqu'au prochain boucle

    LeaveTrace(**x_ant,**y_ant);

    switch (direction)
    {
    case 1: // ↑                
        **y_ant -= 1;// La bouger
        break;
    case 2: // ⬈
        **y_ant -= 1;
        **x_ant += 1;  
        break;
    case 3: // →
        **x_ant += 1;  
        break;
    /*case 4: // ⬊
        **y_ant += 1;
        **x_ant += 1;  
        break;*/
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

    // La bouger effectivement;
    table[**y_ant][**x_ant] = F;
}

// Où la fourmis va laisser son trace
void LeaveTrace(int x, int y){
    table[y][x] = table[y][x] - 8 + 1; // Efface la fourmis et ajoute la qtt
}
