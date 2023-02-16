#include "IHM.h"
#include <stdio.h>

// Var globale
int grille[7][6];
int winner = -1 ;
int current_player = 0;

// Réinitialise la grille
void reset_grille()
{
    int x, y;
    for (x = 0; x < 7; x++)
    {
        for (y = 0; y < 6; y++)
        {
            grille[x][y] = -1;
        }
    }
}

// Renvoie la ligne à laquelle le pion peut tomber
// Renvoie -1 si la ligne est pleine
int last_pos_avaible(int colonne)
{
    int i = 0;
    if (grille[colonne][i] != -1)
    {
        return -1;
    }
    for (i = 1; i < 6; i++)
    {
        if (grille[colonne][i] != -1)
        {
            break;
        }
    }
    return i - 1;
}

// Renvoie 1 (vrai) si une ligne de 4 pions est détectée
int is_winning_line(int x, int y)
{
    int i, j, vec_i, vec_j;
    int pieces = 1;
    int centre;
    for (j = -1; j < 2; j++)
    {
        for (i = -1; i < 2; i++)
        {
            vec_i = i;
            vec_j = j;
            centre = (i==0 && j==0); //renvoie 1 si c'est la case pivot
            while (!centre && x+vec_i >= 0 && x+vec_i <= 6 && y+vec_j >= 0 && y+vec_j <= 5 && grille[x+vec_i][y+vec_j] == current_player)
            {
                pieces++;
                vec_i += i;
                vec_j += j;
            }
        }
    }
    return (pieces >= 4);
}

void Demarre_puissance4()
{
    reset_grille();
    int selected_column;
    int last_ligne;

    while (winner == -1)
    {
        display_grille(grille);
        selected_column = ask_user_column(current_player);
        last_ligne = last_pos_avaible(selected_column);
        if (last_ligne != -1)
        {
            grille[selected_column][last_ligne] = current_player;
            if (is_winning_line(selected_column, last_ligne) == 1)
            {
                winner = current_player;
            }
            else
            {
                current_player = !current_player; // alternance entre le J1 et J2
            }
        }

        else
        {
            no_more_space_avaible();
        }
    }

    display_grille(grille);
    display_winner(current_player);
}