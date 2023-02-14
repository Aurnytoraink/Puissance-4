#include "IHM.h"

// Var globale
unsigned char grille[7][6];
unsigned char winner = 0;
unsigned char current_player = 1;

// Réinitialise la grille
void reset_grille() {
    unsigned char x,y;
    for (x=0;x<7;x++) {
        for (y=0;y<6;y++) {
            grille[x][y] = 0;
        }
    }
}

//Renvoie la ligne à laquelle le pion peut tomber
//Renvoie -1 si la ligne est pleine
signed char last_pos_avaible(unsigned char colonne) {
    int i = 0;
    if (grille[colonne][i] != 0) {
        return -1;
    }
    for (i=1;i<6;i++) {
        if (grille[colonne][i] != 0) {
            break;
        }
    }
    return i;
}


void Demarre_puissance4() {
    reset_grille();
    display_grille(grille);
    
}