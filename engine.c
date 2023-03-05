#include "IHM.h"
#include <stdio.h>

// Var globale
int grille[7][6];
int winner = -1;
int current_player = 0;
int filled_case = 0;

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

int recherche_ord(int x, int y)
{
    int pieces = 0, i = 0;
    int y_min = (y - 3 < 0) ? 0 : y - 3;
    int y_max = (y + 3 > 5) ? 5 : y + 3;
    for (i = y_min; i < (y_max + 1); i++)
    {
        if (grille[x][i] == current_player)
        {
            pieces++;
        }
        else
        {
            pieces = 0;
        }

        if (pieces >= 4)
        {
            return 1;
        }
    }
    return 0;
}

int recherche_abs(int x, int y)
{
    int pieces = 0, i = 0;
    int x_min = (x - 3 < 0) ? 0 : x - 3;
    int x_max = (x + 3 > 6) ? 6 : x + 3;
    for (i = x_min; i < (x_max + 1); i++)
    {
        if (grille[i][y] == current_player)
        {
            pieces++;
        }
        else
        {
            pieces = 0;
        }

        if (pieces >= 4)
        {
            return 1;
        }
    }
    return 0;
}

// Renvoie 1 (vrai) si une ligne de 4 pions est détectée
int is_winning_line(int x, int y)
{
    return (recherche_ord(x,y)||recherche_abs(x,y));
}

void Demarre_puissance4()
{
    reset_grille();
    int selected_column;
    int last_ligne;

    while (winner == -1 && filled_case != 42)
    {
        display_grille(grille);
        selected_column = ask_user_column(current_player);
        last_ligne = last_pos_avaible(selected_column);
        if (last_ligne != -1)
        {
            grille[selected_column][last_ligne] = current_player;
            filled_case++;
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

    if (filled_case == 42)
    {
        display_full();
    }
    else
    {
        display_winner(current_player);
    }
}