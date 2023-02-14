#include "IHM.h"

// Var globale
int grille[7][6];
int winner = 0;
int current_player = 0;

// Réinitialise la grille
void reset_grille() {
    int x,y;
    for (x=0;x<7;x++) {
        for (y=0;y<6;y++) {
            grille[x][y] = -1;
        }
    }
}

//Renvoie la ligne à laquelle le pion peut tomber
//Renvoie -1 si la ligne est pleine
int last_pos_avaible(int colonne) {
    int i = 0;
    if (grille[colonne][i] != -1) {
        return -1;
    }
    for (i=1;i<6;i++) {
        if (grille[colonne][i] != -1) {
            break;
        }
    }
    return i-1;
}



void Demarre_puissance4() {
    reset_grille();
    int selected_column;
    int last_ligne;

    while (winner == 0) {
        display_grille(grille);
        selected_column = ask_user_column(current_player);
        last_ligne = last_pos_avaible(selected_column);
        if (last_ligne != -1) {
            grille[selected_column][last_ligne] = current_player;
            current_player = !current_player; //alternance entre le J1 et J2
        }

        else {
            no_more_space_avaible();
        }
    }

    display_winner(current_player);
}